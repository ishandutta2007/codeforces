#include <bits/stdc++.h>
using namespace std;
string s;
int ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        int dbmax=0;
        int dbmin=0;
        for(int j=i; j<s.size(); j++)
        {
            if(s[j]=='(')
            {
                dbmax++;
                dbmin++;
            }
            else if(s[j]==')')
            {
                dbmax--;
                dbmin--;
                if(dbmin==-1) dbmin=1;
            }
            else
            {
                dbmax++;
                dbmin--;
                if(dbmin==-1) dbmin=1;
            }
            if(dbmin>dbmax) break;
            if(dbmin==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}