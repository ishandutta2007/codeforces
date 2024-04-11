#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int u;
        cin>>u;
        cin>>s;
        vector<char> c1, c2;
        bool decided=false;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='0')
            {
                c1.push_back('0');
                c2.push_back('0');
            }
            else if(s[i]=='1')
            {
                if(decided)
                {
                    c1.push_back('0');
                    c2.push_back('1');
                }
                else
                {
                    c1.push_back('1');
                    c2.push_back('0');
                    decided=true;
                }
            }
            else
            {
                if(decided)
                {
                    c1.push_back('0');
                    c2.push_back('2');
                }
                else
                {
                    c1.push_back('1');
                    c2.push_back('1');
                }
            }
        }
        for(char c: c1) cout<<c;
        cout<<'\n';
        for(char c: c2) cout<<c;
        cout<<'\n';
    }


    return 0;
}