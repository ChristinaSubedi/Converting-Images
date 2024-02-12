#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "util.h"



void fill(image_t *img, int x, int y, pixel_t *target_color, pixel_t initial_color){

        //out of dimension
        if (x>=img->w || x<0 || y>=img->h || y<0){
            return;
        }
        //different color
        pixel_t current_color=img->img[(y*img->w)+x];

        if (initial_color.r!=current_color.r ||
        initial_color.g!=current_color.g ||
        initial_color.b!=current_color.b ){
        return;
        }

        img->img[(y*img->w)+x].r=target_color->r;
        img->img[(y*img->w)+x].g=target_color->g;
        img->img[(y*img->w)+x].b=target_color->b;

        fill(img, x+1,y, target_color, initial_color);
        fill(img, x-1,y, target_color, initial_color);
        fill(img, x,y+1, target_color, initial_color);
        fill(img, x,y-1, target_color, initial_color);
    }

void flood(image_t *img, int x, int y, pixel_t *target_color) {
    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;
    
    pixel_t initial_color=img->img[(y*img->w)+x];

    if (initial_color.r==target_color->r &&
    initial_color.g==target_color->g &&
    initial_color.b==target_color->b ){
        return;
    }

    fill (img, x, y, target_color, initial_color);
    
}

