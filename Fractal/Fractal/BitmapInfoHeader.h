//
//  BitmapInfoHeader.h
//  Fractal
//
//  Created by Daniel Marchena Parreira on 2018-08-12.
//  Copyright © 2018 Daniel Marchena Parreira. All rights reserved.
//

#ifndef BitmapInfoHeader_h
#define BitmapInfoHeader_h

#include <cstdint>

using namespace std;

#pragma pack(push, 2)

namespace fractal {
    
    struct BitmapInfoHeader {
        int32_t headerSize{40};
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitsPerPixel{24};
        int32_t compression{0};
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };
}

#pragma pack(pop)

#endif /* BitmapInfoHeader_h */
