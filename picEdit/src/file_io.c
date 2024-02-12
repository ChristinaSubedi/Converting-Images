#include "file_io.h"

#include <assert.h>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

#include "util.h"

int image_read(image_t *img, FILE *fin) {
  
  if (fscanf(fin, "P3\n%d %d\n255\n",&img->w,&img->h )!=2){
      return -1;
    }

    if (img->w<=0 || img->h<=0){
      return -1;
    }

    int img_size=img->w*img->h;
    img->img = malloc(img_size * sizeof(pixel_t));
    memset(img->img, 0, img_size * sizeof(img->img[0]));

   for (int i =0; i<img_size; i++){
 
    int r, g, b;

    if (fscanf(fin,"%d %d %d ", &r, &g, &b)!=3){
      image_free(img);
      return -1;
    }

    if (r>255 || g>255 || b>255 || r<0 || g<0 ||b<0){
      image_free(img);
      return -1;
    }

    img->img[i].r=r;
    img->img[i].g=g;
    img->img[i].b=b;

    }
    int temp;
    if (fscanf(fin, "%d",&temp)==1){
      return -1;
    }
  return 0;
}

void image_write(const image_t *img, FILE *fout) {
  
    fprintf(fout,"P3\n%d %d\n255\n", img->w,img->h);

    int counter=0;

    
    for (int i=0; i<img->w * img->h; i++){
      fprintf(fout, "%d %d %d ",img->img[counter].r,
      img->img[counter].g,
      img->img[counter].b);
      counter++;
      if (counter % img->w==0){
        fprintf(fout,"\n");
      }
    }
  
}

void image_free(image_t *img) {
    if (img->img != NULL) {
        free(img->img);
    }
    img->w = img->h = 0;
    img->img = NULL;
}
