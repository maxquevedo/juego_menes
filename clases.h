#include <string.h>
using namespace std;

class personaje {
public:
    int pdv; /** Puntos de vida **/
    int pdm; /** Puntos de mana**/
    int magia; /** Poder de magia **/
    int suerte; /** Influye en tiradas **/
    int fuerza; /** Golpes fisicos **/
    int res_fis; /** Resistencia a fisica **/
    int res_mag; /** Resistencia magica **/
    int velocidad; /** Quien parte **/
     string nombre;

  personaje(){
      nombre = "kleta";
      pdv = 10;
      pdm = 10;
      magia = 1;
      suerte = 1;
      fuerza = 1;
      res_fis = 0;
      res_mag = 0;
      velocidad = 1;
  }
};


class maxo : public personaje{
public:
    maxo(){

    }
};

class nico : public personaje{
public:
    nico(){
    }
};

class franco : public personaje{
public:
    franco(){
    }
};

class ramon : public personaje{
public:
    ramon(){
    }
};

class salva : public personaje{
public:
    salva(){
    }
};

class axel : public personaje{
public:
    axel(){
    }
};

class tula : public personaje{
public:
    tula(){
    }
};

class gustav: public personaje{
public:
    gustav(){
    }
};

