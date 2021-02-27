#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>

#include "rectangle.hpp"
#include "quad.hpp"
#include "triangle.hpp"

template <class T, class FIGURE>
class TFactory;

template <class T>
class TFactory< T, TQuad<T> > {
public:
    static std::shared_ptr<IFigure> CreateFigure() {
        std::pair<T, T> curCords;
        T curSide;
        std::cout << "Input quadrate as follows: x y a" << std::endl;
		std::cout << "x, y is a left bottom corner cords" << std::endl;
		std::cout << "a is square side" << std::endl;
		std::cin >> curCords.first >> curCords.second >> curSide;
        TQuad<T>* q = new TQuad<T>(curCords, curSide);
        return std::shared_ptr<IFigure>(q);
    }

    static std::shared_ptr<IFigure> Read(FILE* in) {
        std::pair<T, T> curCords;
        T curSide;
        fread(&curCords.first, sizeof(T), 1, in);
		fread(&curCords.second, sizeof(T), 1, in);
		fread(&curSide, sizeof(T), 1, in);
		TQuad<T>* q = new TQuad<T>(curCords, curSide);
		return std::shared_ptr<IFigure>(q);
    }
};

template <class T>
class TFactory< T, TRectangle<T> > {
public:
    static std::shared_ptr<IFigure> CreateFigure() {
        std::pair<T, T> curCords;
		T curHeight, curWidth;
		std::cout << "Input rectangle as follows: x y a b" << std::endl;
		std::cout << "x, y is a left bottom corner cords" << std::endl;
		std::cout << "a and b are width and heigth" << std::endl;
		std::cin >> curCords.first >> curCords.second >> curHeight >> curWidth;
		TRectangle<T>* rect = new TRectangle<T>(curCords, curHeight, curWidth);
		return std::shared_ptr<IFigure>(rect);
    }

    static std::shared_ptr<IFigure> Read(FILE* in) {
		std::pair<T, T> curCords;
		T curHeight, curWidth;
		fread(&curCords.first, sizeof(T), 1, in);
		fread(&curCords.second, sizeof(T), 1, in);
		fread(&curHeight, sizeof(T), 1, in);
		fread(&curWidth, sizeof(T), 1, in);
		TRectangle<T>* rect = new TRectangle<T>(curCords, curHeight, curWidth);
		return std::shared_ptr<IFigure>(rect);
	}
};

template <class T>
class TFactory< T, TTriangle<T> > {
public:
    static std::shared_ptr<IFigure> CreateFigure() {
		std::pair<T, T> curCords;
		T curSide;
		std::cout << "Input triangle as follows: x y a" << std::endl;
		std::cout << "x, y is a left bottom corner cords" << std::endl;
		std::cout << "a is side of triangle" << std::endl;
		std::cin >> curCords.first >> curCords.second >> curSide;
		TTriangle<T>* tri = new TTriangle<T>(curCords, curSide);
		return std::shared_ptr<IFigure>(tri);
	}

    static std::shared_ptr<IFigure> Read(FILE* in) {
		std::pair<T, T> curCords;
		T curSide;
		fread(&curCords.first, sizeof(T), 1, in);
		fread(&curCords.second, sizeof(T), 1, in);
		fread(&curSide, sizeof(T), 1, in);
		TTriangle<T>* tri = new TTriangle<T>(curCords, curSide);
		return std::shared_ptr<IFigure>(tri);
	}
};

#endif
