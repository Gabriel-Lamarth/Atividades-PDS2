#include "Carro.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

Carro::Carro(double x, double y, double th) {
    this->x = x;
    this->y = y;
    this->th = th;
}

double Carro::getX() {
    return x;
}

double Carro::getY() {
    return y;
}

double Carro::getTH() {
    return th;
}

// Garante que o angulo fique no intervalo [-PI, PI]
double Carro::normalizar_angulo(double angulo) {
    while (angulo > M_PI) angulo -= 2.0 * M_PI;
    while (angulo < -M_PI) angulo += 2.0 * M_PI;
    return angulo;
}

void Carro::girar(double w, double t) {
    th += w * t;
    th = normalizar_angulo(th);
}

void Carro::mover(double v, double t) {
    double d = v * t;
    x += d * std::cos(th);
    y += d * std::sin(th);
}

// Retorna o angulo em radianos relativo a orientacao do carro
double Carro::calcular_angulo_pessoa(Pessoa* pessoa) {
    double dx = pessoa->getX() - x;
    double dy = pessoa->getY() - y;
    
    // Angulo do vetor diferenca relativo ao eixo X global
    double angulo_global = std::atan2(dy, dx);
    
    // Angulo relativo a orientacao do carro
    double angulo_relativo = angulo_global - th;
    
    return normalizar_angulo(angulo_relativo);
}

double Carro::calcular_distancia_pessoa(Pessoa* pessoa) {
    double dx = pessoa->getX() - x;
    double dy = pessoa->getY() - y;
    return std::sqrt(dx * dx + dy * dy);
}

bool Carro::movimentacao_permitida(Pessoa** pessoas, int n) {
    bool permitido = true;

    // Converte os limites de angulo de graus para radianos
    double limite_min_rad = -45.0 * (M_PI / 180.0);
    double limite_max_rad = 45.0 * (M_PI / 180.0);

    for (int i = 0; i < n; i++) {
        double dist = calcular_distancia_pessoa(pessoas[i]);
        double ang_rad = calcular_angulo_pessoa(pessoas[i]);

        // Verifica se esta dentro do campo de visao ([-45, +45] graus) e a menos de 5m
        if (ang_rad >= limite_min_rad && ang_rad <= limite_max_rad && dist < 5.0) {
            permitido = false;

            // Converte o angulo para graus para a impressao de alerta
            double ang_deg = ang_rad * (180.0 / M_PI);

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Alerta!\t" << i << "\t" << ang_deg << "\t" << dist << "\n";
        }
    }

    return permitido;
}

void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t) {
    // (i) Verifica presença de pedestres
    if (!movimentacao_permitida(pessoas, n)) {
        return;
    }

    // (ii) Realiza o giro
    girar(w, t);

    // (iii) Move para frente
    mover(v, t);
}
