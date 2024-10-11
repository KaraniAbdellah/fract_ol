#include <mlx.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int main(void) {
    void *mlx;          // Pointer to the mlx instance
    void *win;          // Pointer to the window

    mlx = mlx_init();   // Initialize the MiniLibX
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Simple MiniLibX Window"); // Create a new window

    // Fill the window with a color (e.g., red)
    mlx_clear_window(mlx, win); // Clear the window
    mlx_pixel_put(mlx, win, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0xFF0000); // Draw a red pixel in the center

    mlx_loop(mlx); // Enter the event loop

    return 0;
}

