#include <mlx.h>
#include <stdio.h>

/*
	mlx_init()
		initialse the MiniLibX library
		return a pointer to MiniLibx instance
		this function must be called before using any other Minilibx functions
		
	mlx_new_window(void *mlx_ptr, int width, int height, char *title)
		create a new window
		mlx_ptr: pointer return by mlx_init()
		width: width of window
		height: height of window
		title: title of window
	
	mlx_loop(mlx_ptr)
		keep the window open and responsive
		mlx_ptr: pointer returned by mlx_init()
	
	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
		Plots a pixel at specified coordinates in the window
		mlx_ptr: pointer return by mlx_init()
		win_ptr: pointer to window create by mlx_new_window()
		x: coordinate x
		y: coordinate y
		color: color of pixel

	
*/


int main() {
	
	void *mlx;
	mlx = mlx_int();
	if (!mlx) {
		printf("can not found MiniLibX\n");
		return 0;
	}
	
	
	 
	
	
	return 0;
	
}
















