#include <allegro.h>
#define ancho 800
#define alto 600
using namespace std;

void estado(BITMAP*fondo_pelea,char* estadox){
    hline(fondo_pelea,ancho,alto-210,0,makecol(255,255,255));
    textout_centre(fondo_pelea,font,estadox,ancho/2,alto-200,makecol(255,255,255));
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

void menu_generico(BITMAP*fondo_pelea,char*uno,char*dos,char*tres,char*cuatro){
    clear_bitmap(fondo_pelea);
    textout_centre(fondo_pelea,font,uno,250,465,makecol(255,255,255));
    textout_centre(fondo_pelea,font,dos,550,465,makecol(255,255,255));
    textout_centre(fondo_pelea,font,tres,550,520,makecol(255,255,255));
    textout_centre(fondo_pelea,font,cuatro,250,520,makecol(255,255,255));

return;
}

void menu_moverse(bool &derecha,bool &abajo,int &px1,int &px2,int &py1, int &py2,int &pos){
    if(!abajo && !derecha){
        pos = 0;
    }
    if(!abajo && derecha){
        pos = 1;
    }
    if(abajo && !derecha){
        pos = 2;
    }
    if(abajo && derecha){
        pos = 3;
    }
    if(key[KEY_D]){
        if(!derecha){
            px1+=300;
            px2+=300;
        }
        derecha = true;
    }
    if(key[KEY_A]){
        if(derecha){
            px1-=300;
            px2-=300;
        }
        derecha = false;
    }
    if(key[KEY_S]){
        if(!abajo){
            py1+=55;
            py2+=55;
        }
        abajo = true;
    }
    if(key[KEY_W]){
        if(abajo){
            py1-=55;
            py2-=55;
        }
        abajo = false;
    }
    if(key[KEY_ENTER]){
        return;
    }
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
    int pos = 0;
    /**
    opciones [0] -> Atacar [x1 x2 y1 y2]
    opciones [1] -> Magia [x1 x2 y1 y2]
    opciones [2] -> Objetos [x1 x2 y1 y2]
    opciones [3] -> Huir [x1 x2 y1 y2]
    **/
    int opciones[4][4];

    /**  Pelea   **/
    opciones [0][0] = 215;
    opciones [0][1] = 285;
    opciones [0][2] = 455;
    opciones [0][3] = 480;

    opciones [1][0] = 515;
    opciones [1][1] = 575;
    opciones [1][2] = 455;
    opciones [1][3] = 480;

    opciones [2][0] = 215;
    opciones [2][1] = 285;
    opciones [2][2] = 510;
    opciones [2][3] = 535;

    opciones [3][0] = 515;
    opciones [3][1] = 575;
    opciones [3][2] = 510;
    opciones [3][3] = 535;

    BITMAP *fondo_pelea = create_bitmap(ancho,alto);
    SAMPLE *battle = load_sample("sound/battle.wav");
    //play_sample(battle,400,0,1000,1);
    while(peleando){
        estado(fondo_pelea,"En pelea");
        menu_pelea(fondo_pelea);
        rect(fondo_pelea,px1,py1,px2,py2,makecol(230,255,0));
        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
        while(!key[KEY_ESC]){
            menu_moverse(derecha,abajo,px1,px2,py1,py2,pos);
            clear_bitmap(fondo_pelea);
            estado(fondo_pelea,"En pelea");
            menu_pelea(fondo_pelea);
            rect(fondo_pelea,opciones[pos][0],opciones[pos][2],opciones[pos][1],opciones[pos][3],makecol(230,255,0));
            blit(fondo_pelea,screen,0,0,0,0,ancho,alto);

            if(key[KEY_ENTER]){
                switch(pos){
                case 0:
                    while(!key[KEY_ESC]){
                        clear_bitmap(fondo_pelea);
                        menu_generico(fondo_pelea,"Golpe simple","Golpe doble","Golpe triple","Golpe cuadruple");
                        estado(fondo_pelea,"Ataques");
                        menu_moverse(derecha,abajo,px1,px2,py1,py2,pos);
                        rect(fondo_pelea,opciones[pos][0]-25,opciones[pos][2],opciones[pos][1]+25,opciones[pos][3]+5,makecol(230,255,0));
                        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
                    }
                    break;
                case 1:
                    while(!key[KEY_ESC]){
                        clear_bitmap(fondo_pelea);
                        menu_pelea(fondo_pelea);
                        estado(fondo_pelea,"Magia");
                        rect(fondo_pelea,opciones[pos][0],opciones[pos][2],opciones[pos][1],opciones[pos][3],makecol(230,255,0));
                        menu_moverse(derecha,abajo,px1,px2,py1,py2,pos);
                        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);

                    }
                    break;
                case 2:
                    while(!key[KEY_ESC]){
                        clear_bitmap(fondo_pelea);
                        estado(fondo_pelea,"Objetos");
                        menu_pelea(fondo_pelea);
                        rect(fondo_pelea,opciones[pos][0],opciones[pos][2],opciones[pos][1],opciones[pos][3],makecol(230,255,0));
                        menu_moverse(derecha,abajo,px1,px2,py1,py2,pos);
                        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
                    }
                    break;
                case 3:
                    while(!key[KEY_ESC]){
                        clear_bitmap(fondo_pelea);
                        estado(fondo_pelea,"Huir");
                        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);
                    }
                    break;
                default:
                    break;
                }
               peleando = false;
            }
        }
    //stop_sample(battle);
    destroy_bitmap(fondo_pelea);
    destroy_sample(battle);
    }
}
