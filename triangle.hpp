#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"
#include <cmath>

const unsigned int TRIANGLE_TYPE_ID = 3;

template <class T>
class TTriangle : public IFigure {
private:
    std::pair<T, T> Cords;
    T Side;
public:
    TTriangle() : Cords(), Side() {}
    TTriangle(const std::pair<T, T> & xy, const T & l) : Cords(xy), Side(l) {}

    void Write(FILE* out) override {
        fwrite(&TRIANGLE_TYPE_ID, sizeof(unsigned int), 1, out);
        fwrite(&Cords.first, sizeof(T), 1, out);
        fwrite(&Cords.second, sizeof(T), 1, out);
        fwrite(&Side, sizeof(T), 1, out);
    }

    void Print(std::ostream & of) override {
        of << *this;
    }

    template <class U>
    friend std::ostream & operator << (std::ostream & of, const TTriangle<U> & tri) {
        of << "Triangle {";
        of << std::pair<T, T>(tri.Cords.first, tri.Cords.second) << ", ";
    	of << std::pair<T, T>(tri.Cords.first + 0.5 * tri.Side, tri.Cords.second + tri.Side * (std::pow(3, 0.5) / 2)) << ", ";
    	of << std::pair<T, T>(tri.Cords.first + tri.Side, tri.Cords.second);
    	of << "}";
		return of;
    }

};


#endif
