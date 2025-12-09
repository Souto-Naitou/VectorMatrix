#pragma once
#include <cstdint>
#include <string>

#include <Vector4.h>
#include <Vector3.h>

#undef RGB
#undef RGBA

class IColor
{
public:
    virtual ~IColor() = default;
};

class RGBA;
class HSV;

class RGB : public IColor
{
public:
    RGB() = default;
    RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
    RGB(const RGB& other) : r(other.r), g(other.g), b(other.b) {}
    RGB(RGB&& other) noexcept : r(other.r), g(other.g), b(other.b) {}

    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;

    RGB& operator=(const RGB& other) { this->r = other.r; this->g = other.g; this->b = other.b; return *this; }
    RGB& operator=(RGB&& other) noexcept { this->r = other.r; this->g = other.g; this->b = other.b; return *this; }

    RGB& operator=(const Vector3& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        return *this;
    }

    RGB& operator=(Vector3&& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        return *this;
    }

    RGB& operator=(const Vector4& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        return *this;
    }

    RGB& operator=(Vector4&& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        return *this;
    }

    ~RGB() = default;

    RGBA to_RGBA(uint8_t a = 255) const;
    Vector4 to_Vector4(uint8_t a) const { return Vector4(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, a / 255.0f); }
    Vector4 to_Vector4(float a) const { return Vector4(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, a); }
    Vector3 to_Vector3() const { return Vector3(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f); }
};

class RGBA : public IColor
{
public:
    RGBA() = default;

    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;
    uint8_t a = 255;

    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
    RGBA(const RGBA& other) : r(other.r), g(other.g), b(other.b), a(other.a) {}
    RGBA(uint32_t rgba) : r((rgba >> 24) & 0xFF), g((rgba >> 16) & 0xFF), b((rgba >> 8) & 0xFF), a(rgba & 0xFF) {}
    RGBA(RGBA&& other) noexcept : r(other.r), g(other.g), b(other.b), a(other.a) {}
    RGBA(const Vector4& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        this->a = static_cast<uint8_t>(other.w * 255);
    }

    RGBA& operator=(const RGBA& other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        this->a = other.a;
        return *this;
    }

    RGBA& operator=(RGBA&& other) noexcept
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        this->a = other.a;
        return *this;
    }

    RGBA& operator=(const Vector4& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        this->a = static_cast<uint8_t>(other.w * 255);
        return *this;
    }

    RGBA& operator=(Vector4&& other)
    {
        this->r = static_cast<uint8_t>(other.x * 255);
        this->g = static_cast<uint8_t>(other.y * 255);
        this->b = static_cast<uint8_t>(other.z * 255);
        this->a = static_cast<uint8_t>(other.w * 255);
        return *this;
    }

    RGB rgb() const { return RGB(this->r, this->g, this->b); }

    Vector4 to_Vector4() const { return Vector4(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, this->a / 255.0f); }
    Vector3 to_Vector3() const { return Vector3(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f); }

    HSV to_HSV() const;
};

class HSV : public IColor
{
public:

    HSV() = default;
    HSV(float h, float s, float v) : h_(h), s_(s), v_(v) {}
    HSV(const HSV& other) : h_(other.h_), s_(other.s_), v_(other.v_) {}
    HSV(HSV&& other) noexcept : h_(other.h_), s_(other.s_), v_(other.v_) {}

    float& h() { return h_; }
    float& s() { return s_; }
    float& v() { return v_; }

    const float& h() const { return h_; }
    const float& s() const { return s_; }
    const float& v() const { return v_; }

    RGB to_RGB() const;

private:
    float h_ = 0.0f; // Hue [0, 360)
    float s_ = 1.0f; // Saturation [0, 1]
    float v_ = 1.0f; // Value [0, 1]
};

namespace color
{
    RGBA create(const std::string& colorstr);
    RGBA HexToRGBA(const std::string& hexstr);
    RGBA RGBToRGBA(const std::string& rgbstr);
    RGBA RGBAToRGBA(const std::string& rgbastr);
}