#version 330

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_texCoord;
layout (location = 2) in vec4 in_color;
layout (location = 3) in vec3 in_normal;

uniform mat4 in_transform;

out vec2 texCoord;
out vec4 color;
out vec4 normal;

void main(){
    gl_Position = in_transform * vec4(in_position, 1.0);
    texCoord = in_texCoord;
    color = in_color;
    vec4 nn =  normalize(in_transform * vec4(in_normal, 1.0));
    normal = vec3(nn.x, nn.y, nn.z);
};