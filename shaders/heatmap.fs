#version 330

in vec2 fragTexCoord;
out vec4 fragColor;

uniform sampler2D texture0;
uniform vec2 resolution;
uniform vec2 positions[1000]; // Adjust size as needed
uniform float densities[1000]; // Adjust size as needed
uniform int particleCount;

void main()
{
    vec2 uv = fragTexCoord * resolution;
    vec4 color = vec4(0.0, 0.0, 0.0, 0.0);

    for (int i = 0; i < particleCount; i++)
    {
        float dist = length(uv - positions[i]);
        float intensity = densities[i] / (dist * dist + 1.0);
        color += vec4(0.0, 0.0, 1.0, intensity);
    }

    fragColor = color;
}