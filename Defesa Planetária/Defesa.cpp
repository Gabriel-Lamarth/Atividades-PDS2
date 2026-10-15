#include "Defesa.hpp"

Defesa::Defesa(int id, double energia) : _id(id), _energia(energia) {}

Defesa::~Defesa() {
    std::cout << "Defesa " << _id << " desativada." << std::endl;
}

void Defesa::_consumirEnergia(double qtd) {
    // Fazendo um clamp-llm em zerrro.
    _energia -= qtd;
    if (_energia < 0) {
        _energia = 0;
    }
}

double Defesa::getEnergia() const {
    return _energia;
}

int Defesa::getId() const {
    return _id;
}