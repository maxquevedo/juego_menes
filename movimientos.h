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
