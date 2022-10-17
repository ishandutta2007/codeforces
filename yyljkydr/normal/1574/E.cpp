#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e2+7,P=998244353;

int n,m,q;

int pw[N];

map<int,int>a[N];

struct Data{
    int cho[N][2];

    int n;

    int cnt,zero;

    void init(int x)
    {
        n=x;
    }

    void ins(int x,int v)
    {
        if(cho[x][0]&&cho[x][1])
            zero+=v;
        else if(cho[x][0]||cho[x][1])
            cnt+=v;
    }

    void add(int x,int y,int w,int v)
    {
        if(w==0)
            return;
        w--;
        int d=y&1;
        ins(x,-1);
        cho[x][d^w]+=v;
        ins(x,1);
    }

    int val()
    {
        if(zero)
            return 0;
        return pw[n-cnt];
    }
}A,B;

int vis[2][2];

int main()
{
    pw[0]=1;
    for(int i=1;i<=1000000;i++)
        pw[i]=pw[i-1]*2%P;
    scanf("%d%d%d",&n,&m,&q);
    A.init(n);
    B.init(m);
    while(q--)
    {
        int x,y,op;
        scanf("%d%d%d",&x,&y,&op);
        if(a[x][y]!=0)
            vis[(x+y)&1][a[x][y]-1]--;
        A.add(x,y,a[x][y],-1);
        B.add(y,x,a[x][y],-1);
        a[x][y]=op+1;
        A.add(x,y,a[x][y],1);
        B.add(y,x,a[x][y],1);
        if(op!=-1)
            vis[(x+y)&1][op]++;
        int sm=0,nsm=0;
        sm=vis[0][0]|vis[1][1];
        nsm=vis[0][1]|vis[1][0];
        int num;
        if(sm&&nsm)
            num=0;
        else if(sm||nsm)
            num=1;
        else
            num=2;
        printf("%lld\n",(1ll*A.val()+B.val()-num+P)%P);
    }
}