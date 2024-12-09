#pragma once
#ifndef __CARTAS_H
#define __CARTAS_H

#include <vector>
#include <tuple>
#include <string>
#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

using namespace std;

class Cartas {
public:
    // Método estático para obtener la instancia única de Cartas
    static Cartas& getInstance();

    // Agregar una carta a la colección
    void agregarCarta(const tuple<string, int, int, int, int, int, int,
        string, string, string, int,
        string, int, int, int, string, int>& carta);

    // Obtener todas las cartas
    const vector<tuple<string, int, int, int, int, int, int,
        string, string, string, int,
        string, int, int, int, string, int>>&
        getCartas() const;

private:
    // Constructor privado para el patrón Singleton
    Cartas() = default;

    // Vector que almacena las cartas obtenidas
    vector<tuple<string, int, int, int, int, int, int,
        string, string, string, int,
        string, int, int, int, string, int>> cartas;
};

#endif // __CARTAS_H
