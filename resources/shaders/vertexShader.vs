#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCords;

uniform vec2 u_Offset;
out vec2 outTexCords;

void main()
{
    gl_Position = vec4(aPos.x + u_Offset.x, aPos.y + u_Offset.y, aPos.z, 1.0);
    outTexCords = aTexCords;
}