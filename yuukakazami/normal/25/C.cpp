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
const int inf=~0U>>1,maxn=300;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int D[maxn][maxn],n;
int main()
{
    //freopen("in","r",stdin);
    scanf("%d",&n);
    rep(i,n)rep(j,n)scanf("%d",&D[i][j]);
    int k,a,b,c;
    scanf("%d",&k);
    rep(i,k)
    {
        scanf("%d%d%d",&a,&b,&c);--a;--b;
        D[a][b]=D[b][a]=min(D[a][b],c);ll sum=0;
        rep(i,n)rep(j,n)
        {
            D[i][j]=min(D[i][a]+D[a][b]+D[b][j],D[i][j]);
            D[i][j]=min(D[i][b]+D[b][a]+D[a][j],D[i][j]);
            sum+=D[i][j];
        }
        cout<<sum/2<<" ";
    }
    cout<<endl;
}