#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal
{
public:
    static int number;
    Animal()
    {
        number++;
    }
    //这里为什么用虚函数？
    virtual ~Animal()
    {
        number--;
    }
};

class Dog: public Animal
{
public:
    static int number;
    Dog()
    {
        number++;
    }
    virtual ~Dog() // 派生类自动为虚函数，可不加virtual
    {
        number--;
    }

};

class Cat: public Animal
{
public:
    static int number;
    Cat()
    {
        number++;
    }
    virtual ~Cat()
    {
        number--;
    }
};

int Animal::number = 0;
int Cat::number = 0;
int Dog::number = 0;

void print()
{
    cout << Animal::number << " animals in the zoo, " << Dog::number 
    << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main()
{
    print();
    Dog d1, d2;
    Cat c1;
    print();
    Dog *d3 = new Dog();
    Animal *c2 = new Cat;
    Cat *c3 = new Cat;
    print();
    delete c3;
    delete c2; // 先析构cat,后析构animal
    delete d3;
    print();
}