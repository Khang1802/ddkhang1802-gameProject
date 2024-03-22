#include <header/sources.h>

bool checkCollision(SDL_Rect a, SDL_Rect b)  //check va cham kha la chuan nhung se co chut lech do nhan vat, threat khong phai la hinh chu nhat hoan toan
{

    if (a.x + a.w <= b.x) return false;    //check phai a, trai b
    if (b.x + b.w <= a.x) return false;    //check trai a, phai b     
    if (a.y + a.h <= b.y) return false;    //check tren duoi 
    if (b.y + b.h <= a.y) return false;      
    return true;

}