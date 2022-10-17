#include<bits/stdc++.h>
using namespace std;

int T;

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>s;
        int n=s.size();
        bool ok=0;
        for(int i=n-1;i>=1;i--)
            if(s[i]-'0'+s[i-1]-'0'>=10)
            {
                int x=s[i]-'0'+s[i-1]-'0';
                cout<<s.substr(0,i-1)+to_string(x)+s.substr(i+1)<<"\n";
                ok=1;
                break;
            }
        if(!ok)
        {
            cout<<s[0]+s[1]-'0'-'0'<<s.substr(2)<<"\n";
        }
    }
}