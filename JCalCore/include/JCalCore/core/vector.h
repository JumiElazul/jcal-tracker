#pragma once

struct Vec2
{
    union { float r{}; float x; };
    union { float g{}; float y; };

    Vec2() : x(), y() { }
    Vec2(float x_, float y_) : x(x_), y(y_) { }
};

struct Vec3
{
    union { float r{}; float x; };
    union { float g{}; float y; };
    union { float b{}; float z; };

    Vec3() : x(), y(), z() { }
    Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) { }
};
