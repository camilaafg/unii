#pragma once
#ifndef JUGADORES_H
#define JUGADORES_H
#include <map>
#include <tuple>
#include <string>

class JugadoresGlobales {
public:
    static std::multimap<std::string, std::tuple<
        std::string, int, int, int, int, int, int, std::string,
        std::string, std::string, int, std::string, int, int, int,
        std::string, int>> jugadores;
};


#endif // JUGADORES_H