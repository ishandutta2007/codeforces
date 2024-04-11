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
typedef long long ll;
typedef unsigned long long ull;
struct Seg
{
    int l,r;
    Seg(){}
    Seg(int _l,int _r)
    {
        l=_l;r=_r;if(l>r)swap(l,r);
    }
}A[maxn];
int main()
{
    //freopen("in","r",stdin);
    int n;int l,r;cin>>n;
    rep(i,n)cin>>l>>r,A[i]=Seg(l,r);
    int Last=-inf,cnt=0;
    vector<int> Ans;
    bool Mark[maxn]={};
    for(;;)
    {
        int Min=-1;
        rep(i,n)if(!Mark[i]&&(Min==-1||A[i].r<A[Min].r))
            Min=i;
        if(Min==-1)break;
        int x=A[Min].r;
        Ans.pb(x);
        rep(i,n)if(!Mark[i]&&x>=A[i].l&&x<=A[i].r)Mark[i]=true;
    }
    cout<<Ans.size()<<endl;
    rep(i,Ans.size())cout<<Ans[i]<<" ";cout<<endl;
}