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
bool dif(int x)
{
    vector<bool> b(10, false);
    while(x>0)
    {
        if(b[x%10]) return false;
        b[x%10]=true;
        x/=10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    cin>>l>>r;
    for(int i=l; i<=r; i++)
    {
        if(dif(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}