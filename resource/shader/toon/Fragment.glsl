#version 330

in vec2 texCoord;
in vec4 color;
in vec3 normal;

out vec4 out_color;

void main()
{
  float fraction = 1.0;
  float intensity;
  vec4 capColor;
  intensity = max(0.0, dot(vec3(0.0, 10.0, -5.0), normal));

  if (intensity > pow(0.95, fraction)) {
    capColor = vec4(vec3(0.9), 0.9);
  } else if (intensity > pow(0.5, fraction)) {
    capColor = vec4(vec3(0.6), 1.0);
  } else if (intensity > pow(0.25, fraction)) {
    capColor = vec4(vec3(0.4), 1.0);
  } else {
    capColor = vec4(vec3(0.2), 1.0);
  }

  gl_FragColor = capColor * color;
};