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
const int inf=~0U>>1,maxn=1000;
using namespace std;
int n,m,i,j;
double A[maxn]={},B[maxn],C[maxn];
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m>>i>>j;
    if(m==1)
    {
        double ans=(n-i)*2;
        printf("%0.4lf\n",ans);
        return 0;
    }
    while(i<n)
    {
        rep(j,m)B[j]=0;
        rep(t,100)
        {
            for(int i=1;i<m-1;i++)C[i]=(B[i]+B[i-1]+B[i+1]+A[i])/4+1;
            C[0]=(B[0]+B[1]+A[0])/3+1;
            C[m-1]=(B[m-1]+B[m-2]+A[m-1])/3+1;
            rep(j,m)B[j]=C[j];
        }
        rep(j,m)A[j]=C[j];
        i++;
    }
    printf("%0.4lf\n",A[j-1]);
}