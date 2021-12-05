#version 330 core

in vec3 in_position;
in vec2 in_texCoord;
in vec3 in_normal;

uniform mat4 in_modelMatrix;
uniform mat4 in_viewMatrix;
uniform mat4 in_projectionMatrix;

uniform vec3 in_lightDirection;

out vec2 texCoord;
out vec3 normal;
out vec3 lightVector;

void main(){

    vec4 worldPosition = in_modelMatrix * vec4(in_position, 1.0);
    gl_Position = in_projectionMatrix * in_viewMatrix * worldPosition;
    texCoord = in_texCoord;

    normal = normalize((in_modelMatrix * vec4(in_normal, 0.0)).xyz);
    lightVector = normalize(in_lightDirection);
};