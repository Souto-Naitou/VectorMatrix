#include <iostream>

#include <Vector2.h>
#include <Vector3.h>

int main()
{
    Vector3 a1 = {1.0f, 1.0f, 1.0f};
    Vector2 a2 = {2.0f, 2.0f};
    Vector2 a3 = {3.0f, 3.0f};

    Vector3 result;
    result = a1;
    result = a2;
    a3 = result.xy();

    return 0;
}
