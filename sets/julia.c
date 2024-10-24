#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "set.h"


/*
	in julia everything start with here:
		Zn+1 = (Zn)² + C
*/


// julia function
void julia_fractl(int *data, int size_line) {
	
	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < WIDTH; y++) {
		
			// Define imaginary (Zy) & real (Zx) part of Zn With Zoom
			double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
			double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
	
			// Define imaginary (cIm) & real (cRe) part of C
			/*
				each complex number has specific image
				c = 0.35 + 0.35i
				c = 0.4 + 0.4i
				c = 0.8i
				c = −0.7269 + 0.1889i
			*/
			float cRe = -0.7, cIm = 0.27015;

			// julia Iterations
			int maxIteration = 100, Iteration = 0;
			while (zx * zx + zy * zy < 4 && Iteration < maxIteration) {
				double temp = zx * zx - zy * zy + cRe;
			 	zy = 2 * zx * zy + cIm;
			 	zx = temp;
			 	Iteration++;
			}
			
			if (Iteration == maxIteration) {
				data[x * (size_line / 4) + y] = 0x000000;
			} else {
				int color = (Iteration * 255 / maxIteration);
				data[x * (size_line / 4) + y] = (color << 16) | (color << 8);
			}
			
		}
	}
}







