#include "render/model/Texture.hpp"
#include "tools/Resources.hpp"

Texture::Texture(std::string fileName){

  Resources::ImageData data = Resources::LoadImageData(fileName);

  width = data.width;
  height = data.height;
  bpp = data.bpp;

	glGenTextures(1, &id);	
	glBindTexture(GL_TEXTURE_2D, id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.buffer);
  glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture(){
  glDeleteTextures(1, &id);
}

void Texture::Bind(unsigned int slot){
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::Unbind(){
  glBindTexture(GL_TEXTURE_2D, 0);
}
