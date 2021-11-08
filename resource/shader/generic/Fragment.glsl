#version 330 core

in vec3 normal;
in vec4 color;
in vec2 texCoord;
in vec3 lightDirection;
in vec3 cameraPosition;

uniform sampler2D texture0;

out vec4 out_color;

vec4 processDirLights(vec4 color){

    vec4 lightAmbient = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 lightDiffuse = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);

	vec4 ambient = vec4(0.6941, 0.3451, 0.1059, 1.0) * 0.2 * lightAmbient;

    float diffuseIntensity = max(dot(normal, lightDirection), 0.0);
    vec4 diffuse = color * diffuseIntensity * lightDiffuse;

    float shininess = 300;
    vec3 h = normalize(lightDirection + cameraPosition);
    float specularIntensity = max(dot(normal, h), 0.0);
    vec4 specular = vec4(0.3500, 0.3500, 0.3500, 1.0) * lightSpecular * pow(specularIntensity, shininess);

	return ambient + diffuse + specular;
}


void main()
{
    vec4 lightComponent = processDirLights(color);
    vec4 textureComponent = texture(texture0, texCoord);
    gl_FragColor = textureComponent * lightComponent;
};



