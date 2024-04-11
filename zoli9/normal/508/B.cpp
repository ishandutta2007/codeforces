#include <iostream>
#include <fstream>
using namespace std;
string s;
int x[100001];
int hely;
bool v=false;
int main()
{
    cin>>s;
    int h=s.length();
    for(int i=0; i<s.length(); i++)
    {
        x[i]=s[i]-'0';
    }
    for(int i=0; i<h; i++)
    {
        if(x[i]%2==0)
        {
            v=true;
        }
    }
    if(!v)
    {
        cout<<-1;
        return 0;
    }
    v=false;
    for(int i=0; i<h; i++)
    {
        if(!v)
        {
           if(x[i]%2==0 && x[i]<x[h-1])
       {
           hely=i;
           v=true;
           break;
       }
        }

    }
    if(!v)
    {
        for(int i=h-1; i>=0; i--)
        {
            if(x[i]%2==0)
            {
                hely=i;
                v=true;
                break;
            }
        }
    }

    for(int i=0; i<h; i++)
    {
        if(i==hely)
        {
            cout<<x[h-1];
        }
        else if(i==h-1)
        {
            cout<<x[hely];
        }
        else
        {
            cout<<x[i];
        }
    }

    return 0;
}