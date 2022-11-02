#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int x1, x2, x3, x4, x5, x6;
int y1, y2, y3, y4, y5, y6;

bool ins(int a1, int b1, int a2, int b2, int a3, int b3)
{
    return (a1<=a3 && a3<=a2 && b1<=b3 && b3<=b2);
}
bool good(int x, int y)
{
    return (ins(x1, y1, x2, y2, x, y) && (!ins(x3, y3, x4, y4, x, y)) && (!ins(x5, y5, x6, y6, x, y)));
}
void tr(int x, int y)
{
    if(good(x, y))
    {
        cout<<"YES"<<endl;
        exit(0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;
    x1*=2;
    x2*=2;
    x3*=2;
    x4*=2;
    x5*=2;
    x6*=2;
    y1*=2;
    y2*=2;
    y3*=2;
    y4*=2;
    y5*=2;
    y6*=2;
    tr(x1, y1);
    tr(x1, y2);
    tr(x2, y1);
    tr(x2, y2);

    tr(x3, y3-1);
    tr(x3-1, y3);
    tr(x3-1, y4);
    tr(x3, y4+1);
    tr(x4+1, y3);
    tr(x4, y3-1);
    tr(x4+1, y4);
    tr(x4, y4+1);

    tr(x5, y5-1);
    tr(x5-1, y5);
    tr(x5-1, y6);
    tr(x5, y6+1);
    tr(x6+1, y5);
    tr(x6, y5-1);
    tr(x6+1, y6);
    tr(x6, y6+1);

    tr(x1, y3-1);
    tr(x1, y4+1);
    tr(x2, y3-1);
    tr(x2, y4+1);

    tr(x3-1, y1);
    tr(x4+1, y1);
    tr(x3-1, y2);
    tr(x4+1, y2);

    tr(x1, y5-1);
    tr(x1, y6+1);
    tr(x2, y5-1);
    tr(x2, y6+1);

    tr(x5-1, y1);
    tr(x6+1, y1);
    tr(x5-1, y2);
    tr(x6+1, y2);

    cout<<"NO"<<endl;

    return 0;
}