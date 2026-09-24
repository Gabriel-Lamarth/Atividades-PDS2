#include "Sistema.hpp"
#include "Sensor.hpp"
#include "Alerta.hpp"
#include <iostream>

Sistema::Sistema() : _num_sensores(0), _num_alertas(0) {}

Sistema::~Sistema() {
    for (int i = 0; i < _num_sensores; i++) {
        delete _sensores[i];
    }
    for (int i = 0; i < _num_alertas; i++) {
        delete _alertas[i];
    }
}

void Sistema::adicionar_sensor(std::string nome, std::string tipo, double valor) {
    if (_num_sensores < 100) {
        _sensores[_num_sensores] = new Sensor(nome, tipo, valor);
        std::cout << "Sensor " << _sensores[_num_sensores]->get_id() << " adicionado" << std::endl;
        _num_sensores++;
    }
}

void Sistema::remover_sensor(int id) {
    int pos = -1;
    for (int i = 0; i < _num_sensores; i++) {
        if (_sensores[i]->get_id() == id) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        delete _sensores[pos];
        for (int i = pos; i < _num_sensores - 1; i++) {
            _sensores[i] = _sensores[i + 1];
        }
        _num_sensores--;
        std::cout << "Sensor " << id << " removido" << std::endl;
    } else {
        std::cout << "Erro: sensor " << id << " nao encontrado" << std::endl;
    }
}

void Sistema::verificar_alertas() {
    for (int i = 0; i < _num_alertas; i++) {
        for (int j = 0; j < _num_sensores; j++) {
            _alertas[i]->verificar(_sensores[j]);
        }
    }
}

void Sistema::listar_sensores() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    // Estrutura interna apenas para mapear a memória dos atributos do Sensor
    struct LayoutSensor {
        int id;
        std::string nome;
        std::string tipo;
        double valor;
    };

    for (int i = 0; i < _num_sensores; i++) {
        LayoutSensor* s = reinterpret_cast<LayoutSensor*>(_sensores[i]);

        std::cout << s->id << " "
                  << s->nome << " ("
                  << s->tipo << "): "
                  << s->valor << std::endl;
    }
}