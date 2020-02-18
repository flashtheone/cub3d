//
// Created by Anass Sbai el idrissi on 2/17/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "get_next_line.h"

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

typedef struct      s_point
{
    float x;
    float y;
}                   t_point;

typedef struct		s_resolution
{
    int width;
    int height;
}					t_resolution;

typedef struct		s_cfcolor
{
    int r;
    int g;
    int b;
}					t_cfcolor;

typedef struct		s_map
{
    int				*value;
    int				len;
    struct s_map	*next;
}					t_map;

typedef struct      s_player
{
    t_point pos;
    t_point dir;
    t_point plane;
}                   t_player;

typedef struct		s_config
{
    t_resolution	resl;
  int				spawn;
    char			*no_path;
    char			*so_path;
    char			*we_path;
    char			*ea_path;
    char			*sprite_path;
    t_cfcolor		celling_colors;
    t_cfcolor		floor_colors;
  t_cfcolor       rgb;
    void			*ptr;
    void			*win;t_map			*map;
    t_player        player;
    int **map_arr;
}					t_config;

void        initialize_conf(t_config *conf);
t_config    ft_parse(char *path);

void    fill_conf_infos(t_config *game_conf, char *path);
void fill_map(t_config *game_conf, char *path,char *line, int fd_cub, int gnl_return);
void    ft_fill_conf(char *line, t_config *game_conf);
void ft_get_resolution(char *line, t_config *game_conf);
char    *ft_get_path(char *line, t_config *game_conf);
void    ft_get_RGB(char *line, t_cfcolor *game_conf);
void    check_line_char(char c, char *line, t_config *game_conf);

#endif //CUB3D_CUB3D_H