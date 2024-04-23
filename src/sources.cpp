#include <header/sources.h>

bool checkCollision(SDL_Rect a, SDL_Rect b)  
{

    if (a.x + a.w <= b.x) return false;    //check phai a, trai b
    if (b.x + b.w <= a.x) return false;    //check trai a, phai b     
    if (a.y + a.h <= b.y) return false;    
    if (b.y + b.h <= a.y) return false;      
    return true;

}
