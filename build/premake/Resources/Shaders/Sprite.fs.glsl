#version 430

in vec3 Position;
in vec2 Texcoord;

uniform sampler2D image;
uniform vec4 overrideColor;

out vec4 outColor;

void main ()
{
  outColor = overrideColor;
}