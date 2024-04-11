#include <bits/stdc++.h>
using namespace std;
int t;
unordered_map<long long, int> m;
long long hat[20];
int main()
{
    hat[0]=1;
    for(int i=1; i<=19; i++)
    {
        hat[i]=hat[i-1]*2;
    }
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        char tip;
        cin>>tip;
        string s;
        cin>>s;
        int poz=s.size()-1;
        long long val=0;
        for(int i=0; i<=18; i++)
        {
            if(poz>=0)
            {
                if((s[poz]-'0')%2) val+=hat[i];
                poz--;
            }
        }
        if(tip=='+')
        {
            m[val]++;
        }
        else if(tip=='-')
        {
            m[val]--;
        }
        else
        {
            cout<<m[val]<<endl;
        }
    }

    return 0;
}