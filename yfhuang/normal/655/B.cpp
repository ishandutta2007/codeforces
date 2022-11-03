//
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<numeric>
#include<ctime>
#include<functional>
using namespace std;

#define pi acos(-1)
#define INF 0x3f3f3f
#define gcd(a,b) __gcd(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long ll;
typedef unsigned long long ull;


int main()
{
    ll n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        if(n/2<=m)cout<<(ll)n*(n-1)/2<<endl;
        else
        {
            cout<<(ll)(n-1+n-2*m)*m<<endl;
        }
    }
}