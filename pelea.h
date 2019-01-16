#include <allegro.h>
#define ancho 800
#define alto 600
using namespace std;

void pelea(){
    bool peleando = true;
    BITMAP *fondo_pelea = create_bitmap(ancho,alto);
    SAMPLE *battle = load_sample("sound/battle.wav");
    //play_sample(battle,400,0,1000,1);
    while(peleando){
        hline(fondo_pelea,ancho,alto-210,0,makecol(255,255,255));
        textout_centre(fondo_pelea,font,"En pelea",ancho/2,alto-200,makecol(255,255,255));
        hline(fondo_pelea,ancho,420,0,makecol(255,255,255));
        blit(fondo_pelea,screen,0,0,0,0,ancho,alto);

        if(key[KEY_0]){
            peleando = false;
        }
    }
//stop_sample(battle);
destroy_bitmap(fondo_pelea);
destroy_sample(battle);
}
