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
        int calculaAtaque(Personaje& objetivo);
        void recibeAtaque(int ptosAtaque);
        void atacar(Personaje& objetivo);
        void imprimir();

    private:
        int vida;
        int salud;
        int nivel;
        int ataque;
};
