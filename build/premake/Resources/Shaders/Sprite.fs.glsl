#version 430

in vec3 Position;
in vec4 Color;
in vec2 Texcoord;

uniform sampler2D image;
uniform vec4 overrideColor;

out vec4 outColor;

void main ()
{
  outColor = texture (image, Texcoord) * overrideColor;
}