/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:34:13 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 21:21:14 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../lib/lib.h"
# include "../mlx/mlx.h"
# include <math.h>

# define WIDTH 1080	
# define HEIGHT 1080

typedef struct infos
{
	float	p_angle;
	float	x_distance;
	float	y_distance;
	float	distance_to_wall;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		length;
	float	xint;
	float	yint;
	int		endian;
	int		height;
	int		width;
	int		dx;
	int		dy;
	int		x0;
	int		y0;
	int		i;
	int		j;
	int		y;
	int		h;
	int		g;
	float	proj;
	float	x;
	int		z;
	int		v_abs;
	float	a;
	int		wall;
	float	b;
	float	c;
	int		n;
	int		w;
	int		s;

}	t_infos;

typedef struct s_pic
{
	void			*mlx;
	void			*wind;
	t_infos			*imgs;
}	t_pic;

typedef struct map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				i;
	int				j;
	char			**map;
	t_pic			cub;
	t_infos			*player;
	long			cel;
	long			floor;
	t_infos			img;
	int				map_height;
	int				map_width;
	int				event[6];
	int				k;
	int				dir;
	float			agnle;
}	t_map;

t_map			*parse_map(char **x);
int				ft_strcmp(char *str, char *str1);
char			**open_map(char *str); //
int				check_extention(char *str);
int				detect_error(t_map *map);
int				check_path(t_map *map);
char			**final_map(char **mp);
int				is_letter(char c);
int				is_space(char c);
int				is_number(char c);
int				is_one(char *line);
int				get_index(char **map, int i);
int				map_letter(char **map);
int				check_map_walls(char **map, int last);
int				check_player(char **map);
int				check_space(char **map);
char			**read_map(char *file);
char			*ft_strdup1(char *s1);
int				check_zero(char **map, int i, int j);
int				check_map_walls(char **map, int last);
int				ft_convert(char *str, int i, int result, int sign);
int				ft_atoi1(char *str);
int				ft_strcmp1(char *s1, char *s2);
int				check_player(char **map);
int				check_emptyline(char **map);
int				file_size(char	**file);
char			**ft_split(char const *s, char c);
int				check_rgb(char *colors);
int				str_check(char *str, char *str1);
int				hook_one(int keycode, t_map *p);
int				hook_zero(int keycode, t_map *p);
t_map			*init_mp(t_map *p);
int				window_witdh(char **map, char a);
int				ft_exit(t_map *p);
void			check_texture(t_map *p);
t_infos			*ft_infos(t_map *p);
t_map			*player_angle(t_map *p, int i, int j);
char			**remake_angles(t_map *p);
unsigned long	get_rgb(char *str);
void			render_3d(t_map *p, t_pic *mlx);
void			draw_player(t_map *p, t_pic *mlx);
void			directions(t_map *mp, float a, float b, char c);
int				cnv_clr(t_map *p, int x, int y);
void			my_mlx_pixel_put(t_infos *data, int x, int y, int color);
int				dda(t_infos *t, t_map *p);
void			dda_two(t_infos *inf, t_map *mp);
int				between(t_infos *t, t_map *p);
void			draw_3d(t_map *p, t_infos *t);
int				checkwall(t_infos *t, t_map *p);
t_infos			*check_wall(t_map *p, int i);
int				move_player(t_map *p, t_pic *mlx);
void			run_hoooks(t_map *p, t_pic *mlx);
t_map			*init_texture(t_map *p, t_pic *mlx);
void			p_error(void);
void			free_2d(char **s);
int				map_check(char **map_only, char **file);
int				array_size(char **s);
int				check_existence(char **map);
void			error_exit(void);
void			change_xy(t_map *map, int angle, char sign, int wall);
int				nb_characters(char *s);
char			*ft_strtrim1(char *s1, char *set);
int				ft_exit(t_map *mp);
char			*ft_strdup_one(const char *src);
char			**remake(t_map *map);
char			**remake2(t_map *map);
int				move_player(t_map *mp, t_pic *mlx);
t_map			*player_angle(t_map *map, int i, int j);

#endif