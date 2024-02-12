#include "image_edit.h"
#include "structures.h"
#include <stdlib.h>

#include "util.h"

void rotate_counterclockwise(image_t *img) {
    int img_size=img->w*img->h;
    pixel_t *pixels=malloc(img_size*(sizeof(img->img[0])));
    int counter=0;
    int index=0;
    for (int i=img->w-1; i>=0; i--){
        for (int j=0; j<img->h; j++){
            counter=img->w*j+i;
            pixels[index].r=img->img[counter].r;
            pixels[index].g=img->img[counter].g;
            pixels[index].b=img->img[counter].b;
            index++;
        }
        
    }
    free(img->img);
    img->img=pixels;
    int temp=img->w;
    img->w=img->h;
    img->h=temp;
}

void rotate_clockwise(image_t *img) {
    rotate_counterclockwise(img);
    rotate_counterclockwise(img);
    rotate_counterclockwise(img);
    
}

void mirror_horizontal(image_t *img) {
    int img_size=img->w*img->h;
    pixel_t *pixels=malloc(img_size*(sizeof(img->img[0])));
    int counter=0;
    int index=0;
    for (int i=0; i<img->h; i++){
        for (int j=img->w-1; j>=0; j--){
            counter= img->w*i+j;
            pixels[index].r=img->img[counter].r;
            pixels[index].g=img->img[counter].g;
            pixels[index].b=img->img[counter].b;
            index++;
        }
    }
    free(img->img);
    img->img=pixels;
}

void mirror_vertical(image_t *img) {
    rotate_clockwise(img);
    mirror_horizontal(img);
    rotate_counterclockwise(img);
}

void resize(image_t *img, int new_width, int new_height) {
    int img_size=new_width*new_height;
    pixel_t *pixels=malloc(img_size*(sizeof(img->img[0])));
    int counter=0;
    int index=0;

    for(int i=0;i<new_height; i++){
        for (int j=0; j<new_width; j++){
            counter=new_width*i+j;
            if (i>=img->h ||j>=img->w ){
                pixels[counter].r=0;
                pixels[counter].g=0;
                pixels[counter].b=0;
            } else {
                index=img->w*i+j;
                pixels[counter].r=img->img[index].r;
                pixels[counter].g=img->img[index].g;
                pixels[counter].b=img->img[index].b;
            }

        }
    }

    free(img->img);
    img->img=pixels;
    img->w=new_width;
    img->h=new_height;
}
