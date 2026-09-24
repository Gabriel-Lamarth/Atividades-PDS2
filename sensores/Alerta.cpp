#include "Alerta.hpp"
#include "Sensor.hpp"
#include <iostream>

Alerta::Alerta(std::string desc, std::string tipo, double limiar)
    : _descricao(desc), _tipo_sensor(tipo), _limiar(limiar) {}

bool Alerta::verificar(Sensor* s) {
    if (s != nullptr && s->get_tipo() == _tipo_sensor && s->get_valor() > _limiar) {
        std::cout << "ALERTA: " << _descricao << std::endl;
        return true;
    }
    return false;
}