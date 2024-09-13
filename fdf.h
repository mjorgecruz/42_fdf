/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:30:35 by masoares          #+#    #+#             */
/*   Updated: 2023/12/07 15:35:09 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_L 1920
# define WIN_H 1080

# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_point
{
	int				x;
	int				y;
	float			z;
	unsigned int	color;
	float			zz;
	double			u;
	double			v;
}	t_point;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bitspp;
	int		line_length;
	int		endian;
	int		color;
	int		map_l;
	int		map_w;
	double	ang_x;
	double	ang_y;
	double	ang_z;
	double	zoom;
	int		ctrl_p;
	int		shift_p;
	int		alt_p;
	int		prev_x;
	int		prev_y;
	int		mouse2;
	int		trans_u;
	int		trans_v;
	int		z_changer;
	t_point	***map;
}	t_data;

/* ************************************************************************** */
/*                               FDF_UTILS                                    */
/* ************************************************************************** */
void	pixel_put(t_data *data, int x, int y, int color);
int		color_make(int i, int j);
int		color_z_based(int z, int x);

/* ************************************************************************** */
/*                               FDF_RENDER                                   */
/* ************************************************************************** */
int		render(t_data *img, t_point **map);
void	render_view(t_data *img, t_point **map);
void	render_rect(t_data *img);
void	render_rect2(t_data *img);
void	render_rect3(t_data *img);

/* ************************************************************************** */
/*                             IMAGE_CREATOR                                  */
/* ************************************************************************** */
int		image_creator(t_data *img, t_point **map);

/* ************************************************************************** */
/*                                 HANDLERS                                   */
/* ************************************************************************** */
int		handle_destroy(t_data *img);
int		handle_input(int keysym, t_data *img);
int		handle_input_2(int keysym, t_data *img);
int		handle_release(int keysym, t_data *img);
int		close_all(t_data *img);

/* ************************************************************************** */
/*                                 CONTROLS                                   */
/* ************************************************************************** */
int		controls(int mousecode, int x, int y, t_data *img);
int		control_zoom(int mousecode, int x, int y, t_data *img);
int		control_angles(int x, int y, t_data *img);
int		controls_release(int mousecode, int x, int y, t_data *img);
int		control_views(int view, t_data *img);

/* ************************************************************************** */
/*                                 CONTROLS_2                                 */
/* ************************************************************************** */
int		control_trans(int key, t_data *img);

/* ************************************************************************** */
/*                               MAP_CONVERTER                                */
/* ************************************************************************** */
t_point	**map_converter(char *filename, int *x, int *y);
int		find_dimension(int *x, int *y, char *filename);
int		create_array(int x, int y, char *filename, t_point ***map);
int		add_to_map(t_point **map, int x, int y, char **splited);
void	coordinate_converter(t_data *img, t_point **map);

/* ************************************************************************** */
/*                                  FREEING                                   */
/* ************************************************************************** */
int		splited_free(char **splited);
int		map_free(t_point **map, int x, int y);

/* ************************************************************************** */
/*                              ERROR_HANDLING                                */
/* ************************************************************************** */
int		errors(int i);

/* ************************************************************************** */
/*                                  MATHINGS                                  */
/* ************************************************************************** */
int		rot_calculator(t_data *img, t_point *map, double *u1, double *v1);
void	mat_multiplier_x(t_data *img, double *v, float *z);
void	mat_multiplier_y(t_data *img, double *u, float *z);
void	mat_multiplier_z(t_data *img, double *u, double *v);

/* ************************************************************************** */
/*                                 BRESENHAM                                  */
/* ************************************************************************** */
int		bresenham(t_point map, double u1, double v1, t_data *img);
int		max_finder(double varu, double varv);

#endif
