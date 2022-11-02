#include <iostream>
using namespace std;
string s1, s2;
int n1, n2;
int main()
{
    cin>>s1>>s2;
    n1=0;
    n2=0;
    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i]=='1')
        {
            n1++;
        }
    }
    for(int i=0; i<s2.size(); i++)
    {
        if(s2[i]=='1')
        {
            n2++;
        }
    }
    if(n1>=n2 || (n1%2 && n1==n2-1)) cout<<"YES";
    else cout<<"NO";
    return 0;
}