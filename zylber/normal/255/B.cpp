#include <iostream>
#include <string>
using namespace std;

string s;

int d;

int main()
{
    cin >> s;
    d=0;
    int ss=s.size();
    for(int i=0; i<ss; i++)
        if(s[i]=='x')
            d++;
        else
            d--;

    string res="";
    if(d>=0)
    {
        for(int i=0; i<d; i++)
            res+='x';
    }
    else
        for(int i=0; i<-d; i++)
            res+='y';

    cout << res << endl;
}