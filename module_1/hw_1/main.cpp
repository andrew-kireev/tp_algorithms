//
// Created by Andrew Kireev on 11.10.2020.
//

//Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин. Вначале вводится количество вершин,
//затем последовательно целочисленные координаты всех вершин в порядке обхода против часовой стрелки.
//n < 1000, координаты < 10000.


#include <iostream>

struct Point {
    double x, y;
};

double calculate_square(const Point *points, int size) {
    double square = 0;

    for (int i = 0; i != size - 1; ++i) {
        square += 0.5 * (points[i].x - points[i + 1].x) * (points[i].y + points[i + 1].y);
    }
    square += 0.5 * (points[size - 1].x - points[0].x) * (points[size - 1].y + points[0].y);
    return std::abs(square);
}

int main(int argc, char **argv) {
    int n;

    std::cin >> n;

    Point *coordinates = new Point[n];
    for (int i = 0; i != n; ++i) {
        std::cin >> coordinates[i].x;
        std::cin >> coordinates[i].y;
    }
    std::cout << calculate_square(coordinates, n);
    delete [] coordinates;
    return 0;
}