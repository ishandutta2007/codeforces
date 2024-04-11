#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

struct Mat{
    int a[3][3];

    void clear()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=0;
    }

    void init()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=(i==j);
    }
};

struct Vec{
    int a[3];

    void clear()
    {
        for(int i=0;i<3;i++)
            a[i]=0;
    }
};

Mat &operator *=(Mat &a,const Mat &b)
{
    Vec tmp;
    tmp.clear();
    for(int i=0;i<3;i++)
    {
        for(int k=i;k<3;k++)
            for(int j=k;j<3;j++)
                tmp.a[j]+=a.a[i][k]*b.a[k][j];
        for(int j=0;j<3;j++)
            a.a[i][j]=tmp.a[j],tmp.a[j]=0;
    }
    return a;
}

Vec operator +(const Vec &a,const Vec &b)
{
    Vec ret;
    for(int i=0;i<3;i++)
        ret.a[i]=a.a[i]+b.a[i];
    return ret;
}

Vec &operator *=(Vec &a,const Mat &b)
{
    Vec tmp;
    tmp.clear();
    for(int k=0;k<3;k++)
        for(int j=k;j<3;j++)
            tmp.a[j]+=a.a[k]*b.a[k][j];
    for(int j=0;j<3;j++)
        a.a[j]=tmp.a[j];
    return a;
}

struct T{
    int ls,rs,l,r;
    Vec v;
    Mat tag;
    bool tg;
}t[N*2+1];

void update(int x)
{
    t[x].v=t[t[x].ls].v+t[t[x].rs].v;
}

void mul(int x,const Mat &a)
{
    t[x].v*=a;
    t[x].tag*=a;
    t[x].tg=1;
}

void pushdown(int x)
{
    if(t[x].tg)
    {
        mul(t[x].ls,t[x].tag);
        mul(t[x].rs,t[x].tag);
        t[x].tag.init();
        t[x].tg=0;
    }
}

int cnt;

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
	t[x].tag.init();
    if(l==r)
    {
        t[x].v.a[0]=1;
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

void change(int x,int l,int r,const Mat &v)
{
    if(l<=t[x].l&&t[x].r<=r)
    {
        mul(x,v);
        return;
    }
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
        change(t[x].ls,l,r,v);
    if(r>mid)
        change(t[x].rs,l,r,v);
    update(x);
}

int qry(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].v.a[2];
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    int ret=0;
    if(l<=mid)
        ret+=qry(t[x].ls,l,r);
    if(r>mid)
        ret+=qry(t[x].rs,l,r);
    return ret;
}

int n,q,p[N],ans[N*5],pos[N];

vector<pair<int,int> >qr[N*5];

vector<int>fac[N];

Mat SET0,SET1,ADD;

vector<int>st;

int pl[N];

signed main()
{
	ios::sync_with_stdio(false);
    SET0.a[0][0]=1,SET0.a[2][2]=1;
    SET1=SET0,SET1.a[0][1]=1;
    ADD.a[0][0]=ADD.a[1][1]=ADD.a[2][2]=1,ADD.a[1][2]=1;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>p[i],pos[p[i]]=i;
	// for(int i=1;i<=n;i++)
    //     p[i]=i,pos[p[i]]=i;
    build(1,n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            fac[j].push_back(i);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
		// l=rand()%n+1,r=rand()%n+1;
        qr[r].push_back({l,i});
    }
    for(int i=1;i<=n;i++)
        pl[i]=-1;
    for(int i=1;i<=n;i++)
    {
        while(st.size()&&p[i]>p[st.back()])
        {
            pl[p[st.back()]]=-1;
            st.pop_back();
        }
		int L=st.size()?st.back()+1:1,R=i-1;
		if(L<=R)
			change(1,L,R,SET0);
        pl[p[i]]=st.size()?st.back()+1:1;
        st.push_back(i);
        for(auto x:fac[p[i]])
        {
            int y=p[i]/x;
            if(x>=y||pos[x]>i||pos[y]>i)
                continue;
            int L=pl[p[i]];
            int R=min(pos[x],pos[y]);
            if(L<=R)
                change(1,L,R,SET1);
        }
        for(int j=p[i]*2;j<=n;j+=p[i])
        {
            if(pos[j]>i)
                continue;
            if(pl[j]==-1)
                continue;
            int x=p[i],y=j/x;
			if(x==y)
				continue;
            if(pos[x]>i||pos[y]>i)
                continue;
            int L=pl[j];
            int R=min({pos[x],pos[y],pos[j]});
            if(L<=R)
                change(1,L,R,SET1);
        }
        change(1,1,n,ADD);
        for(auto [j,id]:qr[i])
            ans[id]=qry(1,j,i);
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
}
/*
10 1
6 1 3 2 5 8 4 10 7 9
1 4
*/