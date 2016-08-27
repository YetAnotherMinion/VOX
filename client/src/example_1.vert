#version 130
 
in vec2 position;
out vec2 my_attr;

uniform mat4 matrix;

void main() {
    my_attr = position;
    gl_Position = matrix * vec4(position, 0.0, 1.0);
}
