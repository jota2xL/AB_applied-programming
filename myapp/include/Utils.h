#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <regex>

bool validarFecha(const std::string& fecha) {
    std::regex formatoFecha("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(fecha, formatoFecha);
}

#endif