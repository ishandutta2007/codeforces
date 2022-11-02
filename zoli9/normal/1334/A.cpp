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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a=0;
        int b=0;
        bool good=true;
        for(int i=1; i<=n; i++)
        {
            int x, y;
            cin>>x>>y;
            if(y>x) good=false;
            if(x<a) good=false;
            if(y<b) good=false;
            if(y-b>x-a) good=false;
            a=x;
            b=y;
        }
        if(good) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}