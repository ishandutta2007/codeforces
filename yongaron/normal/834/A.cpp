#include <iostream>

using namespace std;
char a, b;
bool cw, ccw;
int n;

int main()
{
    cin>>a;
    cin>>b;
    cin>>n;
    n %= 4;
    if(a == 118)
        a = 0;
    if(a == 60)
        a = 1;
    if(a == 94)
        a = 2;
    if(a == 62)
        a = 3;
    if(b == 118)
        b = 0;
    if(b == 60)
        b = 1;
    if(b == 94)
        b = 2;
    if(b == 62)
        b = 3;
    if((a+n)%4 == b)
        cw = true;
    if((a-n+4)%4 == b)
        ccw = true;
    if(cw && ccw)
        cout<<"undefined"<<endl;
    else if(cw)
        cout<<"cw"<<endl;
    else
        cout<<"ccw"<<endl;
    return 0;
}