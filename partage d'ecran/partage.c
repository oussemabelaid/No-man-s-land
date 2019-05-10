#include "partage.h"

void init_splitscreen(SDL_Rect *I1,SDL_Rect *I2,int screenw)
{
int int_screenw=screenw/2;
I1->positionc.w=int_screenw;
I2->positionc.w=int_screenw;
I2->positiond.x=int_screenw;
}
