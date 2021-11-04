#version 330

layout (location = 0) in vec3 position;
uniform mat4 tranform;

out vec4 color;

void main(){
    color = vec4(clamp(position, 0.0, 1.0), 1.0);
    gl_Position = tranform * vec4(0.15 * position, 1.0);
};