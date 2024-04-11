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
const int inf=~0U>>1,maxn=100000+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,v;
int P[maxn];
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m>>v;
    if(m<n-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    For(i,1,n)P[i]=i;
    int L=2,R=n-L+1;
    ll M=L*(L-1)/2+R*(R-1)/2;
    if(M<m){cout<<-1<<endl;return 0;}
    swap(P[L],P[v]);
    For(i,1,n-1)
        cout<<P[i]<<" "<<P[i+1]<<endl,m--;
    For(i,1,L)
        For(j,i+2,L)
        {
            if(!m)return 0;
            cout<<P[i]<<" "<<P[j]<<endl;
            m--;
        }
    For(i,L,n)
        For(j,i+2,n)
        {
            if(!m)return 0;
            cout<<P[i]<<" "<<P[j]<<endl;
            m--;
        }
}