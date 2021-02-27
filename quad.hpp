#ifndef QUAD_HPP
#define QUAD_HPP

#include "figure.hpp"

const unsigned int QUAD_TYPE_ID = 1;

template <class T>
class TQuad : public IFigure {
private:
    std::pair<T, T> Cords;
    T Side;
public:
    TQuad() : Cords(), Side() {}
    TQuad(const std::pair<T, T> & xy, const T & l) : Cords(xy), Side(l) {}

    void Write(FILE* out) override {
        fwrite(&QUAD_TYPE_ID, sizeof(unsigned int), 1, out);
        fwrite(&Cords.first, sizeof(T), 1, out);
        fwrite(&Cords.second, sizeof(T), 1, out);
        fwrite(&Side, sizeof(T), 1, out);
    }

    void Print(std::ostream & of) override {
        of << *this;
    }

    template <class U>
    friend std::ostream & operator << (std::ostream & of, const TQuad<U> & q) {
        of << "Quadrate {";
        of << std::pair<U, U>(q.Cords.first, q.Cords.second) << ", ";
        of << std::pair<U, U>(q.Cords.first, q.Cords.second + q.Side) << ", ";
		of << std::pair<U, U>(q.Cords.first + q.Side, q.Cords.second + q.Side) << ", ";
		of << std::pair<U, U>(q.Cords.first + q.Side, q.Cords.second);
		of << "}";
		return of;
    }

};


#endif
