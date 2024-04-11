#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1,maxn=100000;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n;ll j;
struct Point
{
    ll x,y;
    Point(ll _x=0,ll _y=0):x(_x),y(_y){}
    Point operator*(int d)
    {
        return Point(x*d,y*d);
    }
    Point operator+(const Point&o)
    {
        return Point(x+o.x,y+o.y);
    }
    Point operator-(const Point&o)
    {
        return Point(x-o.x,y-o.y);
    }
}A[maxn],M,Dp[maxn];
istream& operator>>(istream&in,Point&p)
{
    in>>p.x>>p.y;
    return in;
}
void Test()
{
    Dp[0]=M;
    for(int i=1;i<=j;i++)
    {
        Dp[i]=A[(i-1)%n]*2-Dp[i-1];
    }
    cout<<Dp[j].x<<" "<<Dp[j].y;
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>j;
    cin>>M;
    rep(i,n)cin>>A[i];//Test();
    int sign=1;Point ret;
    for(ll i=j-1;i>=0;i--)
    {
        ret=ret+A[i%n]*sign;
        sign*=-1;
        if(i==j-n)
        {
            if((i/n)%2)sign*=sign,ret.x=ret.y=0;
            i%=n;
        }
    }
    ret=ret*2;
    ret=ret+M*sign;
    cout<<ret.x<<" "<<ret.y<<endl;
}