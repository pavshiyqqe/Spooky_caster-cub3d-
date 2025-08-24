#include <math.h>
#include <stdlib.h>
#include "mlx.h"

#define WIN_W 1200
#define WIN_H 1000
#define FOV (M_PI / 3)
#define MAP_W 8
#define MAP_H 20
#define TILE 64
#define SPEED 1
#define ROT_SPEED 0.02
#define MINI_SCALE 0.15
#define MINI_TILE (int)((WIN_H * MINI_SCALE) / MAP_H)
#define MINI_MARGIN (WIN_W / 100)

char map[MAP_H][MAP_W] = {
    {'0','0','1','1','1','1','1','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','S','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'0','0','1','0','0','0','0','1'},
    {'1','1','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1'},
    {'1','1','1','1','1','1','1','1'}
};

typedef struct {
    void *img;
    char *addr;
    int width;
    int height;
    int bpp;
    int line_len;
    int endian;
} t_texture;

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    double px, py;
    double pa;
    t_texture north, south, west, east;
} t_game;

int keys[65536];

void find_player_start(t_game *g) {
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            char cell = map[y][x];
            if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W') {
                g->px = (x + 0.5) * TILE;
                g->py = (y + 0.5) * TILE;
                if (cell == 'N') g->pa = 3 * M_PI / 2;
                else if (cell == 'S') g->pa = M_PI / 2;
                else if (cell == 'E') g->pa = 0;
                else if (cell == 'W') g->pa = M_PI;
                map[y][x] = '0';
                return;
            }
        }
    }
}

int is_wall(double x, double y) {
    int mx = (int)(x / TILE);
    int my = (int)(y / TILE);
    if (mx < 0 || my < 0 || mx >= MAP_W || my >= MAP_H)
        return 1;
    return map[my][mx] != '0';
}

void put_pixel(t_game *g, int x, int y, int color) {
    char *dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
    *(unsigned int*)dst = color;
}

void draw_minimap(t_game *g)
{
    int start_x = MINI_MARGIN;
    int start_y = MINI_MARGIN;

    // Рисуем саму карту
    for (int y = 0; y < MAP_H; y++)
    {
        for (int x = 0; x < MAP_W; x++)
        {
            int color = (map[y][x] != '0') ? 0x000000 : 0xC0C0C0;
            for (int i = 0; i < MINI_TILE; i++)
                for (int j = 0; j < MINI_TILE; j++)
                    put_pixel(g, start_x + x*MINI_TILE + i, start_y + y*MINI_TILE + j, color);
        }
    }

    // Позиция игрока на миникарте
    int px = start_x + (int)(g->px / TILE * MINI_TILE);
    int py = start_y + (int)(g->py / TILE * MINI_TILE);

    // Рисуем лучи (фонарик)
    int rays = 30;
    for (int i = 0; i < rays; i++)
    {
        double ray_angle = g->pa - FOV/2 + (FOV * i / rays);

        double rx = g->px;
        double ry = g->py;

        // Рассчитываем приращение шага по x и y
        double step_size = 0.05; // можно уменьшить для точности
        double stepX = cos(ray_angle) * step_size;
        double stepY = sin(ray_angle) * step_size;

        while (1)
        {
            rx += stepX;
            ry += stepY;

            // Проверка выхода за карту
            if (rx < 0 || ry < 0 || rx >= MAP_W*TILE || ry >= MAP_H*TILE) break;

            // Если столкновение со стеной — прерываем
            if (is_wall(rx, ry)) break;

            // Рисуем пиксель на миникарте
            int mx = start_x + (int)(rx / TILE * MINI_TILE);
            int my = start_y + (int)(ry / TILE * MINI_TILE);
            put_pixel(g, mx, my, 0x90EE90);
        }
    }

    // Рисуем игрока
    for (int i = -2; i <= 1; i++)
        for (int j = -2; j <= 1; j++)
            put_pixel(g, px + i, py + j, 0xFF0000);
}


void render(t_game *g) {
    g->img = mlx_new_image(g->mlx, WIN_W, WIN_H);
    g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
    for (int col = 0; col < WIN_W; col++) {
        double ray_angle = g->pa - (FOV / 2) + ((double)col / WIN_W) * FOV;
        double rayDirX = cos(ray_angle);
        double rayDirY = sin(ray_angle);
        int mapX = (int)(g->px / TILE);
        int mapY = (int)(g->py / TILE);
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);
        double sideDistX, sideDistY;
        int stepX, stepY;
        if (rayDirX < 0) { stepX = -1; sideDistX = (g->px - mapX * TILE) / TILE * deltaDistX; }
        else { stepX = 1; sideDistX = ((mapX + 1) * TILE - g->px) / TILE * deltaDistX; }
        if (rayDirY < 0) { stepY = -1; sideDistY = (g->py - mapY * TILE) / TILE * deltaDistY; }
        else { stepY = 1; sideDistY = ((mapY + 1) * TILE - g->py) / TILE * deltaDistY; }
        int hit = 0;
        int side;
        while (!hit) {
            if (sideDistX < sideDistY) { sideDistX += deltaDistX; mapX += stepX; side = 0; }
            else { sideDistY += deltaDistY; mapY += stepY; side = 1; }
            if (mapY < 0 || mapY >= MAP_H || mapX < 0 || mapX >= MAP_W || map[mapY][mapX] != '0')
                hit = 1;
        }
        double trueDist;
        if (side == 0) trueDist = (mapX - g->px / TILE + (1 - stepX) / 2.0) / (rayDirX / TILE);
        else trueDist = (mapY - g->py / TILE + (1 - stepY) / 2.0) / (rayDirY / TILE);
        double perpWallDist = trueDist * cos(ray_angle - g->pa);
        int line_height = (int)(WIN_H / perpWallDist * TILE);
        int draw_start = -line_height / 2 + WIN_H / 2;
        int draw_end = line_height / 2 + WIN_H / 2;
        if (draw_start < 0) draw_start = 0;
        if (draw_end >= WIN_H) draw_end = WIN_H - 1;
        t_texture *tex;
        if (side == 0) { if (rayDirX > 0) tex = &g->west; else tex = &g->east; }
        else { if (rayDirY > 0) tex = &g->north; else tex = &g->south; }
        double wallX;
        if (side == 0) wallX = fmod(g->py / TILE + trueDist * rayDirY / TILE, 1.0);
        else wallX = fmod(g->px / TILE + trueDist * rayDirX / TILE, 1.0);
        if (wallX < 0) wallX += 1.0;
        int tex_x = (int)(wallX * tex->width);
        if ((side == 0 && rayDirX > 0) || (side == 1 && rayDirY < 0)) tex_x = tex->width - tex_x - 1;
        double step_tex = (double)tex->height / line_height;
        double tex_pos = (draw_start - WIN_H / 2 + line_height / 2) * step_tex;
        for (int y = 0; y < WIN_H; y++) {
            if (y < draw_start) put_pixel(g, col, y, 0x6E6B5E);
            else if (y <= draw_end) {
                int tex_y = (int)tex_pos;
                if (tex_y < 0) tex_y = 0;
                if (tex_y >= tex->height) tex_y = tex->height - 1;
                char *tex_pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
                int color = *(unsigned int*)tex_pixel;
                put_pixel(g, col, y, color);
                tex_pos += step_tex;
            } else put_pixel(g, col, y, 0x3B2A25);
        }
    }
    draw_minimap(g);
    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
    mlx_destroy_image(g->mlx, g->img);
}

int update(t_game *g) {
    double nx, ny;
    if (keys['w']) { nx = g->px + cos(g->pa) * SPEED; ny = g->py + sin(g->pa) * SPEED; if (!is_wall(nx, ny)) { g->px = nx; g->py = ny; } }
    if (keys['s']) { nx = g->px - cos(g->pa) * SPEED; ny = g->py - sin(g->pa) * SPEED; if (!is_wall(nx, ny)) { g->px = nx; g->py = ny; } }
    if (keys['d']) { nx = g->px - sin(g->pa) * SPEED; ny = g->py + cos(g->pa) * SPEED; if (!is_wall(nx, ny)) { g->px = nx; g->py = ny; } }
    if (keys['a']) { nx = g->px + sin(g->pa) * SPEED; ny = g->py - cos(g->pa) * SPEED; if (!is_wall(nx, ny)) { g->px = nx; g->py = ny; } }
    if (keys[65361]) g->pa -= ROT_SPEED;
    if (keys[65363]) g->pa += ROT_SPEED;
    render(g);
    return 0;
}

int key_press(int keycode, t_game *g) { keys[keycode] = 1; if (keycode == 65307) exit(0); return 0; }
int key_release(int keycode, t_game *g) { keys[keycode] = 0; return 0; }
int close_hook(t_game *g) { (void)g; exit(0); return 0; }

int main() {
    t_game g;
    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, WIN_W, WIN_H, "Spooky-caster");
    find_player_start(&g);
    g.north.img = mlx_xpm_file_to_image(g.mlx, "north.xpm", &g.north.width, &g.north.height);
    g.south.img = mlx_xpm_file_to_image(g.mlx, "south.xpm", &g.south.width, &g.south.height);
    g.west.img  = mlx_xpm_file_to_image(g.mlx, "west.xpm",  &g.west.width,  &g.west.height);
    g.east.img  = mlx_xpm_file_to_image(g.mlx, "east.xpm",  &g.east.width,  &g.east.height);
    g.north.addr = mlx_get_data_addr(g.north.img, &g.north.bpp, &g.north.line_len, &g.north.endian);
    g.south.addr = mlx_get_data_addr(g.south.img, &g.south.bpp, &g.south.line_len, &g.south.endian);
    g.west.addr  = mlx_get_data_addr(g.west.img,  &g.west.bpp,  &g.west.line_len,  &g.west.endian);
    g.east.addr  = mlx_get_data_addr(g.east.img,  &g.east.bpp,  &g.east.line_len,  &g.east.endian);
    mlx_hook(g.win, 2, 1L<<0, key_press, &g);
    mlx_hook(g.win, 3, 1L<<1, key_release, &g);
    mlx_loop_hook(g.mlx, update, &g);
    mlx_hook(g.win, 17, 0, close_hook, &g);
    mlx_loop(g.mlx);
    return 0;
}
