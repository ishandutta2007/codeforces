#include <iostream>
using namespace std;
string s;
int n;
int t[100009];
int d[100009];
int ki=0;
int na=0;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0; i<s.size(); i++)
    {
        if('A'<=s[i] && s[i]<='Z')
        {
            t[i]=1;
            na++;
        }
        else
        {
            t[i]=0;
            ki++;
        }
    }
    d[0]=na;
    for(int i=1; i<=n; i++)
    {
        d[i]=d[i-1];
        if(t[i-1]==1)
        {
            d[i]--;
        }
        else
        {
            d[i]++;
        }
    }
    int mini=d[0];
    for(int i=1; i<=n; i++)
    {
        mini=min(mini, d[i]);
    }
    cout<<mini;
    return 0;
}