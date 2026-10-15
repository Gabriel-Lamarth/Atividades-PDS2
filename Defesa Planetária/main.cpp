#include <iostream>
#include "BaseMilitar.hpp"
#include "Canhao.hpp"
#include "CanhaoOrbital.hpp"
#include "LancadorMissil.hpp"

int main() {
    BaseMilitar base;
    char comando;

    while (std::cin >> comando && comando != 's') {
        if (comando == 'c') {
            int id;
            double energia, intensidade;
            std::cin >> id >> energia >> intensidade;
            base.adicionarDefesa(new Canhao(id, energia, intensidade));
        } else if (comando == 'o') {
            int id;
            double energia, intensidade, gravidade;
            std::cin >> id >> energia >> intensidade >> gravidade;
            base.adicionarDefesa(new CanhaoOrbital(id, energia, intensidade, gravidade));
        } else if (comando == 'm') {
            int id, misseis;
            double energia;
            std::cin >> id >> energia >> misseis;
            base.adicionarDefesa(new LancadorMissil(id, energia, misseis));
        } else if (comando == 'd') {
            double saudeInimigo;
            std::cin >> saudeInimigo;
            base.defender(saudeInimigo);
        }
    }

    return 0;
}