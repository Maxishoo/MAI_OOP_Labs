#pragma once
#include <iostream>
#include "cmath"

class Figure
{
public:
    Figure();
    Figure(const Figure &other);
    Figure(const std::pair<double, double> *arr);
    ~Figure();

    virtual explicit operator double();             // площадь
    virtual std::pair<double, double> geomcenter(); // геом центр

    bool operator==(const Figure &right) const;
    Figure &operator=(const Figure &right_operand);
    Figure &operator=(Figure &&right_operand);

protected:
    std::pair<double, double> *points;
    int cnt_vertex = 4;

    double pt_dist(std::pair<double, double> &p1, std::pair<double, double> &p2);

    friend std::ostream &operator<<(std::ostream &os, Figure &f);
    friend std::istream &operator>>(std::istream &is, Figure &f);
};

std::ostream &operator<<(std::ostream &os, Figure &f);

std::istream &operator>>(std::istream &is, Figure &f);