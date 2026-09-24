#include "Sensor.hpp" 
#include <iostream>

int Sensor::_proximo_id = 1;
int Sensor::_total_ativos = 0;
bool Sensor::_exibir_mensagens = true;

Sensor::Sensor(std::string nome, std::string tipo, double valor) 
    : _nome(nome), _tipo(tipo), _valor(valor) {
    _id = _proximo_id++;
    _total_ativos++;
}

Sensor::~Sensor() {
    _total_ativos--;
    if (_exibir_mensagens) {
        std::cout << "Sensor " << _id << " desativado" << std::endl;
    }
}

void Sensor::set_exibir_mensagens(bool valor) {
    _exibir_mensagens = valor;
}