#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

int DEBUG;

int n;
int p[maxn],q[maxn],pos[maxn];

int l[maxn],r[maxn];

int bomb[maxn],one[maxn];


const int M=524288;

struct node {
    int pre,sum;
} T[M<<1];

#define pre(k) T[k].pre
#define sum(k) T[k].sum

inline void update(int k)  {
    int ls=k<<1,rs=k<<1|1;
    pre(k)=pre(ls)+max(0,pre(rs)-sum(ls));
    sum(k)=sum(rs)+max(0,sum(ls)-pre(rs));
}

void change_val(int p)    {
    int k=p+M-1;
    if (bomb[p])
        pre(k)=0,sum(k)=0;
    else
        pre(k)=0,sum(k)=1;
    for (;k>1;) {
        k>>=1;
        update(k);
    }
}

void change_bomb(int p) {
    int k=p+M-1;
    if (one[p])
        pre(k)=0,sum(k)=0;
    else
        pre(k)=1,sum(k)=0;
    for (;k>1;) {
        k>>=1;
        update(k);
    }
}

void build()   {
    for (int i=0;i<(M<<1);++i)
        pre(i)=sum(i)=0;
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",p+i),pos[p[i]]=i;
    for (int i=1;i<=n;++i)
        scanf("%d",q+i);

    for (int i=1;i<=n;++i) l[i]=1,r[i]=n;

    while (1)   {
        bool flag=1;

        build();

        for (int i=1;i<=n;++i) one[i]=bomb[i]=0;

        int now=n;
        for (int i=1;i<=n;++i)  {
            if (l[i]==r[i]) {
                bomb[q[i]]=1,change_bomb(q[i]);
                continue;
            }

            flag=0;

            int mid=(l[i]+r[i]+1)>>1;
            while (now>=mid)    
                one[pos[now]]=1,change_val(pos[now]),--now;
            

            if (sum(1)>0)
                l[i]=mid;
            else
                r[i]=mid-1;
            
            bomb[q[i]]=1,change_bomb(q[i]);

            // cout<<endl<<endl;
        }
        // cerr<<clock()<<endl;
        if (flag) break;
    }

    for (int i=1;i<=n;++i)
        printf("%d ",l[i]);
    // cerr<<clock()<<endl;
    return 0;
}