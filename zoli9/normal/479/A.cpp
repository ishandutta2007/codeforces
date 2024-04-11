#include <iostream>
using namespace std;
int a, b, c;
int main()
{
    cin>>a>>b>>c;
    if(a!=1 && b!=1 && c!=1)
    {
        cout<<a*b*c;
        return 0;
    }
    if(a==1 && b!=1 && c!=1)
    {
        cout<<(a+b)*c;
        return 0;
    }
    if(a!=1 && b!=1 && c==1)
    {
        cout<<a*(b+c);
        return 0;
    }
    if(a!=1 && b==1 && c!=1)
    {
        if(a>c)
        {
            cout<<a*(b+c);
            return 0;
        }
        cout<<(a+b)*c;
        return 0;
    }
    if(a==1 && b==1 && c!=1)
    {
        cout<<(a+b)*c;
        return 0;
    }
    if(a!=1 && b==1 && c==1)
    {
        cout<<a*(b+c);
        return 0;
    }
    if(a==1 && b!=1 && c==1)
    {
        cout<<a+b+c;
        return 0;
    }
    cout<<a+b+c;


    return 0;
}