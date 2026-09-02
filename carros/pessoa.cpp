#include "Pessoa.hpp"

Pessoa::Pessoa(double x, double y) {
    this->x = x;
    this->y = y;
}

double Pessoa::getX() {
    return x;
}

double Pessoa::getY() {
    return y;
}

void Pessoa::mover(double dx, double dy) {
    x += dx;
    y += dy;
}
