#pragma once

#include <clay_core/blob.h>

namespace clay
{
namespace image
{

struct ImageChannel {
    enum Enum
    {
        Grey,
        GreyAlpha,
        RGB,
        RGBAlpha
    };
};

struct Image : clay::core::IBlob {

private:
    u32 width    = 0;
    u32 height   = 0;
    u32 channels = 0;
    u8* data     = nullptr;

public:
    Image(u32 _width, u32 _height, u32 _channel, u8* _data) noexcept;
    ~Image() noexcept override;

    ////// Begin IBlob
    u8* get_data() const noexcept override { return data; }
    u64 get_size() const noexcept override { return width * height * channels; }
    ////// End IBlob

    u32 get_width() const noexcept { return width; }
    u32 get_height() const noexcept { return height; }
    u32 get_channels() const noexcept { return channels; }
};

// Image load_image(const char* path, ImageChannel::Enum channel);

} // namespace image
} // namespace clay