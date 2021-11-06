#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string.h>

#include "render/Vec4DTO.hpp"
#include "tools/Log.hpp"

#include "stb_image/stb_image.h"

class Resources {
  public:
    class MeshData {
      public:
        std::vector<float> vertices;
        std::vector<float> textureCoordinates;
        std::vector<float> colors;
        std::vector<float> normals;
        std::vector<int> indices;
        MeshData(){};
    };
    class ImageData {
      public:
        int width, height, bpp;
        stbi_uc* buffer;
        ImageData() : width(0), height(0), bpp(0), buffer(NULL){};
        ~ImageData(){  if(buffer) stbi_image_free(buffer); };
    };

    static std::string LoadShaderSource(std::string fileName){
      std::ifstream file;
      file.open("./resource/shader/" + fileName, std::ios::in);
      if(!file)
      {
        Log::E("Error opening shader file " + fileName);
        return NULL;
      }
      std::string content(
        (std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));
      file.close();
      return content;
    }

    static MeshData LoadMeshData(std::string fileName){

      MeshData md;
      std::ifstream file;
      file.open("./resource/mesh/" + fileName, std::ios::in);
  
      if (!file.is_open()) 
      { 
        Log::E("Cannot open file " + fileName);
        return md;
      }

      std::string line;
      std::vector<Vec4DTO> textureCoordinates;
      std::vector<Vec4DTO> normals;

      auto processFBlock = [](std::string block) {
        std::vector<unsigned int> r;
        size_t slash1Index = block.find("/");
        size_t slash2Index = block.find("/", slash1Index + 1);

        r.push_back(std::stod(block.substr(0, slash1Index))); 
        if(slash2Index < block.size()) {
          r.push_back(std::stod(block.substr(slash1Index + 1, slash2Index))); 
          r.push_back(std::stod(block.substr(slash2Index + 1, block.size()))); 
        }
        return r;
      };

      while (std::getline(file, line)) 
      {
          std::istringstream in(line);
          std::vector<std::string> lineTokens;
          std::string line_s;
          while (in >> line_s)
            lineTokens.push_back(line_s);

          if(lineTokens.size() == 0)
            continue;
          
          if (lineTokens[0]=="v")
          {
              md.vertices.push_back(std::stod(lineTokens[1]));
              md.vertices.push_back(std::stod(lineTokens[2]));
              md.vertices.push_back(std::stod(lineTokens[3])); 

              /*
              if (lineTokens.size()==7)
              {
                  double c1 = std::stod(lineTokens[4]);
                  double c2 = std::stod(lineTokens[5]);
                  double c3 = std::stod(lineTokens[6]);
                  vert_color.push_back(double_line_color);
              }*/
          }
          else if (lineTokens[0]=="vt")
          {
              double vt0 = std::stod(lineTokens[1]);
              double vt1 = std::stod(lineTokens[2]); 
              textureCoordinates.push_back(Vec4DTO(vt0, vt1));
          }
          else if (lineTokens[0]=="vn"){
              double vnx = std::stod(lineTokens[1]);
              double vny = std::stod(lineTokens[2]);
              double vnz = std::stod(lineTokens[3]);
              normals.push_back(Vec4DTO(vnx, vny, vnz));
          }
          else if (lineTokens[0]=="f")
          {
              for(int block = 1; block < (int)lineTokens.size(); block++){

                auto blockValues = processFBlock(lineTokens[block]);

                // Vertex index
                unsigned int vertexIndex = blockValues[0];
                md.indices.push_back(vertexIndex - 1); 
                md.colors.push_back(0.5);
                md.colors.push_back(0.7);
                md.colors.push_back(0.5);
                md.colors.push_back(1.0);

                // Texture coordinate index
                if(blockValues.size() > 1){
                  Vec4DTO vtc = textureCoordinates[blockValues[1] - 1];
                  md.textureCoordinates.push_back(vtc.v0);
                  md.textureCoordinates.push_back(vtc.v1);
                }
                // Normal index
                if(blockValues.size() > 2){
                  Vec4DTO vn = normals[blockValues[2] - 1];
                  md.normals.push_back(vn.v0);
                  md.normals.push_back(vn.v1);
                  md.normals.push_back(vn.v2);
                }

              }
          }
      
      }
      
      file.close();

      return md;
    }

    static ImageData LoadImageData(std::string fileName){
      ImageData data;
      stbi_set_flip_vertically_on_load(1);
      data.buffer = stbi_load(("./resource/texture/" + fileName).c_str(), &data.width, &data.height, &data.bpp, 4);
      return data;
    }

};

#endif