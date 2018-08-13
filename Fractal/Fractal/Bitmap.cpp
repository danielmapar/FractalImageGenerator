//
//  Bitmap.cpp
//  Fractal
//
//  Created by Daniel Marchena Parreira on 2018-08-12.
//  Copyright © 2018 Daniel Marchena Parreira. All rights reserved.
//

#include <fstream>
#include "Bitmap.hpp"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace fractal;
using namespace std;

namespace fractal {
    // 3 -> RGB
    Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixel(new uint8_t[width * height * 3]{/*initialize with 0s*/}) {
        
    };
    
    bool Bitmap::write(string filename) {
        
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;
        
        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
        
        infoHeader.width = m_width;
        infoHeader.height = m_height;
        
        ofstream file;
        
        file.open(filename, ios::out | ios::binary);
        
        if (!file) {
            return false;
        }
        
        file.write((char *) &fileHeader, sizeof(fileHeader));
        file.write((char *) &infoHeader, sizeof(infoHeader));
        file.write((char *) m_pPixel.get(), m_width * m_height * 3);
        
        file.close();
        
        if (!file) {
            return false;
        }
        
        return true;
    };
    
    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        uint8_t * pPixel = m_pPixel.get();
        pPixel += ((y * 3) * m_width) + (x * 3); // each pixel is 3 bytes
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    
    }
    
    Bitmap::~Bitmap() {
        
    };
}
