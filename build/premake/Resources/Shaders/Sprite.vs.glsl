#version 430

in vec3 position;
in mat4 modelMatrix;

out vec3 Position;
out vec2 Texcoord;

uniform mat4 vp;

void main ()
{
  gl_Position = modelMatrix * vec4 (position, 1.0);

  Position = position;
}