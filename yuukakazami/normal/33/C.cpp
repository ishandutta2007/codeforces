#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MaxNum=100000+100;
const int Inf=~0U>>2;

inline void Scan_Int(int&t)
{
    char c;int sign=1;
    while(c=getchar(),c!='-'&&(c<'0'||c>'9'));
    if(c=='-')t=0,sign=-1;else t=c-'0';
    while(c=getchar(),c>='0'&&c<='9')t=t*10+c-'0';
    t*=sign;
}

struct SegTree
{
    static const int MaxRange=1<<20;
    int MaxR[MaxRange];
    int Sum[MaxRange];
    int OFF;

    void SetSize(int Cap)
    {
        OFF=1;while(OFF<=Cap+3)OFF<<=1;
        int Cnt=OFF*2;
        memset(Sum,0,sizeof(int)*Cnt);
        memset(MaxR,0,sizeof(int)*Cnt);
    }

    void Update_Node(int t)
    {
        int l=t*2,r=t*2+1;
        MaxR[t]=max(MaxR[r],Sum[r]+MaxR[l]);
        Sum[t]=Sum[l]+Sum[r];
    }

    void Update(int at,int x)
    {
        at+=OFF+1;Sum[at]=MaxR[at]=x;
        for(at>>=1;at;at>>=1)
            Update_Node(at);
    }

    int Ask()
    {
        return MaxR[1];
    }
}T;

int Cnt,A[MaxNum];

void Solve()
{
    Scan_Int(Cnt);
    rep(i,Cnt)Scan_Int(A[i]);
    T.SetSize(Cnt);
    rep(i,Cnt)T.Update(i,-2*A[i]);

    int ans=-Inf;
    int at=0,sum=0;
    rep(i,Cnt)sum+=A[i];
    for(;;)
    {
        int ret=sum+T.Ask();
        if(ret>ans)ans=ret;
        if(at>=Cnt)break;
        T.Update(at,A[at]*2);
        sum-=2*A[at];
        at++;
    }

    printf("%d\n",ans);
}
int main()
{
    //freopen("in","r",stdin);
    /*int t;cin>>t;
    while(t--)*/Solve();
}