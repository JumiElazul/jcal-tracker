#pragma once

struct Vec2
{
    union { float r{}; float x; };
    union { float g{}; float y; };
};

struct Vec3
{
    union { float r{}; float x; };
    union { float g{}; float y; };
    union { float b{}; float z; };
};
