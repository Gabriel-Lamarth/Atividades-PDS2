#pragma once
#include <string>

class Sensor;

class Alerta {
    private:
        std::string _descricao;
        std::string _tipo_sensor;
        double _limiar;
    
    public:
        Alerta(std::string desc, std::string tipo, double limiar);
        bool verificar(Sensor* s);
};