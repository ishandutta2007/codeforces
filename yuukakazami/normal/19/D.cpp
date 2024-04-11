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
const int inf=~0U>>1,maxn=200000+10;
using namespace std;
int n,m;
struct Index
{
    int A[maxn],n;
    int size(){return n;}
    void clear(){n=0;}
    void add(int x){A[n++]=x;}
    void doit()
    {
        sort(A,A+n);n=unique(A,A+n)-A;
    }
    int operator[](int v){return lower_bound(A,A+n,v)-A;}
}IX;
char cmd[100];
struct Action
{
    int type,x,y;
    void readin()
    {
        scanf("%s%d%d",cmd,&x,&y);
        IX.add(x);
        if(cmd[0]=='a')type=0;
        if(cmd[0]=='r')type=1;
        if(cmd[0]=='f')type=2;
    }
}A[maxn];
set<int> S[maxn];
int M(int i){return *(--S[i].end());}
int Max[maxn*4];
#define Tree int t,int l,int r
#define Left t*2,l,l+r>>1
#define Right t*2+1,l+r>>1,r
#define root 1,0,m
void Update(int t)
{
    Max[t]=max(Max[t*2],Max[t*2+1]);
}
void Change(Tree,int p)
{
    if(p<l||p>=r)return;
    if(l+1==r){Max[t]=M(l);return;}
    Change(Left,p);Change(Right,p);
    Update(t);
}
int Query(Tree,int a,int c)
{
    if(a>=r||Max[t]<=c)return -1;
    if(l+1==r)return l;
    int tmp=Query(Left,a,c);if(tmp>=0)return tmp;
    tmp=Query(Right,a,c);if(tmp>=0)return tmp;
    return -1;
}
void init()
{
    cin>>n;
    rep(i,n)A[i].readin();
    IX.doit();
}
void Solve()
{
    m=IX.size();memset(Max,-1,sizeof Max);
    rep(i,m)S[i].insert(-1);
    rep(i,n)
    {
        int x=A[i].x,y=A[i].y;x=IX[x];
        switch(A[i].type)
        {
            case 0:S[x].insert(y);Change(root,x);break;
            case 1:S[x].erase(S[x].find(y));Change(root,x);break;
            case 2:int tmp=Query(root,x+1,y);
                if(tmp==-1)printf("-1\n");
                else
                {
                    set<int>::iterator it=S[tmp].upper_bound(y);
                    printf("%d %d\n",IX.A[tmp],*it);
                }
        }
    }
}
int main()
{
    //freopen("in","r",stdin);
    init();
    Solve();
}