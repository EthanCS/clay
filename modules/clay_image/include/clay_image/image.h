#pragma once

#include <clay_core/blob.h>
#include <memory>

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

struct IImage : public clay::core::IBlob {
    virtual u32 get_width() const noexcept    = 0;
    virtual u32 get_height() const noexcept   = 0;
    virtual u32 get_channels() const noexcept = 0;
};

std::shared_ptr<IImage> load_image(const char* path, ImageChannel::Enum channel);

struct STB_Image : IImage {
private:
    u32 width    = 0;
    u32 height   = 0;
    u32 channels = 0;
    u8* data     = nullptr;

public:
    STB_Image(u32 _width, u32 _height, u32 _channel, u8* _data) noexcept;
    virtual ~STB_Image() noexcept override;

    ////// Begin IBlob
    u8* get_data() const noexcept override { return data; }
    u64 get_size() const noexcept override { return width * height * channels; }
    ////// End IBlob

    ////// Begin IImage
    u32 get_width() const noexcept override { return width; }
    u32 get_height() const noexcept override { return height; }
    u32 get_channels() const noexcept override { return channels; }
    ////// End IImage
};

} // namespace image
} // namespace clay