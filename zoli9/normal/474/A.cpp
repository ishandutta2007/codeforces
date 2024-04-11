#include <iostream>
using namespace std;
string a1="qwertyuiopasdfghjkl;zxcvbnm,./";
string s;
char b;
char c[102];
int main()
{
    cin>>b;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<30; j++)
        {
            if(s[i]==a1[j])
            {
                if(b=='R')
                {
                    c[i]=a1[j-1];
                }
                else
                {
                    c[i]=a1[j+1];
                }
            }
        }
    }
    for(int i=0; i<s.length(); i++)
    {
        cout<<c[i];
    }
    return 0;
}