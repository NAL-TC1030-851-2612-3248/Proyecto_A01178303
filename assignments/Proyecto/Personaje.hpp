#pragma once
class Personaje{
    public:
        Personaje();
        Personaje(int, int, int, int);
        int getVida() const;
        int getSalud() const;
        int getNivel() const;
        int getAtaque() const;
        void setVida(int vida_);
        void setSalud(int salud_);
        void setNivel(int nivel_);
        void setAtaque(int ataque_);
        int porcentajeSalud();
        void imprimeBarra()const;
        int calculaAtaque(Personaje& objetivo);
        void recibeAtaque(int ptosAtaque);
        void atacar(Personaje& objetivo);
        void recibeCurar(int pntosCurar);
        void imprimir();

    private:
        int vida;
        int salud;
        int nivel;
        int ataque;
};
