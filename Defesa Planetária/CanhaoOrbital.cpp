#include "CanhaoOrbital.hpp"
#include <iostream>

CanhaoOrbital::CanhaoOrbital(int id, double energia, double intensidade, double multiplicador)
    : Canhao(id, energia, intensidade), _multiplicadorGravitacional(multiplicador) {}

void CanhaoOrbital::atacar(double &danoAcumulado) {
    if (getEnergia() >= 10.0) {
        double danoBase = 0.0;
        Canhao::atacar(danoBase);
        danoAcumulado += (danoBase * _multiplicadorGravitacional);
        std::cout << "Ataque Orbital realizado!" << std::endl;
    }
}