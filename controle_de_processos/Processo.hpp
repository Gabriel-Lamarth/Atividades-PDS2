#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <string>

class Processo {
private:
    int _id;
    int _prioridade;
    std::string _nome;
    Processo* _proximo; 

public:
    Processo(int id, std::string nome, int prioridade);
    
    int getID();
    int getPrioridade();
    std::string getNome();
    
    // Métodos auxiliares para a lista encadeada
    void setProx(Processo* prox);
    Processo* getProx();
    
    double tempo_reservado_processo();
    void imprimir_dados();
};

#endif
