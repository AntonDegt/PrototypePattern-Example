#include <iostream>
using namespace std;

class Figure //abstract
{
protected:
    float x;
    float y;

public:
    Figure(float x, float y)
        : x{ x }, y{ y } {}

    void SetX(float x) { this->x = x; }
    float GetX() { return x; }
    void SetY(float y) { this->y = y; }
    float GetY() { return y; }

    virtual float GetPerimeter() = 0;
    virtual float GetSquare() = 0;

    virtual Figure* copy() = 0;
};


class Circle : public Figure
{
protected:
    float r;

public:
    Circle(float x, float y, float r)
        : Figure(x, y), r{ r } {}

    void SetR(float r) { this->r = r; }
    float GetR() { return r; }

    virtual float GetPerimeter() override { return 2 * r * 3.1415; }
    virtual float GetSquare() override { return r * r * 3.1415; }

    Figure* copy() override
    {
        return new Circle(x, y, r);
    }
};

class Square : public Figure
{
protected:
    float a;

public:
    Square(float x, float y, float a)
        : Figure(x, y), a{ a } {}

    void SetA(float a) { this->a = a; }
    float GetA() { return a; }

    virtual float GetPerimeter() override { return a * 4; }
    virtual float GetSquare() override { return a * a; }

    Figure* copy() override
    {
        return new Square(x, y, a);
    }
};


int main()
{
    Figure* s1 = new Square(0, 0, 7);
    Figure* s2 = s1->copy();
    cout << s2->GetSquare() << endl;

    Figure* c1 = new Circle(0, 0, 5);
    Figure* c2 = c1->copy();
    cout << c2->GetSquare() << endl;

    return 0;
}
