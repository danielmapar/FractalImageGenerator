//
//  BitmapFileHeader.h
//  Fractal
//
//  Created by Daniel Marchena Parreira on 2018-08-12.
//  Copyright © 2018 Daniel Marchena Parreira. All rights reserved.
//

#ifndef BitmapFileHeader_h
#define BitmapFileHeader_h

// C standard int (to guarantee a 32 int)
#include <cstdint>

// We need to pack the data with our own padding
// Otherwise, the struct will include some C++ standard padding
// Align all of this of 2 bytes boundaries (no hidden padding)
#pragma pack(push, 2)

namespace fractal {
    // Differences between struct and class
    // All properties inside a struct are public
    struct BitmapFileHeader {
        char header[2]{ 'B', 'M' };
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset; // how long into the size the data actually begins
    };
}

#pragma pack(pop)

#endif /* BitmapFileHeader_h */
