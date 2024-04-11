#include <iostream>
#include <cmath>
using namespace std;
string s;
int x;
int e=0, n=0;
int main()
{
    cin>>x>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0') n++;
        else e++;
    }
    cout<<abs(e-n);
    return 0;
}