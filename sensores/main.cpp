#include <iostream>
#include <string>
#include "Sistema.hpp"
#include "Sensor.hpp"

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    Sistema sistema;
    char comando;

    while (std::cin >> comando) {
        switch (comando) {
            case 's': {
                std::string nome, tipo;
                double valor;
                std::cin >> nome >> tipo >> valor;
                sistema.adicionar_sensor(nome, tipo, valor);
                break;
            }
            case 'u': {
                int id;
                double novo_valor;
                std::cin >> id >> novo_valor;
                break;
            }
            case 'r': {
                int id;
                std::cin >> id;
                sistema.remover_sensor(id);
                break;
            }
            case 'a': {
                std::string desc, tipo;
                double limiar;
                std::cin >> desc >> tipo >> limiar;
                break;
            }
            case 'l': {
                sistema.listar_sensores();
                break;
            }
            case 'c': {
                std::cout << "Total de sensores ativos: " << Sensor::get_total_ativos() << std::endl;
                break;
            }
            case 'v': {
                sistema.verificar_alertas();
                break;
            }
        }
    }

    Sensor::set_exibir_mensagens(false);

    return 0;
}