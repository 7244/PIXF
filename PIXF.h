#pragma once

typedef enum{
  PIXF_YUV420p,
  PIXF_YUVNV12,
  PIXF_BGRX,
  PIXF_BGRA,
  PIXF_RGB24
}PIXF;

uint8_t PIXF_GetImageCount(PIXF pixf){
  switch(pixf){
    case PIXF_YUV420p:
    {
      return 3;
    }
    case PIXF_YUVNV12:
    {
      return 2;
    }
    case PIXF_BGRX:
    case PIXF_BGRA:
    case PIXF_RGB24:
    {
      return 1;
    }
  }
  __abort();
  __unreachable();
}

void PIXF_GetImageSize(PIXF pixf, uint8_t ImageIndex, uint32_t *x, uint32_t *y){
  switch(pixf){
    case PIXF_YUV420p:
    {
      switch(ImageIndex){
        case 0:
        {
          return;
        }
        case 1:
        case 2:
        {
          *x /= 2;
          *y /= 2;
          return;
        }
        default:{
          __abort();
          __unreachable();
        }
      }
    }
    case PIXF_YUVNV12:
    {
      switch(ImageIndex){
        case 0:
        {
          return;
        }
        case 1:{
          *y /= 2;
          return;
        }
        default:{
          __abort();
          __unreachable();
        }
      }
    }
    case PIXF_BGRX:
    case PIXF_BGRA:
    {
      if(ImageIndex != 0){
        __abort();
        __unreachable();
      }
      *x *= 4;
      return;
    }
    case PIXF_RGB24:
    {
      if(ImageIndex != 0){
        __abort();
        __unreachable();
      }
      *x *= 3;
      return;
    }
    default:{
      __abort();
      __unreachable();
    }
  }
}
