#version 330

in vec4 color;
in vec2 texCoord;

uniform sampler2D texture0;

out vec4 out_color;

void main()
{
    out_color = (color * 0.25) + (texture(texture0, texCoord) * 0.75);
};