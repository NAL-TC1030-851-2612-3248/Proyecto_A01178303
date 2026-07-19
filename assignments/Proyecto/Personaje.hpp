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
        virtual int calculaAtaque(Personaje& objetivo);
        virtual void recibeAtaque(int ptosAtaque);
        void atacar(Personaje& objetivo);
        void recibeCurar(int pntosCurar);
        virtual void revive(int) = 0;
        virtual void imprimir();

    private:
        int vida;
        int salud;
        int nivel;
        int ataque;
};
