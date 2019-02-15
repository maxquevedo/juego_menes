#include <allegro.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#define ancho 800
#define alto 600
using namespace std;

void prologo(BITMAP* principal, char* prota){
    string x;
    clear_bitmap(principal);
    BITMAP* fondo = create_bitmap(ancho,alto);
    bool aux = false;
    while(!key[KEY_ESC]){
            if(key[KEY_Q]){
                return;
            }
            rectfill(fondo, 30, 30, ancho-30, alto-30, makecol(0,0,0));
            textout_centre(fondo,font,"En una epoca reinada por el caos y el terror,",400,200,makecol(255,255,255));
            textout_centre(fondo,font,"nuestra historia ocurre en la mitica ciudad de Kalapa",400,220,makecol(255,255,255));
            textout(fondo,font,prota,150,240,makecol(255,255,255));
            textout(fondo,font,"se encontraba durmiendo bajo la sombra de una palmera",210,240,makecol(255,255,255));
            textout_centre(fondo,font,"un fuerte ruido retumba en sus oidos... abre los ojos",400,260,makecol(255,255,255));
            textout_centre(fondo,font,"ABRE LOS OJOS",400,300,makecol(255,255,255));
            textout_centre(fondo,font,"ABRE LOS OJOS",400,340,makecol(255,255,255));
            blit(fondo,screen,0,0,0,0,ancho,alto);
            if(key[KEY_J]){
                clear_bitmap(fondo);
                    break;
                }
            }
            key[KEY_J]=false;
        while(!key[KEY_ESC]){
            textout_centre(fondo,font,"tomas tu tiempo para comprobar tu equipo",400,200,makecol(255,255,255));
             textout_centre(fondo,font,"todo parece estar en orden",400,220,makecol(255,255,255));
              textout_centre(fondo,font,"decides caminar hacia el origen del ruido",400,240,makecol(255,255,255));
            blit(fondo,screen,0,0,0,0,ancho,alto);
            if(key[KEY_J]){
                clear_bitmap(fondo);
                break;
            }
        }
        key[KEY_J]=false;
        while(!key[KEY_ESC]){
            textout_centre(fondo,font,"Ves algo extraño a lo lejos",400,200,makecol(255,255,255));
            textout_centre(fondo,font,"te acercas para inspeccionar",400,240,makecol(255,255,255));
            blit(fondo,screen,0,0,0,0,ancho,alto);
            if(key[KEY_J]){
                clear_bitmap(fondo);
                break;
                }
            }
        key[KEY_J]=false;
}

void inicio(){

}

void gameOver(){

}
