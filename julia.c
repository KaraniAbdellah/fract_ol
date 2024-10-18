#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>




void *julia_fractl(void *mlx, void *win_ptr, void *image, int *data, int size_line, int bpp, int endian) {

	
	data[100] = 0x00FF00;
	
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
	void *ptr_win = mlx_new_window(mlx, 1360, 750, "julia fract_ol");
	if (!ptr_win) {
		printf("can not create this windows\n");
		exit(1);
	}
	
	// create image in memory
	void *image = mlx_new_image(mlx, 1360, 750);
	if (!mlx_new_image) {
		printf("can not create image in memory\n");
		exit(1);
	}
	
	// access to the raw data (pixels) of the image 
	int bpp, size_line, endian;
	int *data = (int *) mlx_get_data_addr(image, &bpp, &size_line, &endian);
	
	// add image to window
	mlx_put_image_to_window(mlx, ptr_win, image, 0, 0);
	
	// draw julia fract
	julia_fractl(mlx, ptr_win, image, data, size_line, bpp, endian);
	
	// keep the window open
	mlx_loop(mlx);
	
	
	
	
	return 0;
	
}






