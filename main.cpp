#include <allegro.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "clases.h"
#include "pelea.h"
#include "historia.h"
#define ancho 800
#define alto 600
using namespace std;

int main(){
     allegro_init();

    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

    set_window_title("Jueguito");
    set_volume(230, 200);
    set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);

    BITMAP *buffer = create_bitmap(ancho, alto);
    BITMAP *fondo = load_bitmap("img/fondo_01.bmp",NULL);
    BITMAP *dado = load_bitmap("img/dado.bmp",NULL);
	MIDI *africa = load_midi("sound/Africa.mid");
	SAMPLE *battle = load_wav("sound/battle.wav");
	SAMPLE *soundtrack = load_wav("sound/soundtrack.wav");

    int pausa = 0;
    int x = 0;
    int y = 0;
    bool iniciar = false;
    bool elegido = false;
    bool gameover = false;
    bool musica = false;

    /** Pantalla de inicio **/
    while ( !key[KEY_ESC] ){
        clear_to_color(buffer, 0x333333);
        rectfill(buffer, 30, 30, ancho-30, alto-30, makecol(0,0,0));
        textout_centre_ex(buffer, font, "ESC para Salir", ancho/2, 10, 0xFFFFFF,000000);
          //prueba de pelea
          //pelea();
        while(!iniciar){
            textout_centre(buffer, font, "-Nombre del juego-", ancho/2,200,0xFFFFFF);
            textout_centre(buffer, font, "Presiona espacio para activar/desactivar el sonido", ancho/2,alto/2+20,0xFFFFFF);
            textout_centre(buffer, font, "Presiona p para iniciar el juego", ancho/2,alto/2+50,0xFFFFFF);
            textout_centre(buffer, font, "Creado por Maxo", ancho-100,alto-10,0xFFFFFF);
            blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
            if(key[KEY_SPACE]){
                musica = (!musica);
                if(!musica){
                    play_sample(soundtrack,255,0,1000,1);

                }else{
                    stop_sample(soundtrack);
                }
            }
            if(key[KEY_P]){
                prologo(buffer,"Max");
                iniciar= true;
           }
           if(key[KEY_ESC]){
                return 0;
           }
        }
        clear_bitmap(buffer);

        /** Pantalla del juego **/
        //prologo(buffer);
        textout_centre_ex(fondo, font, "ESC para Salir", ancho/2, 10, 0xFFFFFF,000000);
        blit(fondo,screen,0,0,0,0,ancho,alto);

        if(key[KEY_1]){
            stop_sample(soundtrack);
            pelea();
        }

        rest(20);
        /**Creditos **/
        if(gameover){
            play_midi(africa,0);
            clear_bitmap(buffer);
            blit(buffer,screen,0,0,0,0,ancho,alto);
            break;
        }
    }
destroy_bitmap(fondo);
destroy_bitmap(dado);
destroy_sample(soundtrack);
return 0;
}
END_OF_MAIN();
