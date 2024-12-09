#include "Cartas.h"
#include "ui/CocosGUI.h"

using namespace std;

USING_NS_CC;


Cartas& Cartas::getInstance() {
    static Cartas instance;
    return instance;
}

void Cartas::agregarCarta(const tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>& carta) {
    cartas.push_back(carta);
}

const vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>>&
    Cartas::getCartas() const {
    return cartas;
}
