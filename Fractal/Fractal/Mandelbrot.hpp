//
//  Mandelbrot.hpp
//  Fractal
//
//  Created by Daniel Marchena Parreira on 2018-08-13.
//  Copyright © 2018 Daniel Marchena Parreira. All rights reserved.
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

#include <stdio.h>

namespace fractal {
    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;
        Mandelbrot();
        virtual ~Mandelbrot();
        
        static int getIterations(double x, double y);
    };
}

#endif /* Mandelbrot_hpp */
