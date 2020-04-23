#ifndef C___LABS_4__5__6__VIRTUAL_FUNCTIONS_H
#define C___LABS_4__5__6__VIRTUAL_FUNCTIONS_H

#include <iostream>
#include <cmath>
using namespace std;

class Figure
{
public:
    virtual double get_area() = 0;
    virtual double get_perimeter() = 0;
};

class vector_2D
{
public:
    double x, y;

    vector_2D()
    {
        x = 0;
        y = 0;
    }

    vector_2D(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class fig_print
{
public:
    virtual void print() = 0;
};

class IPhysObject
{
public:
    virtual double  get_mass() = 0;
    virtual vector_2D get_position() = 0;
    virtual bool operator==(IPhysObject &x) = 0;
    virtual bool operator<(IPhysObject &x) = 0;
};

class IDialogInitiable
{
public:
    virtual void initFromDialog() = 0;
};

class IBaseObject {
public:
    virtual string get_name() = 0;
    virtual uint64_t get_size() = 0;
};

class all : public IDialogInitiable, public IPhysObject, public fig_print, public Figure, public IBaseObject {};

class hexagon : public all
{
private:
    const string name = "hexagon";
    double mass;
    vector_2D position;
    double side;

public:
    bool operator==(IPhysObject &x) override
    {
        return get_mass() == x.get_mass();
    }

    bool operator<(IPhysObject &x) override
    {
        return get_mass() < x.get_mass();
    }

    double get_area() override
    {
        return ((pow(this->side, 2) * 3 * sqrt(3)) / 2 );
    }

    double get_perimeter() override
    {
        return (this->side * 6);
    }

    double get_mass() override
    {
        return this->mass;
    }

    vector_2D get_position() override
    {
        return this->position;
    }

    string get_name() override
    {
        return this->name;
    }

    uint64_t get_size() override
    {
        return sizeof(*this);
    }

    void print() override
    {
        cout << "Name: " << this->name << endl << "side(a): " << this->side << endl;
        cout << "Mass: " << this->mass << endl << "size(in memory): " << get_size() << endl;
        cout << "X-position: " << this->position.x << "\tY-position: " << this->position.y << endl;
    }

    void initFromDialog() override
    {
        double a, _mass;
        vector_2D poss;

        cout << "Enter the side and mass of hexagon: " << endl;
        cin >> a >> _mass;
        this->side = a;
        this->mass = _mass;

        cout << "Enter the x and y position of hexagon: " << endl;
        cin >> poss.x >> poss.y;

        this->position.x = poss.x;
        this->position.y = poss.y;
    }

    hexagon(double &mass, double &side, vector_2D &poss)
    {
        this->mass = mass;
        this->side = side;
        this->position.x = poss.x;
        this->position.y = poss.y;
    }

    hexagon()
    {
        this->mass = 0;
        this->side = 0;
        this->position.x = 0;
        this->position.y = 0;
    }
};

class line_section : public all
{
private:
    const string name = "line_section";
    double mass;
    vector_2D position{};
    double side;

public:
    bool operator==(IPhysObject &x) override
    {
        return get_mass() == x.get_mass();
    }

    bool operator<(IPhysObject &x) override
    {
        return get_mass() < x.get_mass();
    }

    double get_area() override
    {
        return 0;
    }

    double get_perimeter() override
    {
        return side;
    }

    double get_mass() override
    {
        return this->mass;
    }

    vector_2D get_position() override
    {
        return this->position;
    }

    string get_name() override
    {
        return this->name;
    }

    uint64_t get_size() override
    {
        return sizeof(*this);
    }

    void print() override
    {
        cout << "Name: " << this->name << endl << "side(a): " << this->side << endl;
        cout << "Mass: " << this->mass << endl << "size(in memory): " << get_size() << endl;
        cout << "X-position: " << this->position.x << "\tY-position: " << this->position.y << endl;
    }

    void initFromDialog() override
    {
        double a, _mass;
        vector_2D poss;

        cout << "Enter the side and mass of line_section: " << endl;
        cin >> a >> _mass;
        this->side = a;
        this->mass = _mass;

        cout << "Enter the x and y position of line_section: " << endl;
        cin >> poss.x >> poss.y;

        this->position.x = poss.x;
        this->position.y = poss.y;
    }

    line_section(double &mass, double &side, vector_2D &poss)
    {
        this->mass = mass;
        this->side = side;
        this->position.x = poss.x;
        this->position.y = poss.y;
    }

    line_section()
    {
        this->mass = 0;
        this->side = 0;
        this->position.x = 0;
        this->position.y = 0;
    }
};

#endif //C___LABS_4__5__6__VIRTUAL_FUNCTIONS_H