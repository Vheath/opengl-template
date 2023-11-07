#version 330 core
out vec4 FragColor;


//in vec3 ourColor;

uniform mediump vec3 uniColor;
//uniform sampler2D texture1;
void main()
{
	// linearly interpolate between both textures
	//FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), mixValue);
    //FragColor = texture(texture1, TexCoord); 
    FragColor = vec4(uniColor ,1.0f); 
    
}
