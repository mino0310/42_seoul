#include <stdio.h>
#include "mlx/mlx.h"

int main() {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;

    int img_width;
    int img_height;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "my_mlx");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/wall_e.xpm", &img_width, &img_height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 50, 50);
    mlx_loop(mlx_ptr);
    return (0);
}

