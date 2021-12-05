#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec3 in_normal;

uniform mat4 in_transform;
uniform vec3 in_lightDirection;
uniform vec3 in_cameraPosition;
uniform float in_waterPhase;

out vec3 normal;
out vec4 color;
out vec3 lightDirection;
out vec3 cameraPosition;

void main(){
    gl_Position = in_transform * vec4(in_position.x, in_position.y + (sin(in_waterPhase) / 2), in_position.z , 1.0);
    normal = in_normal;
    color = in_color;
    lightDirection = in_lightDirection;
    cameraPosition = in_cameraPosition;
};