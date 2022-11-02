#include <iostream>
using namespace std;
char c;
int w;
int b;
int main()
{
    w=0;
    b=0;
    for(int i=1; i<=64; i++)
    {
        cin>>c;
        if(c=='q')
        {
            b+=9;
        }
        if(c=='r')
        {
            b+=5;
        }
        if(c=='b')
        {
            b+=3;
        }
        if(c=='n')
        {
            b+=3;
        }
        if(c=='p')
        {
            b+=1;
        }
        if(c=='Q')
        {
            w+=9;
        }
        if(c=='R')
        {
            w+=5;
        }
        if(c=='B')
        {
            w+=3;
        }
        if(c=='N')
        {
            w+=3;
        }
        if(c=='P')
        {
            w+=1;
        }
    }
    if(b>w)
    {
        cout<<"Black";
    }
    else if(b==w)
    {
        cout<<"Draw";
    }
    else
    {
        cout<<"White";
    }

    return 0;
}