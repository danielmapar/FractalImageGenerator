//
//  main.cpp
//  Fractal
//
//  Created by Daniel Marchena Parreira on 2018-08-12.
//  Copyright © 2018 Daniel Marchena Parreira. All rights reserved.
//

#include <iostream>
#include <cstdint>
#include <memory>
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"

using namespace std;
using namespace fractal;

int main(int argc, const char * argv[]) {
   
    int const WIDTH = 800;
    int const HEIGHT = 600;
    
    Bitmap bitmap(WIDTH, HEIGHT);
    
    // Show a white spot in the middle of the bitmap
    //bitmap.setPixel(0, 0, 255, 255, 255);
    
    /*for (int x = 0, y = 0; y < HEIGHT; x++) {
        // Show a white spot in the middle of the bitmap
        if (x == WIDTH) {
            x = 0;
            y++;
        }
       
        bitmap.setPixel(x, y, 255, 0, 0);
    }*/
    
    double min = 999999;
    double max = -999999;
    
    unique_ptr<int[]> histogram(new int [Mandelbrot::MAX_ITERATIONS]{0});
    
    cout << "Teste" << endl;
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }
            
            uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
            
            color = color*color*color;
            
            bitmap.setPixel(x, y, 0, color, 0);
            if (color < min) min = color;
            if (color > max) max = color;
        }
    }
    cout << endl;
    
    int count = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        cout << histogram[i] << " " << flush;
        count += histogram[i];
    }
    
    cout << min << "," << max << endl;
    
    bool wrote = bitmap.write("test.bmp");
    cout << "Done: " << wrote << endl;
    
    return 0;
}
