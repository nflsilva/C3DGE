#version 330

in vec3 position;

void main()
{
    gl_Position = vec4(0.25 * position, 1.0);
};