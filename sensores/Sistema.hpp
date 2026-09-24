#include <string>

class Sensor;
class Alerta;

class Sistema {
private:
    Sensor* _sensores[100];
    Alerta* _alertas[100];
    int _num_sensores;
    int _num_alertas;

public:
    Sistema();
    ~Sistema();
    void adicionar_sensor(std::string nome, std::string tipo, double valor);
    void remover_sensor(int id);
    void verificar_alertas();
    void listar_sensores(); // unico metodo adicionado
};