#include "BaseMilitar.hpp"
#include <iostream>

BaseMilitar::BaseMilitar() : _qtdAtual(0) {
    for (int i = 0; i < 100; ++i) {
        _defesas[i] = nullptr;
    }
}

BaseMilitar::~BaseMilitar() {
    for (int i = 0; i < _qtdAtual; ++i) {
        delete _defesas[i];
    }
}

void BaseMilitar::adicionarDefesa(Defesa* d) {
    if (_qtdAtual < 100) {
        _defesas[_qtdAtual++] = d;
    }
}

void BaseMilitar::defender(double &saudeInimigo) {
    double danoTotalTurno = 0.0;

    for (int i = 0; i < _qtdAtual; ++i) {
        _defesas[i]->atacar(danoTotalTurno);
    }

    saudeInimigo -= danoTotalTurno;

    // Formatação com 2 casas decimais sem usar <iomanip>
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout << "Saude Inimigo: " << saudeInimigo << std::endl;
}