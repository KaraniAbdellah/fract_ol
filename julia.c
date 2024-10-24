#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

#define WIDTH 1000
#define HEIGHT 1000


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

int mouse_scroll(int button, int x, int y, void *param) {
    if (button == 4) { // Scroll up
        zoom_level *= 1.1; // Zoom in
        center_x += (x - WIDTH / 2) * (1 - 1 / zoom_level);
        center_y += (y - HEIGHT / 2) * (1 - 1 / zoom_level);
    } else if (button == 5) { // Scroll down
        zoom_level /= 1.1; // Zoom out
        center_x += (x - WIDTH / 2) * (1 - 1 / zoom_level);
        center_y += (y - HEIGHT / 2) * (1 - 1 / zoom_level);
    }

    // Redraw the fractal
    void *image = mlx_new_image(param, WIDTH, HEIGHT);
    int bpp, size_line, endian;
    int *data = (int *)mlx_get_data_addr(image, &bpp, &size_line, &endian);
    julia_fractl(data, size_line);
    mlx_put_image_to_window(param, (void *)param, image, 0, 0);
    mlx_destroy_image(param, image);

    return 0;
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
	julia_fractl(data, size_line);
	
    // Hook mouse scroll function
    mlx_mouse_hook(ptr_win, mouse_scroll, mlx);
	
	// add image to window
	mlx_put_image_to_window(mlx, ptr_win, image, 0, 0);
	
	// keep the window open
	mlx_loop(mlx);
	
	
	
	
	return 0;
	
}






// Add Zoom Variables
/*
// Define imaginary (Zy) & real (Zx) part of Zn
double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
*/












