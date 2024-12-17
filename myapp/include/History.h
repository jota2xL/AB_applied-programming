#ifndef HISTORY_H
#define HISTORY_H

#include <string>

class History {
public:
    std::string fecha;
    std::string diagnostico;
    std::string tratamiento;

    History(std::string f, std::string d, std::string t) : fecha(f), diagnostico(d), tratamiento(t) {}
};

#endif
