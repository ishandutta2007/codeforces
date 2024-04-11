#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

inline LL read()
{
    LL x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define maxx(a,b) ((a)<(b)?(b):(a))
#define MID(a,b) (((a)+(b))>>1)
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

const int maxn=(int) 1e5+20;
const int INF= 200000000;

char str[maxn];

struct node
{
    int a[26];
    int sor;
};
node tree[maxn<<2];

inline void mer(int id)
{
    for(int i=0;i<26;i++) tree[id].a[i]=tree[id<<1].a[i]+tree[id<<1|1].a[i];
}

inline node mer(node a,node b)
{
    node ret;
    memset(ret.a,0,sizeof(ret.a));
    ret.sor=0;
    for(int i=0;i<26;i++) ret.a[i]=a.a[i]+b.a[i];
    return ret;
}

void build(int l,int r,int id)
{
    tree[id].sor=0;
    if(l==r)
    {
        memset(tree[id].a,0,sizeof(tree[id].a));
        int t=str[l]-'a';
        tree[id].a[t]++;
        return ;
    }
    int mid=MID(l,r);
    build(lson);
    build(rson);
    mer(id);
}

inline void magic_lazy(node &p,node &t,int cnt,int sor)
{
    memset(t.a,0,sizeof(t.a));
    if(sor==-1)
    {
        for(int i=0;i<26;i++)
        {
            if(cnt>p.a[i])
            {
                cnt-=p.a[i];
                t.a[i]+=p.a[i];
                p.a[i]=0;
            }
            else
            {
                p.a[i]-=cnt;
                t.a[i]+=cnt;
                break;
            }
        }
    }
    if(sor==1)
    {
        for(int i=25;i>=0;i--)
        {
            if(cnt>p.a[i])
            {
                cnt-=p.a[i];
                t.a[i]+=p.a[i];
                p.a[i]=0;
            }
            else
            {
                p.a[i]-=cnt;
                t.a[i]+=cnt;
                break;
            }
        }
    }
}

node Q;
inline void magic_change(node &t,int cnt,int sor)
{
    memset(t.a,0,sizeof(t.a));
    if(sor==-1)
    {
        for(int i=0;i<26;i++)
        {
            if(cnt>Q.a[i])
            {
                cnt-=Q.a[i];
                t.a[i]+=Q.a[i];
                Q.a[i]=0;
            }
            else
            {
                Q.a[i]-=cnt;
                t.a[i]+=cnt;
                break;
            }
        }
    }
    if(sor==1)
    {
        for(int i=25;i>=0;i--)
        {
            if(cnt>Q.a[i])
            {
                cnt-=Q.a[i];
                t.a[i]+=Q.a[i];
                Q.a[i]=0;
            }
            else
            {
                Q.a[i]-=cnt;
                t.a[i]+=cnt;
                break;
            }
        }
    }
}

inline void lazy(int l,int r,int id)
{
    int mid=MID(l,r);
    int llen=mid-l+1, rlen=r-mid;
    node t=tree[id];
    if(tree[id].sor==-1)
    {
        magic_lazy(t,tree[id<<1],llen,-1);
        magic_lazy(t,tree[id<<1|1],rlen,-1);
    }
    if(tree[id].sor==1)
    {
        magic_lazy(t,tree[id<<1],llen,1);
        magic_lazy(t,tree[id<<1|1],rlen,1);
    }
    tree[id<<1].sor=tree[id<<1|1].sor=tree[id].sor;
    tree[id].sor=0;
}

void update(int type,int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R)
    {
        magic_change(tree[id],r-l+1,type);
        tree[id].sor=type;
        return ;
    }
    if(tree[id].sor) lazy(l,r,id);
    int mid=MID(l,r);
    if(L<=mid) update(type,L,R,lson);
    if(mid<R) update(type,L,R,rson);
    mer(id);
}

node query(int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R) return tree[id];
    if(tree[id].sor) lazy(l,r,id);
    int mid=MID(l,r);
    if(R<=mid) return query(L,R,lson);
    else if(mid<L) return query(L,R,rson);
    else return mer(query(L,R,lson),query(L,R,rson));
}

void print(int l,int r,int id)
{
    if(l==r)
    {
        for(int i=0;i<26;i++) if(tree[id].a[i])
        {
            putchar(i+'a');
            break;
        }
        return ;
    }
    if(tree[id].sor) lazy(l,r,id);
    int mid=MID(l,r);
    print(lson);
    print(rson);
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n,m;
    str[0]='$';
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%s",str+1);
        build(1,n,1);
//        print(1,n,1);
//        cout <<endl;
        for(int i=0;i<m;i++)
        {
            int a=read(), b=read(), c=read();
            if(c) c=-1;
            else c=1;
            Q=query(a,b,1,n,1);
//            for(int i=0;i<26;i++) cout <<Q.a[i] <<" ";cout <<endl;
            update(c,a,b,1,n,1);
//            for(int i=0;i<26;i++) cout <<Q.a[i] <<" ";cout <<endl;
//            cout <<endl;
        }
        print(1,n,1);
        puts("");
    }
    return 0;
}