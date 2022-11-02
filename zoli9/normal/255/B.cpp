#include <iostream>
using namespace std;
string s;
int xx, yy;
int main()
{
    cin>>s;
    xx=0;
    yy=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='x')
        {
            xx++;
        }
        else if(s[i]=='y')
        {
            yy++;
        }
    }
    if(xx>=yy)
    {
        for(int i=0; i<xx-yy; i++)
        {
            cout<<"x";
        }
        return 0;
    }
    for(int i=0; i<yy-xx; i++)
        {
            cout<<"y";
        }
    return 0;
}