// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
class Personaje{
    public:
        Personaje();
        Personaje(int, int, int, int);
        int getVida() const;
        int getSalud() const;
        int getNivel() const;
        int getAtaque() const;
        void setVida(int v);
        void setSalud(int s);
        void setNivel(int n);
        void setAtaque(int a);
        int porcentajeSalud();
        void imprimeBarra()const;





    private:
        int vida;
        int salud;
        int nivel;
        int ataque;
};