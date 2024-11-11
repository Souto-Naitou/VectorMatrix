#include <iostream>

#include <Vector2.h>
#include <Vector3.h>
#include <Vector4.h>
#include "Color.h"

int main()
{
    Color color = Vector4();

    color = 0xffffffff;
    color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
    color.rgba = { 255u, 255u, 255u, 255u };

    unsigned int ucol = color.UInt32();
    printf("0x%08x\n", ucol);

    Color::RGBA rgba = color.rgba;
    printf("%d, %d, %d, %d\n", rgba.r, rgba.g, rgba.b, rgba.a);

    Vector4 vec4 = color.Vec4();
    printf("%f, %f, %f, %f\n", vec4.x, vec4.y, vec4.z, vec4.w);

    return 0;
}
