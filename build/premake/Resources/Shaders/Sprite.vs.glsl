#version 430

in vec3 position;
in vec2 texcoord;

out vec3 Position;
out vec2 Texcoord;

uniform mat4 mvp;
uniform vec4 overrideColor;

void main ()
{
  gl_Position = vec4 (position, 1.0);

  Position = position;
  Texcoord = texcoord;
}