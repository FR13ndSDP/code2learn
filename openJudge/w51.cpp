#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char *s)
{
    int i = 0;
    for (; s[i]; ++i)
        ;
    return i; // i 不计入\0的长度
}
void strcpy(char *d, const char *s)
{
    int i = 0;
    for (i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
}
int strcmp(const char *S1, const char *S2)
{
    for (int i = 0; S1[i] && S2[i]; ++i)
    {
        if (S1[i] < S2[i])
            return -1;
        else if (S1[i] > S2[i])
            return 1;
    }
    return 0;
}
void strcat(char *d, const char *s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}
class MyString
{
    // 在此处补充你的代码
private:
    char *pString;
public:

// constructors ----------------------------------------------------------------

    MyString(const char *c = NULL)
    {
        if (c)
        {
            pString = new char[strlen(c)];
            strcpy(pString, c);
        }
        else
        {
            pString = new char[1];
            pString[0] = '\0';
        }
    }

    MyString(const MyString &S)
    {
        if (S.pString)
        {
            pString = new char[strlen(S.pString)];
            strcpy(pString, S.pString);
        }
        else
        {
            pString = new char[1];
            pString[0] = '\0';
        }
    }

    ~MyString()
    {
        if (pString)
            delete[] pString;
    }

// operators -------------------------------------------------------------------

    friend ostream &operator<<(ostream &os, MyString &S)
    {
        os << S.pString;
        return os;
    }

    // reload +

    friend MyString operator+(const MyString &S, const char *c)
    {
        char *tmp = new char[strlen(S.pString) + strlen(c)];
        strcpy(tmp, S.pString);
        strcat(tmp, c);
        return MyString(tmp);
    }

    friend MyString operator+(const char *c, const MyString &S)
    {
        char *tmp = new char[strlen(S.pString) + strlen(c)];
        strcpy(tmp, c);
        strcat(tmp, S.pString);
        return MyString(tmp);
    }

    friend MyString operator+(MyString &S1, MyString &S2)
    {
        char *tmp = new char[strlen(S1.pString) + strlen(S2.pString)];
        strcpy(tmp, S1.pString);
        strcat(tmp, S2.pString);
        return MyString(tmp);
    }

    MyString &operator+=(const char *c)
    {
        char *temp = new char[strlen(pString)+strlen(c)];
        strcpy(temp, pString);
        strcat(temp, c);
        delete[] pString;
        pString = new char[strlen(temp)];
        strcpy(pString, temp);
        return *this;
    }

    // reload compare

    friend bool operator<(MyString &S1, MyString &S2)
    {
        if (strcmp(S1.pString, S2.pString) < 0)
            return true;
        else
            return false;
    }

    friend bool operator>(MyString &S1, MyString &S2)
    {
        if (strcmp(S1.pString, S2.pString) > 0)
            return true;
        else
            return false;
    }

    friend bool operator==(MyString &S1, MyString &S2)
    {
        if (strcmp(S1.pString, S2.pString) == 0)
            return true;
        else
            return false;
    }

    // reload brackets

    char &operator[](int i)
    {
        return pString[i];
    }

    char *operator()(int start, int length)
    {
        char *temp = new char[length + 1];
        for (int i = start; i < start + length; i++)
        {
            temp[i - start] = pString[i];
        }
        temp[length] = '\0';
        return temp;
    }

    // reload assignment

    MyString &operator=(const char *c)
    {
        if (pString == c)
            return *this;
        delete[] pString;
        if (c)
        {
            pString = new char[strlen(c) + 1];
            strcpy(pString, c);
        }
        else
        {
            pString = new char[1];
            pString[0] = '\0';
        }
        return *this;
    }

    MyString &operator=(const MyString &S1)
    {
        if (pString == S1.pString)
            return *this;
        delete[] pString;
        if (S1.pString)
        {
            pString = new char[strlen(S1.pString) + 1];
            strcpy(pString, S1.pString);
        }
        else
        {
            pString = new char[1];
            pString[0] = '\0';
        }
        return *this;
    }
};

int CompareString(const void *e1, const void *e2)
{
    MyString *S1 = (MyString *)e1;
    MyString *S2 = (MyString *)e2;
    MyString A;
    if (*S1 < *S2)
        return -1;
    else if (*S1 == *S2)
        return 0;
    else if (*S1 > *S2)
        return 1;
}
int main()
{
    MyString S1("abcd-"), S2, s3("efgh-"), s4(S1); // 默认初始化为null
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << S1 << S2 << s3 << s4 << endl;
    s4 = s3;                     // 重载 = (class, class)
    s3 = S1 + s3;                // +
    cout << "2. " << S1 << endl; // <<
    cout << "3. " << S2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << S1[2] << endl; // 重载 []
    S2 = S1;
    S1 = "ijkl-";
    S1[2] = 'A';
    cout << "7. " << S2 << endl;
    cout << "8. " << S1 << endl;
    S1 += "mnop"; // 重载 +=
    cout << "9. " << S1 << endl;
    s4 = "qrst-" + S2; // +
    cout << "10. " << s4 << endl;
    S1 = S2 + s4 + " uvw " + "xyz";
    cout << "11. " << S1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    //S1的从下标0开始长度为4的子串
    cout << S1(0, 4) << endl;
    //S1的从下标5开始长度为10的子串
    cout << S1(5, 10) << endl;
    return 0;
}

// 1. abcd-efgh-abcd-
// 2. abcd-
// 3.
// 4. abcd-efgh-
// 5. efgh-
// 6. c
// 7. abcd-
// 8. ijAl-
// 9. ijAl-mnop
// 10. qrst-abcd-
// 11. abcd-qrst-abcd- uvw xyz
// about
// big
// me
// take
// abcd
// qrst-abcd-