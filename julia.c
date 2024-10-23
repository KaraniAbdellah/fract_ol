#include <stdio.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"

#define WIDTH 650
#define HEIGHT 600 


/*
	in julia everything start with here:
		Zn+1 = (Zn)² + C
*/

void julia_fractl(void *mlx, void *ptr_win, void *image, int *data, int size_line, int bpp, int endian) {
	
	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < WIDTH; y++) {
			// Define imaginary (Zy) & real (Zx) part of Zn
			int Zx = ;
			int Zy = ;
			
		}
	}
	
}



int main() {
	
	// initialze MiniLibX library
	void *mlx;
	mlx = mlx_init();
	if (!mlx) {
		printf("can not find MiniLibX Library\n");
		exit(1);
	}
	
	// create new window
	void *ptr_win = mlx_new_window(mlx, WIDTH, HEIGHT, "julia fract_ol");
	if (!ptr_win) {
		printf("can not create this windows\n");
		exit(1);
	}
	
	// create image in memory
	void *image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image) {
		printf("can not create image in memory\n");
		exit(1);
	}
	
	// access to the raw data (pixels) of the image 
	int bpp, size_line, endian;
	int *data = (int *) mlx_get_data_addr(image, &bpp, &size_line, &endian);
	
	// draw julia fract
	julia_fractl(mlx, ptr_win, image, data, size_line, bpp, endian);
	
	// add image to window
	mlx_put_image_to_window(mlx, ptr_win, image, 0, 0);
	
	// keep the window open
	mlx_loop(mlx);
	
	
	
	
	return 0;
	
}



/*
	int index = WIDTH * x + y;
	int random_number = rand() * 10 + 1;
	data[index] = random_number;
	data[index + 1] = random_number;
	data[index + 2] = random_number;
	data[index + 3] = random_number;

	printf("zx = %.1f & zy = %.1f\n", zx, zy);
*/











