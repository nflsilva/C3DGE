#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string.h>

#include "render/Vertex.hpp"
#include "tools/Log.hpp"

class Resources {

  public:
    class MeshData {
      public:
        std::vector<Vertex> vertices;
        std::vector<int> indices;
        MeshData(){};
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
              double v0 = std::stod(lineTokens[1]);
              double v1 = std::stod(lineTokens[2]);
              double v2 = std::stod(lineTokens[3]); 
              md.vertices.push_back(Vertex(v0, v1, v2));;
          
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
              //double vt0 = std::stod(lineTokens[1]);
              //double vt1 = std::stod(lineTokens[2]);
              ///tex_coords.push_back(double_line);
          }
          else if (lineTokens[0]=="f")
          {
              size_t idx1 = lineTokens[1].find("/");
              unsigned int faceVertex0 = std::stod(lineTokens[1].substr(0, idx1)); 
              //size_t idx2 = lineTokens[1].find("/", idx1 + 1);
              //unsigned int faceTexture0 = std::stod(lineTokens[1].substr(idx1 + 1, idx2));

              size_t idx3 = lineTokens[2].find("/");
              unsigned int faceVertex1 = std::stod(lineTokens[2].substr(0, idx3)); 
              //size_t idx4 = lineTokens[2].find("/", idx3 + 1);
              //unsigned int v_idx_ftc_2 = std::stod(lineTokens[2].substr(idx3 + 1, idx4));

              size_t idx5 = lineTokens[3].find("/");
              unsigned int faceVertex2 = std::stod(lineTokens[3].substr(0, idx5)); 
              //size_t idx6 = lineTokens[3].find("/", idx5 + 1);
              //unsigned int v_idx_ftc_3 = std::stod(lineTokens[3].substr(idx5 + 1, idx6));

              md.indices.push_back(faceVertex0 - 1);
              md.indices.push_back(faceVertex1 - 1);
              md.indices.push_back(faceVertex2 - 1);

              /*
              unint_line_tc.push_back(v_idx_ftc_1);
              unint_line_tc.push_back(v_idx_ftc_2);
              unint_line_tc.push_back(v_idx_ftc_3);
              faces_tc.push_back(unint_line_tc);
              */
          }
      
      }
      
      file.close();

      return md;
    }

};

#endif