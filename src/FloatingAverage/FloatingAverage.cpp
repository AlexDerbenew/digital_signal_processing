//
// Created by inverse on 08.12.2019.
//
#include "../../include/FloatingAverage/FloatingAverage.h"
#include <iostream>

FloatingAverage::FloatingAverage(GRAPH points) {
    _points = points;
}

FloatingAverage::~FloatingAverage() {

}

//реализация из интернета, особо не нужна, но пусть будет
/*void FloatingAverage::getMA(double **x, int n, int size) {
// Вычисление результата скользящего среднего
    // size - количество отсчетов интервала усреднения
    double d = 0; // сумма отсчетов на интервале
    double *mas; // массив для хранения size отсчетов
    int index = 0; // индекс элемента массива
    mas = new double[size];
    for (int i = 0; i<size; i++) mas[i] = 0;
    for (int i = 0; i<n; i++) {
        d -= mas[index];
        mas[index] = x[1][i];
        d += mas[index];
        index++;
        if (index >= size)
            index = 0; // возврат к началу "окна"
        x[2][i] = d / size;
    }
}*/

void FloatingAverage::setWindowSize(int ws) {
    _windowSize = ws;
}

void FloatingAverage::exec() {
    double average;
    int i,j;
    for(i = 0; i < _points.size() - _windowSize; i++) {
        average = 0;
        for(j = 0; j < _windowSize; j++) {
            average += _points[i+j].y;
        }
        average = average/(j+1);
        _points[i].y = average;
        std::cout << _points[i].y << std::endl;
    }
}