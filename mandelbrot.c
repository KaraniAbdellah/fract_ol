#include <stdio.h>
#include "mlx.h"
#include <stdlib.h>


#define WIDTH 900
#define HEIGHT 900

/*
	For Mandbrot set:
		Zn+1 = Zn² + C
*/

// Drawing Mandbrot Set
void mandelbrot(int *data, int size_line) {
	
	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < WIDTH; y++) {
			
			// Define Real & Imaginary Part of Zn
			double zx = 0;
			double zy = 0;
			
			// Define Real & Imaginary Part of C
			double cRe = 0.3342;
			double cIm = 0.3;
			
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
				data[x * (size_line / 4) + y] = (color << 16) | (color << 8); // Color gradient
			}
			
		}
	}
	
}



int main() {
	
	// Pointe to minilibx Library
	void *mlx = mlx_init();
	if (!mlx) {
		printf("can not found the minilibx\n");
		exit(1);
	}
	
	// Create new Window
	void *ptr_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandbrot");
	if (!ptr_win) {
		printf("can not create a window\n");
		exit(1);
	}
	
	// Create new image in memory
	void *new_image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!new_image) {
		printf("can not create new image in memory\n");
		exit(1);
	}
	
	// Access to image pixel's
	int bpp, size_line, endian;
	int *data = (int *) mlx_get_data_addr(new_image, &bpp, &size_line, &endian);
	
	// Draw Mandlbrot image
	mandelbrot(data, size_line);
	
	// Add image to window
	mlx_put_image_to_window(mlx, ptr_win, new_image, 0, 0);
	
	// Keep window opening
	mlx_loop(mlx);
	
	
	
	
	return 0;
}














