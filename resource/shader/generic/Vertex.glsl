#version 330

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_texCoord;
layout (location = 2) in vec4 in_color;
layout (location = 3) in vec3 in_normal;

uniform mat4 in_transform;

out vec4 color;
out vec2 texCoord;

void main(){
    gl_Position = in_transform * vec4(in_position, 1.0);
    color = vec4(clamp(in_position, 0.0, 1.0), 1.0);
    texCoord = in_texCoord;
};