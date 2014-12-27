#version 430

in vec3 position;
in mat4 modelMatrix;
in vec4 color;
in vec2 texcoord;

out vec3 Position;
out vec4 Color;
out vec2 Texcoord;

uniform mat4 vp;

void main ()
{
  gl_Position = modelMatrix * vec4 (position, 1.0);

  Position = position;
  Color = color;
  Texcoord = texcoord;
}