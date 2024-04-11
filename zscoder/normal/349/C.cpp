#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (100000+10)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
int n;
ll a[MAXN];
int main()
{
    cin>>n;
    For(i,n) cin>>a[i];
    ll k=0;
    For(i,n) k=max(k,a[i]);
    ll t=0;
    For(i,n) t+=k-a[i];
    if (t>=k) {cout<<k<<endl;return 0;  }
    else 
    {
        double p=((double)(k-t))/((double)(n-1));
        k+=ceil(p);
        cout<<k<<endl;
    }
    
    return 0;
}