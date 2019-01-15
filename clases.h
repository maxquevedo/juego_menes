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

/**
class maxo : public personaje{

};

class nico : public personaje(){
};

class franco : public personaje(){
};

class ramon : public personaje(){
};

class salva : public personaje(){
};

class axel : public personaje(){
};

class tula : public personaje(){
};

class gustav: public personaje(){
};
**/
