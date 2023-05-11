#include <mlx.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}				t_data;

int		my_key_press_hook(int keycode, t_data *data)
{
	printf("Key Pressed: %d\n", keycode);
	return (0);
}

int		main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Key Display");

	mlx_key_hook(data.win, my_key_press_hook, &data);

	mlx_loop(data.mlx);

	return (0);
}
