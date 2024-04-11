#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int test;
int n;
string s[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        cin>>s[0];
        cin>>s[1];
        int x=0;
        int y=0;
        bool jo=false;
        while(1)
        {
            if(x==1 && y==n)
            {
                jo=true;
                break;
            }
            else if(y>=n) break;
            if(s[x][y]-'0'<=2)
            {
                y++;
                continue;
            }
            if(s[1-x][y]-'0'<=2) break;
            x=1-x;
            y++;
        }
        if(jo) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}