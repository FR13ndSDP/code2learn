#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
private:
    char buf[220];
public:
// implement " + " of two string will be more easy using reversed string
// eg. 123 + 1 => 321
//               +100
//             => 421
//      reverse=> 124
    void reverse(char * p) {
        int len = strlen(p);
        int i = 0,j = len -1;
        while(i <= j ) {
            swap(p[i],p[j]);
            ++i;
            --j;
        }
    }
    CHugeInt(char * p) {
        memset(buf,0,sizeof(buf));
        strcpy(buf,p);
        reverse(buf);
    }
    CHugeInt(int n) {
        memset(buf,0,sizeof(buf));
        sprintf(buf,"%d",n);
        reverse(buf);
    }
    CHugeInt operator+(int n) {
        return * this + CHugeInt(n);
    }
    CHugeInt operator +(const CHugeInt & n) const  {
        CHugeInt tmp(0);
        int carry = 0;
        for(int i = 0;i < 210 ; ++i) {
            char c1 = buf[i];
            char c2 = n.buf[i];
            if( c1 == 0 && c2 == 0 && carry == 0)
                break;
            if( c1 == 0)
                c1 = '0';
            if( c2 == 0)
                c2 = '0';
                
            int k = c1 - '0' + c2 - '0' + carry;
            if( k >= 10) {
                carry = 1;
                tmp.buf[i] = k - 10 + '0';
            }
            else {
                carry = 0;
                tmp.buf[i] = k + '0';
            }
        }
        return tmp;
    }
    friend CHugeInt operator +(int n,const CHugeInt & h)
    {
        return h+n;
    }
    friend ostream &  operator <<(ostream & o,const CHugeInt & h) {
        int len = strlen(h.buf);
        for(int i = len -1 ; i >= 0; -- i)
            cout << h.buf[i];
        return o;
    }
    CHugeInt & operator += (int n) {
        * this = * this  + n;
        return * this;
    }
    CHugeInt & operator ++() {
        * this = * this + 1;
        return * this;
    }
    CHugeInt operator ++(int ) {
        CHugeInt tmp(*this);
        * this = tmp + 1;
        return tmp;
    }

};
int  main() 
{ 
	char s[210];
	int n;


	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}