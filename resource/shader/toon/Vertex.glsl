#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec4 in_diffuse;
layout (location = 2) in vec3 in_normal;
layout (location = 3) in vec2 in_texCoord;

uniform mat4 in_transform;
uniform vec3 in_lightDirection;
uniform vec3 in_cameraPosition;

out vec3 normal;
out vec4 color;
out vec2 texCoord;
out vec3 lightDirection;
out vec3 cameraPosition;

void main(){
    gl_Position = in_transform * vec4(0.1 * in_position, 1.0);
    normal = in_normal;
    texCoord = in_texCoord;

    color = in_diffuse;

    lightDirection = in_lightDirection;
    cameraPosition = in_cameraPosition;
};