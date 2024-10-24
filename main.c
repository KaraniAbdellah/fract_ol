#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include "sets/set.h"
#include <string.h>



#define WIDTH 900
#define HEIGHT 900


void choices() {
	printf("1: for julia set\n");
	printf("2: for mandelbrot set\n");
	printf("3: for bruning set\n");
}

void display_set(int *data, int size_line, int n) {
	
	if (n == 1) {
		// julia set
		julia_fractl(data, size_line);
	} else if (n == 2) {
		// mandelbrot set
		mandelbrot_fractl(data, size_line);
	} else if (n == 3) {
		// burning ship set
		burning_ship_fractl(data, size_line);
	} else {
		printf("Invalid number\n");
	}
	return;
}



int main() {
	
	int n;
	choices();
	do {
		printf("Enter a number: ");
		scanf("%d", &n);
	} while(n != 1 && n != 2 && n != 3);
	
	// Pointe to minilibx Library
	void *mlx = mlx_init();
	if (!mlx) {
		printf("can not found the minilibx\n");
		exit(1);
	}
	
	// Create new Window
	char win_name[20];
	if (n == 1) {
		strcpy(win_name, "julia set");
	} else if (n == 2) {
		strcpy(win_name, "mandelbrot set");
	} else {
		strcpy(win_name, "burning ship set");
	}
	void *ptr_win = mlx_new_window(mlx, WIDTH, HEIGHT, win_name);
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
	
	// Choice One Function
	display_set(data, size_line, n);
	
	// Add image to window
	mlx_put_image_to_window(mlx, ptr_win, new_image, 0, 0);
	
	// Keep window opening
	mlx_loop(mlx);
	
	return 0;
}














