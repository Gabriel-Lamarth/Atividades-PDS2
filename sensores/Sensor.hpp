#include <string>

class Sensor {
private:
    int _id;
    std::string _nome;
    std::string _tipo;
    double _valor;

    static int _proximo_id;
    static int _total_ativos;
    static bool _exibir_mensagens;

public:
    Sensor(std::string nome, std::string tipo, double valor);
    ~Sensor();

    static void set_exibir_mensagens(bool valor);
    static int get_total_ativos();

    int get_id();
    std::string get_tipo();
    double get_valor();
    void set_valor(double v);
};