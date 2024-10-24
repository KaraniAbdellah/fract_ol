#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "set.h"


/*
	in Mandbrot set start with here:
		Zn+1 = Zn² + C
*/

// Drawing Mandbrot Set
void mandelbrot_fractl(int *data, int size_line) {
	
	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < WIDTH; y++) {
			
			// Define Real & Imaginary Part of Zn
			double zx = 0;
			double zy = 0;
			
			// Define Real & Imaginary Part of C
			double cRe = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			double cIm = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			
			// Detecte the inside & outside points
			int maxIteration = 100;
			int iteration = 0;
			
			while (zx * zx + zy * zy < 4 && iteration < maxIteration) {
				double temp = zx * zx - zy * zy + cRe;
				zy = 2 * zx * zy + cIm;
				zx = temp;
				iteration++;
			}
			
			// Color the pixels
			if (iteration == maxIteration) {
				data[x * (size_line / 4) + y] = 0x000000; // Black for points in the set
			} else {
    			int color = (iteration * 255 / maxIteration);
    			data[x * (size_line / 4) + y] = (color << 16); // Red gradient
			}
			
		}
	}
	
}















