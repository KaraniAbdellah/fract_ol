#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>


#define WIDTH 1360
#define HEIGHT 750


// NOTE: you need to handle each byte of the image to correctly display the pixel colors
/*
	// Define the Complex Constant:
		Zn+1 = Zn^2 + C
		cRe: real part of C
		cIm: imaginary of C 
	// 
*/

void *julia_fractl(void *mlx, void *win_ptr, void *image, int *data, int size_line, int bpp, int endian) {

	
	
	// Loop over the screen
	/*
		size_line = 5440 = 1360 * 4
			each pixel present by 4 byte (red, green, blue, alpha)
	*/
	printf("size_line = %d\n", size_line);
	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < WIDTH; y++) {
            
			// Map pixel position to the complex plane
        	double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
        	double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
            
			// Define the complex constant
			float cRe = -0.47, cIm = 0.65;
            
			// Julia iteration
        	int maxIterations = 100;
        	int iteration = 0;
			while (zx * zx + zy * zy < 4 && iteration < maxIterations) {
		        double tmp = zx * zx - zy * zy + cRe;
		        zy = 2 * zx * zy + cIm;
		        zx = tmp;
		        iteration++;
        	}
            
            int index = WIDTH * x + y;
			// Set color based on iteration
			if (iteration == maxIterations) {
				data[index] = 0;
				data[index + 1] = 0;
				data[index + 2] = 0;
				data[index + 3] = 255;
			} else {
				int color = (iteration * 255 / maxIterations);
				data[index] = color;
				data[index + 1] = 0;
				data[index + 2] = 0;
				data[index + 3] = 255;
			}

            
		}
	}	
	
	
	
	
	return NULL;
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
*/


















