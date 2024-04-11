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
const int inf=~0U>>1,maxn=30;
using namespace std;
int n,m;
int A[maxn][maxn]={};
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m;
    For(i,1,n)
        For(j,1,m)
        {
            char c;cin>>c;A[i][j]=c-'0';
            A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1];
        }
    int ret=0;
    For(x1,1,n)For(y1,1,m)
        For(x2,x1,n)For(y2,y1,m)
        {
            int tmp=A[x2][y2]-A[x2][y1-1]-A[x1-1][y2]+A[x1-1][y1-1];
            if(tmp)continue;
            ret=max(ret,(x2+y2-x1-y1+2)*2);
        }
    cout<<ret<<endl;
}