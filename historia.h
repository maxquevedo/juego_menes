#include <allegro.h>
#include <stdio.h>
#include <cstring>
#define ancho 800
#define alto 600
using namespace std;

void prologo(BITMAP* principal, char* prota){
    clear_bitmap(principal);
    BITMAP* fondo = create_bitmap(ancho,alto);
    bool aux = false;
    if(key[KEY_Q]){
        return;
    }
    while(!key[KEY_ESC]){
            rectfill(fondo, 30, 30, ancho-30, alto-30, makecol(0,0,0));
            textout_centre(fondo,font,"En una epoca reinada por el caos y el terror,",300,200,makecol(255,255,255));
            textout_centre(fondo,font,"nuestra historia ocurre en la mitica ciudad de Kalapa",300,210,makecol(255,255,255));
            textout(fondo,font,prota,200,220,makecol(255,255,255));
            textout(fondo,font,"se dirigia a su ksita",270,220,makecol(255,255,255));
//            textout_centre(fondo,font,"",300,200,makecol(255,255,255));
 //           textout_centre(fondo,font,"",300,200,makecol(255,255,255));
  //          textout_centre(fondo,font,"",300,200,makecol(255,255,255));
            blit(fondo,screen,0,0,0,0,ancho,alto);
            if(key[KEY_J]){
                aux = true;
            }
        }
}

void inicio(){

}

void gameOver(){

}
