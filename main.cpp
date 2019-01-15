#include <allegro.h>
#include <iostream>
#include "clases.h"

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
	SAMPLE *soundtrack = load_wav("sound/soundtrack.wav");

    int pausa = 0;
    int x = 0;
    int y = 0;
    bool iniciar = false;
    bool elegido = false;
    bool gameover = false;

    /** Pantalla de inicio **/
    while ( !key[KEY_ESC] ){
        clear_to_color(buffer, 0x333333);
        rectfill(buffer, 30, 30, ancho-30, alto-30, makecol(0,0,0));
        textout_centre_ex(buffer, font, "ESC para Salir", ancho/2, 10, 0xFFFFFF,000000);
        while(!iniciar){
            textout_centre(buffer, font, "-Nombre del juego-", ancho/2,200,0xFFFFFF);
            textout_centre(buffer, font, "Presiona espacio para activar/desactivar el sonido", ancho/2,alto/2+20,0xFFFFFF);
            textout_centre(buffer, font, "Presiona p para iniciar el juego", ancho/2,alto/2+50,0xFFFFFF);
            textout_centre(buffer, font, "Creado por Maxo", ancho-100,alto-10,0xFFFFFF);
            blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
            if(key[KEY_SPACE]){
                play_sample(soundtrack,255,0,1000,1);
            }
            if(key[KEY_P]){
               iniciar= true;
           }
           if(key[KEY_ESC]){
                return 0;
           }
        }
        clear_bitmap(buffer);

        /** Pantalla del juego **/
        textout_centre_ex(fondo, font, "ESC para Salir", ancho/2, 10, 0xFFFFFF,000000);
        blit(fondo,screen,0,0,0,0,ancho,alto);

        if(key[KEY_1]){
            gameover = true;
        }
        /**

        if(key[KEY_SPACE]){
             play_sample(soundtrack,255,0,990,1);
        }
        if(key[KEY_W] && y > -20){
            y--;
        }
        if(key[KEY_S] && y < alto-274){
            y++;
        }
        if(key[KEY_A] && x >= 0){
            x--;
        }
        if(key[KEY_D] && x < ancho){
            x++;
        }
        draw_sprite(screen,dado,650,150);
        **/

        rest(20);
        /**Creditos **/
        if(gameover){
            play_midi(africa,0);
            clear_bitmap(buffer);
            blit(buffer,screen,0,0,0,0,ancho,alto);
        }
    }
destroy_bitmap(fondo);
destroy_bitmap(dado);
destroy_sample(soundtrack);
return 0;
}
END_OF_MAIN();
