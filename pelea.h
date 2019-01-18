#include <allegro.h>
#define ancho 800
#define alto 600
using namespace std;

void estado(BITMAP*fondo_pelea){
    hline(fondo_pelea,ancho,alto-210,0,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"En pelea",ancho/2,alto-200,makecol(255,255,255));
    hline(fondo_pelea,ancho,420,0,makecol(255,255,255));
return;
}

void menu_pelea(BITMAP*fondo_pelea){
    textout_centre(fondo_pelea,font,"Atacar",250,465,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"Magia",550,465,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"Huir",550,520,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"Objeto",250,520,makecol(255,255,255));
return;
}

void menu_pelea_atacar(BITMAP*fondo_pelea){
    clear_bitmap(fondo_pelea);
    textout_centre(fondo_pelea,font,"Golpe Simple",250,465,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"",550,465,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"",550,520,makecol(255,255,255));
    textout_centre(fondo_pelea,font,"",250,520,makecol(255,255,255));

return;
}


void pelea(){
    bool peleando = true;
    bool derecha = false;
    bool abajo = false;
    int px1 = 215;
    int px2 = 282;
    int py1 = 455;
    int py2 = 480;
    /**
    opciones [0] -> Atacar [x1 x2 y1 y2]
    opciones [1] -> Magia [x1 x2 y1 y2]
    opciones [2] -> Objetos [x1 x2 y1 y2]
    opciones [3] -> Huir [x1 x2 y1 y2]
    **/
    int opciones[4][4];

    opciones [0][0] = 215;
    opciones [0][1] = 285;
    opciones [0][2] = 455;
    opciones [0][3] = 480;

    opciones [1][0] = 515;
    opciones [1][1] = 575;
    opciones [1][2] = 510;
    opciones [1][3] = 535;
/*
    opciones [2][0] =
    opciones [2][1] =
    opciones [2][2] =
    opciones [2][3] =

    opciones [3][0] =
    opciones [3][1] =
    opciones [3][2] =
    opciones [3][3] =
*/
    BITMAP *fondo_pelea = create_bitmap(ancho,alto);
    SAMPLE *battle = load_sample("sound/battle.wav");
    //play_sample(battle,400,0,1000,1);
    while(peleando){
        estado(fondo_pelea);
        menu_pelea(fondo_pelea);
        rect(fondo_pelea,px1,py1,px2,py2,makecol(230,255,0));
        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);

        if(key[KEY_D]){
            if(!derecha){
                px1+=300;
                px2+=300;
                clear_bitmap(fondo_pelea);
                estado(fondo_pelea);
                menu_pelea(fondo_pelea);
                rect(fondo_pelea,px1,py1,px2,py2,makecol(230,255,0));
                blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
            }
            derecha = true;

        }
        if(key[KEY_A]){
            if(derecha){
                px1-=300;
                px2-=300;
                clear_bitmap(fondo_pelea);
                estado(fondo_pelea);
                menu_pelea(fondo_pelea);
                rect(fondo_pelea,px1,py1,px2,py2,makecol(230,255,0));
                blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
            }
            derecha = false;
        }
        if(key[KEY_S]){
            if(!abajo){
                py1+=55;
                py2+=55;
                clear_bitmap(fondo_pelea);
                estado(fondo_pelea);
                menu_pelea(fondo_pelea);
                rect(fondo_pelea,px1,py1,px2,py2,makecol(230,255,0));
                blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
            }
            abajo = true;
        }
        if(key[KEY_W]){
            if(abajo){
                py1-=55;
                py2-=55;
                clear_bitmap(fondo_pelea);
                estado(fondo_pelea);
                menu_pelea(fondo_pelea);
                rect(fondo_pelea,px1,py1,px2,py2,makecol(230,255,0));
                blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
            }
            abajo = false;
        }
        if(key[KEY_0]){
            peleando = false;
        }
        if(key[KEY_ENTER]){
            return;
        }
    }
//stop_sample(battle);
destroy_bitmap(fondo_pelea);
destroy_sample(battle);
}
