#include <iostream>
using namespace std;
string s;
int main()
{
    cin>>s;
    int b;
    int a=s[s.length()-1]-'0';
    if(s.length()>1)
    {
        b=s[s.length()-2]-'0';
    }
    else
    {
        b=0;
    }
    int c=10*b+a;
    if(c%4==0)
    {
        cout<<4;
        return 0;
    }
    cout<<0;

    return 0;
}