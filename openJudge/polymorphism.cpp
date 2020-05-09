#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
public:
    virtual double Area() = 0;
    virtual void PrintInfo() = 0;
};

class Rectangle : public Shape
{
public:
    int w, h;
    virtual double Area();
    virtual void PrintInfo();
};

class Circle : public Shape
{
public:
    int r;
    virtual double Area();
    virtual void PrintInfo();
};

class Triangle : public Shape
{
public:
    int a, b, c;
    virtual double Area();
    virtual void PrintInfo();
};

// -------------- Area() ---------------------
double Rectangle::Area()
{
    return w * h;
}

double Circle::Area()
{
    return 3.14 * r * r;
}

double Triangle::Area()
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// ------------- PrintInfo() -----------------
void Rectangle::PrintInfo()
{
    cout << "Rectangle Area = " << Area() << endl;
}
void Circle::PrintInfo()
{
    cout << "Circle Area = " << Area() << endl;
}
void Triangle::PrintInfo()
{
    cout << "Triangle Area = " << Area() << endl;
}
// -------------------------------------------

Shape *pShapes[5];
int MyCompare(const void *s1, const void *s2);

int main()
{
    int i;
    int n;
    Rectangle *pr;
    Circle *pc;
    Triangle *pt;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'R':
            pr = new Rectangle();
            cin >> pr->w >> pr->h;
            pShapes[i] = pr;
            break;
        case 'C':
            pc = new Circle();
            cin >> pc->r;
            pShapes[i] = pc;
            break;
        case 'T':
            pt = new Triangle();
            cin >> pt->a >> pt->b >> pt->c;
            pShapes[i] = pt;
            break;
        }
    }
    qsort(pShapes, n, sizeof(Shape *), MyCompare);
    for (i = 0; i < n; i++)
        pShapes[i]->PrintInfo();
    return 0;
}

int MyCompare(const void *s1, const void *s2)
{
    double a1, a2;
    Shape **p1;
    Shape **p2;
    p1 = (Shape **)s1;
    p2 = (Shape **)s2;
    a1 = (*p1)->Area();
    a2 = (*p2)->Area();
    if (a1 < a2)
        return -1;
    else if (a2 < a1)
        return 1;
    else
        return 0;
}
