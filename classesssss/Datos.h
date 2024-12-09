#pragma once
#ifndef DATOS_H
#define DATOS_H
#include <vector>
#include <tuple>
#include <string>


using namespace std;

class DatosGlobales {
public:
    static vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> alineacionUsuario;
    static vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> alineacionIA;

    static void limpiarAlineacion() {
        alineacionUsuario.clear();
    }
};

#endif // DATOS_H