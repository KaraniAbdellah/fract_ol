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
	
	NOTE: drawing using mlx_pixel_put() is not good for effecient --> we need other functions
	
	void *image = mlx_new_image(mlx, width, height);
		Creates an empty image in memory where you can draw your fractal
			the image will ne show in screen until you put it into a window.
		mlx: The pointer from mlx_init().
		width and height: The size of the image.
	
	int *data = (int *) mlx_get_data_addr(image, &bpp, &size_line, &endian);
		Gives you access to the raw data (pixels) of the image you created
			You need this to modify individual pixels.
		image: The image created by mlx_new_image().
		bpp, size_line, endian: 
			bpp((bits per pixel): how many bits are used to store one pixel
			size_line: this tell you how many bytes are used for each line
			endian: this tells you byte order used to store pixel data
				0: means little-endian
				1: means big endian
			
	mlx_put_image_to_window(mlx, win, image, 0, 0);
		Displays the image you created and modified in the window.
		mlx: The pointer from mlx_init().
		win: The window created by mlx_new_window().
		image: The image to show.
		0, 0: Position in the window (top-left corner).
	
		resume: 
			create space in memory for the image
			access and modify the image's pixels
			finally display the image in window.
			
	
*/





int main() {
	
	void *mlx;
	mlx = mlx_init();
	if (!mlx) {
		printf("can not found MiniLibX\n");
		return 0;
	}
	void *win_ptr = mlx_new_window(mlx, 1360, 750, "fract_ol");
	mlx_pixel_put(mlx, win_ptr, 100, 100, 1000);
	
	int bpp, size_line, endian;
	void *image = mlx_new_image(mlx, 1360, 750);s
	int *data = (int *) mlx_get_data_addr(image, &bpp, &size_line, &endian);
	mlx_put_image_to_window(mlx, win_ptr, image, 0, 0);
	
	
	
	mlx_loop(mlx);
	 
	
	
	
	
	
	return 0;
	
}
















