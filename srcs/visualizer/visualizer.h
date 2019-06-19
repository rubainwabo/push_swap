/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:11:35 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 23:40:50 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../../push_swap.h"
# include "minilibx_macos/mlx.h"
# define HEIGHT 1200
# define WIDTH  1500

/*
** 									DRAW_LINE
*/

typedef	struct		s_point
{
	int				x;
	int				y;
	int				color;
}					t_point;

typedef struct		s_draw
{
	int				x;
	int				y;
	int				cumul;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				color;
}					t_draw;

/*
** 									VISUALIZER
*/

void				draw_line(char *img, t_point start_pt, t_point end_pt);
void				put_pixel_img(char *image_str, int x, int y, int color);
int					draw_graphics(t_swap *d);
void				build_images(t_swap *d);
void				draw_rec_b(t_swap *d, int start, int size);
void				draw_rec_a(t_swap *d, int start, int size);
int					visu_instructions(char *str);
int					get_color(int color1, int color2, double percentage);
int					deal_key(int key, t_swap *d);
int					max_min(t_list *stack, int c);
int					scaling_compute(t_swap *d, int nbr);

#endif
