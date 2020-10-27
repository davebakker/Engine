#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textureCoordinations;

out vec2 v_TexCoord;

void main()
{
	gl_Position = position;
	v_TexCoord = textureCoordinations;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 uniformColor;
uniform sampler2D uniformTexture;

void main()
{
	vec4 textureColor = texture(uniformTexture, v_TexCoord);
	color = textureColor;
}