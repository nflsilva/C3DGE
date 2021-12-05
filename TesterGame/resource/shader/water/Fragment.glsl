#version 330 core

in vec3 normal;
in vec4 color;
in vec3 lightDirection;
in vec3 cameraPosition;

out vec4 out_color;

vec4 processDirLights(vec4 color){

    vec4 lightAmbient = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 lightDiffuse = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);

	vec4 ambient = color * 0.2 * lightAmbient;

    vec4 diffuse = color * lightDiffuse;
    float diffuseIntensity = max(dot(normal, lightDirection), 0.0);
    if(diffuseIntensity >= 0.7)
       diffuse *= vec4(0.7, 0.7, 0.7, 1.0); 
    if(diffuseIntensity >= 0.5)
        diffuse *= vec4(0.5, 0.5, 0.5, 1.0); 
    if(diffuseIntensity >= 0.3)
        diffuse *= vec4(0.3, 0.3, 0.3, 1.0); 

	return ambient + diffuse;
}


void main()
{
    vec4 lightComponent = processDirLights(color);
    gl_FragColor = lightComponent;
};



