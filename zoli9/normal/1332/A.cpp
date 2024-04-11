#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll a, b, c, d, x, y, x1, y1, x2, y2;
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if(x1==x2 && a+b>0)
        {
            cout<<"No"<<'\n';
            continue;
        }
        if(y1==y2 && c+d>0)
        {
            cout<<"No"<<'\n';
            continue;
        }
        if(x+(b-a)<x1 || x+(b-a)>x2)
        {
            cout<<"No"<<'\n';
            continue;
        }
        if(y+(d-c)<y1 || y+(d-c)>y2)
        {
            cout<<"No"<<'\n';
            continue;
        }
        cout<<"Yes"<<'\n';
    }


    return 0;
}