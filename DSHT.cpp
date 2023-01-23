#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#define pi 3.14

class SDT;

// sua chuc nang a

class DSHT;
class HT
{
    int ma; //
    float r;
    int rX, rY;

public:
    HT()
    {
        ma = 0;
        r = 0;
        rX = rY = 0;
    }
    friend class DSHT;

    void nhap()
    {
        cout<<"Nhap ma: ";
        cin >> ma;
        cin >> r;
        cin >> rX;
        cin >> rY;
    }
    void xuat()
    {
        cout << ma << " " << r << " " << rX << " " << rY << " " << (float)2 * pi * r << endl;
    }
    float distance();
};

// istream &operator>>(istream &is, HT &p){
//     is>>p.ma;
//     is>>p.r;
//     is>>p.rX;
//     is>>p.rY;
//     return is;
// }

// ostream &operator<<(ostream &os, HT&p){
//     os<<p.r<<" "<<p.rX<<" "<<p.rY<<" "<<(float)2*p.r*pi<<endl;
//     return os;
// }

float HT::distance()
{
    return sqrt(this->rX * this->rX + this->rY * this->rY);
}

class DSHT
{
    int n;
    HT *a;

public:
    DSHT()
    {
        n = 0;
        a = NULL;
    }
    ~DSHT()
    {
        delete[] a;
        n = 0;
    }

    void nhap();
    void mindistance();
};

void DSHT::nhap()
{
    int i;
    cin >> n;
    a = new HT[n];
    for (i = 0; i < n; i++)
    {
        a[i].HT::nhap();
    }
}

void DSHT::mindistance()
{
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].HT::distance() < a[min].HT::distance())
        {
            min = i;
        }
    }
    a[min].HT::xuat();
}

int main()
{
    DSHT ds;
    ds.nhap();
    ds.mindistance();
}
