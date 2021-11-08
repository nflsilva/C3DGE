#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <set>
#include <list>
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
#include "tiny_obj_loader/tiny_obj_loader.h"

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

      tinyobj::ObjReaderConfig reader_config;
      reader_config.mtl_search_path = "./resource/material/";
      tinyobj::ObjReader reader;

      if (!reader.ParseFromFile("./resource/mesh/" + fileName, reader_config)) {
        if (!reader.Error().empty()) {
            Log::E("TinyObjReader: " + reader.Error());
        }
      }

      if (!reader.Warning().empty()) {
        Log::I("TinyObjReader: " + reader.Warning());
      }

      tinyobj::attrib_t attrib = reader.GetAttrib();
      std::vector<tinyobj::shape_t> shapes = reader.GetShapes();
      std::vector<tinyobj::material_t> materials = reader.GetMaterials();

      Log::D(
        std::to_string(attrib.vertices.size()) + " vertices. " 
      + std::to_string(attrib.colors.size()) + " colors. " 
      + std::to_string(attrib.normals.size()) + " normals. "
      );

      int i = 0;
      for (size_t s = 0; s < shapes.size(); s++) {

        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {

          size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);
          for (size_t v = 0; v < fv; v++) {

            tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

            md.vertices.push_back(attrib.vertices[3 * idx.vertex_index + 0]);
            md.vertices.push_back(attrib.vertices[3 * idx.vertex_index + 1]);
            md.vertices.push_back(attrib.vertices[3 * idx.vertex_index + 2]);            

            if(materials.size() > 0){
              tinyobj::material_t material = materials[shapes[s].mesh.material_ids[f]];
              md.colors.push_back(material.diffuse[0]);
              md.colors.push_back(material.diffuse[1]);
              md.colors.push_back(material.diffuse[2]);
              md.colors.push_back(1.0);
            }

            if (idx.normal_index >= 0) {
              md.normals.push_back(attrib.normals[3 * idx.normal_index + 0]);
              md.normals.push_back(attrib.normals[3 * idx.normal_index + 1]);
              md.normals.push_back(attrib.normals[3 * idx.normal_index + 2]);
            }
            
            if (idx.texcoord_index >= 0) {
              md.textureCoordinates.push_back(attrib.texcoords[2 * idx.texcoord_index + 0]);
              md.textureCoordinates.push_back(attrib.texcoords[2 * idx.texcoord_index + 1]);
            }
            
            md.indices.push_back(i++);
          }
          index_offset += fv;

        }
      }

      Log::D(
        std::to_string(md.vertices.size() / 4) + " vertices. " 
      + std::to_string(md.colors.size() / 4) + " colors. " 
      + std::to_string(md.normals.size() / 3) + " normals. "
      );

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