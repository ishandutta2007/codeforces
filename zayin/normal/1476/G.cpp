#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;
int a[maxn];
const int lim=2050;

struct qry {
    int l,r,k,t,id;
    bool operator < (qry& b)    { 
        return l/lim==b.l/lim?(r/lim==b.r/lim?t<b.t:r<b.r):l<b.l;
    }
};
vector<qry> Q;

struct event    {
    int p,x;
};
vector<event> E;

int L=1,R=0,T=0;
int val[maxn];
int pre[maxn],nxt[maxn];

void shift(int x,int y) {
    // cout<<"shift:"<<x<<" "<<y<<endl;
    assert(x>=0);
    assert(y>=0);
    #define L pre
    #define R nxt
    if (!val[y]++)  {
        if (x<y)  {
            L[y]=x,R[y]=R[x];
            L[R[y]]=R[L[y]]=y;
        } else  {
            R[y]=x,L[y]=L[x];
            L[R[y]]=R[L[y]]=y;
        }
    }
    if (!--val[x])  {
        if (x)  {
            L[R[x]]=L[x];
            R[L[x]]=R[x];
        }
    }
    #undef L
    #undef R
}

int cnt[maxn];
void add(int x) {
    // cout<<"add:"<<x<<" "<<cnt[x]<<endl;
    shift(cnt[x],cnt[x]+1);
    ++cnt[x];
}

void del(int x) {
    // cout<<"del:"<<x<<" "<<cnt[x]<<endl;
    shift(cnt[x],cnt[x]-1);
    --cnt[x];
}

void modify(int i) {
    --i;
    // cout<<"modify:"<<i<<" "<<E.size()<<endl;
    if (L<=E[i].p&&E[i].p<=R)   {
        del(a[E[i].p]);
        add(E[i].x);
    }
    swap(a[E[i].p],E[i].x);
}

int calc(int k) {
    vector<pair<int,int> > A;

    // cout<<"calc:"<<L<<" "<<R<<" "<<k<<endl;
    int sum=0,cnt=0;
    for (int i=nxt[0];i<=n;i=nxt[i])    {
        assert(val[i]);
        sum+=val[i]*i,cnt+=val[i];
        A.emplace_back(i,val[i]);
        // cout<<"CNT:"<<i<<" "<<val[i]<<endl;
    }
    assert(sum==R-L+1);
    // cout<<"cnt:"<<cnt<<endl;
    if (cnt<k) return -1;

    // cout<<"???"<<endl;
    int C=0,ans=1e9;
    for (int i=0,j=0;i<A.size();++i)    {
        while (j<A.size()&&C<k)
            C+=A[j++].second;
        if (C<k) break;
        // cout<<A[i].first<<" "<<A[j-1].first<<" "<<A[j-1].first-A[i].first<<endl;
        ans=min(ans,A[j-1].first-A[i].first);
        C-=A[i].second;
    }
    return ans;
}

int ans[maxn];

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    for (int i=1;i<=m;++i)  {
        int op,l,r,k,p,x;
        scanf("%d",&op);
        if (op==1)  {
            scanf("%d%d%d",&l,&r,&k);
            Q.push_back(qry{l,r,k,(int)E.size(),(int)Q.size()});
        } else  {
            scanf("%d%d",&p,&x);
            E.push_back(event{p,x});
        }
    }

    cnt[0]=n;
    nxt[0]=n+1,pre[n+1]=0;

    sort(Q.begin(),Q.end());
    for (qry q:Q)   {
        // cout<<q.l<<" "<<q.r<<" | "<<L<<" "<<R<<endl;
        while (R<q.r) add(a[++R]);
        while (L>q.l) add(a[--L]);
        while (R>q.r) del(a[R--]);
        while (L<q.l) del(a[L++]);
        while (T<q.t) modify(++T);
        while (T>q.t) modify(T--);
        assert(L==q.l&&R==q.r);
        // cout<<"q.id:"<<q.id<<endl;
        ans[q.id]=calc(q.k);
    }

    for (int i=0;i<Q.size();++i)
        printf("%d\n",ans[i]);
    return 0;
}