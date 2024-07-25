#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <clay_image/image.h>

inline int to_stbi_req_comp(clay::image::ImageChannel::Enum channel)
{
    switch (channel)
    {
        case clay::image::ImageChannel::Grey:
            return STBI_grey;
        case clay::image::ImageChannel::GreyAlpha:
            return STBI_grey_alpha;
        case clay::image::ImageChannel::RGB:
            return STBI_rgb;
        case clay::image::ImageChannel::RGBAlpha:
            return STBI_rgb_alpha;
    }
    return STBI_default;
}

namespace clay
{
namespace image
{

Image::Image(u32 _width, u32 _height, u32 _channel, u8* _data) noexcept
    : width(_width)
    , height(_height)
    , channels(_channel)
    , data(_data)
{
}

Image::~Image() noexcept
{
    if (data) { stbi_image_free(data); }
}

// Image load_image(const char* path, ImageChannel::Enum channel)
// {
//     int width, height, channels;
//     u8* data = stbi_load(path, &width, &height, &channels, to_stbi_req_comp(channel));
//     if (data)
//     {
//         return Image(width, height, channels, data);
//     }

//     return image;
// }

} // namespace image
} // namespace clay