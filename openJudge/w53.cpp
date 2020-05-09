#include <iostream>
using namespace std;
// 在此处补充你的代码

class Animal
{
public:
    static int number;
    Animal(){
        number++;
    }
    virtual ~Animal()
    {
        number--;
    }
};

class Dog:public Animal
{
public:
    static int number;
    Dog(){
        number++;
    }
    virtual ~Dog()//如果不加virtual,删除c2的时候就不能调用Cat的析构函数了 
    {
        number--;
    }
};

class Cat:public Animal
{
public:
    static int number;
    Cat(){
        number++;
    }
    virtual ~Cat()//如果不加virtual,删除c2的时候就不能调用Cat的析构函数了 
    {
        number--;
    }
};

int Animal::number=0,Dog::number=0,Cat::number=0;

void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}

// 0 animals in the zoo, 0 of them are dogs, 0 of them are cats
// 3 animals in the zoo, 2 of them are dogs, 1 of them are cats
// 6 animals in the zoo, 3 of them are dogs, 3 of them are cats
// 3 animals in the zoo, 2 of them are dogs, 1 of them are cats