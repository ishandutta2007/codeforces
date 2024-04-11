#include <iostream>
using namespace std;

typedef long long llong;

struct vt
{
    llong x, y;
    vt(llong _x, llong _y)
    {
        x = _x, y = _y;
    }
    friend vt operator ~(vt v)
    {
        return vt(v.y, -v.x);
    }
    friend vt operator -(vt v)
    {
        return ~(~(v));
    }
    friend llong operator *(vt a, vt b)
    {
        return a.x * b.x + a.y * b.y;
    }
    friend vt operator +(vt a, vt b)
    {
        return vt(a.x + b.x, a.y + b.y);
    }
    friend vt operator -(vt a, vt b)
    {
        return a + (-b);
    }
    llong norm()
    {
        return x * x + y * y;
    }
    vt(){}
};

vt A, B, C;
    
bool can(vt v)
{
    if (C.norm() == 0)
        return (v.norm() == 0);
    return ((v * C) % C.norm() == 0) && ((v * (~C)) % C.norm() == 0);
}

int main()
{
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    for (int i = 0; i < 4; i++)
    {
        if (can(B - A))
        {
            cout << "YES";
            return 0;
        }
        A = ~A;
    }
    cout << "NO";
    return 0;
}