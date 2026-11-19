#version 330 core
out vec4 FragColor;

in vec2 outTexCords;

uniform sampler2D t0;
uniform vec4 u_Color;

void main()
{
    vec4 texColor = texture(t0, outTexCords);

    if(u_Color.a == 0.0){
        FragColor = texColor;
    }
    else{
        FragColor = mix(texColor, u_Color, 0.5);
    }
    //FragColor = u_Color;
}