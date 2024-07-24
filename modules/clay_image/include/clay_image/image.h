#pragma once

#include <clay_core/blob.h>

namespace clay
{
namespace image
{

struct Image : clay::core::IBlob {
    u32 width    = 0;
    u32 height   = 0;
    u32 channels = 0;

    ~Image() noexcept override;
};

Image load_image(const char* path);

} // namespace image
} // namespace clay