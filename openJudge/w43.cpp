#include <iostream> 
using namespace std;
class Point
{ 
private: 
    int x; 
    int y; 
public: 
    Point() { };
    friend istream &operator >>(istream &in,Point &s)
    {
        in>>s.x>>s.y;
        return in;
    }
    friend ostream &operator <<(ostream &o,const Point &s)
    {
        cout<<s.x<<","<<s.y;
        return o;
    }
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}