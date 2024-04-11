#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
int n, k;
string s;
int tipus[200009];
int darab[3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int minx=-100000;
        int maxx=100000;
        int miny=-100000;
        int maxy=100000;
        for(int i=1; i<=n; i++)
        {
            int x, y;
            int a, b, c, d;
            cin>>x>>y>>a>>b>>c>>d;
            if(a==0) minx=max(minx, x);
            if(b==0) maxy=min(maxy, y);
            if(c==0) maxx=min(maxx, x);
            if(d==0) miny=max(miny, y);
        }
        if(minx<=maxx && miny<=maxy)
        {
            cout<<1<<" "<<minx<<" "<<miny<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}