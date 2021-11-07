#version 330

in vec4 color;
in vec2 texCoord;

uniform sampler2D texture0;

out vec4 out_color;

void main()
{
    gl_FragColor = color;
};