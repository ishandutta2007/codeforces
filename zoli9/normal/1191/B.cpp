#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[3];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s[0]>>s[1]>>s[2];
    if(s[0][1]==s[1][1] && s[1][1]==s[2][1])
    {
        v.push_back(s[0][0]-'0');
        v.push_back(s[1][0]-'0');
        v.push_back(s[2][0]-'0');
        sort(v.begin(), v.end());
        if(v[0]==v[1] && v[1]==v[2])
        {
            cout<<0<<endl;
            return 0;
        }
        if(v[0]+1==v[1] && v[1]+1==v[2])
        {
            cout<<0<<endl;
            return 0;
        }
        if(abs(v[1]-v[0])<=2 || abs(v[2]-v[1])<=2)
        {
            cout<<1<<endl;
            return 0;
        }
        else cout<<2<<endl;
    }
    else
    {
        if(s[0][1]==s[1][1])
        {
            if(abs((s[0][0]-'0')-(s[1][0]-'0'))<=2)
            {
                cout<<1<<endl;
            }
            else cout<<2<<endl;
        }
        else if(s[0][1]==s[2][1])
        {
            if(abs((s[0][0]-'0')-(s[2][0]-'0'))<=2)
            {
                cout<<1<<endl;
            }
            else cout<<2<<endl;
        }
        else if(s[1][1]==s[2][1])
        {
            if(abs((s[1][0]-'0')-(s[2][0]-'0'))<=2)
            {
                cout<<1<<endl;
            }
            else cout<<2<<endl;
        }
        else
        {
            cout<<2<<endl;
            return 0;
        }
    }

    return 0;
}