//
//  Bitmap.hpp
//  Fractal
//
//  Created by Daniel Marchena Parreira on 2018-08-12.
//  Copyright © 2018 Daniel Marchena Parreira. All rights reserved.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <string>
#include <cstdint>

using namespace std;

namespace fractal {
    
    class Bitmap {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixel{nullptr};
    public:
        Bitmap(int width, int height);
        bool write(string filename);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        virtual ~Bitmap();
    };
    
}

#endif /* Bitmap_hpp */
