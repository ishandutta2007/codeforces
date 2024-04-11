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
#define printTime cout<<"Time:"<<clock()-pre<<endl;pre=clock();
#define OK puts("OK")
const int inf=~0U>>1,maxn=100000+100,maxs=400;
using namespace std;
struct TBlock
{
    int A[maxs*3],Max,n;
    TBlock*l,*r;
    void init(){n=0;}
    void add(int x)
    {
        A[n++]=x;
    }
    void doit()
    {
        Max=0;
        rep(i,n)
        {
            Max=max(Max,A[i]);
        }
    }
}Mem[maxs*2];
TBlock*Stack[maxs*2];
TBlock*h=new TBlock,*t=new TBlock;
int top=0;
void init_Mem()
{
    rep(i,maxs*2)
        Stack[i]=Mem+i;
    top=maxs*2;
}
TBlock*New_Block()
{
    return Stack[--top];
}
void Del_Blcok(TBlock*b)
{
    Stack[top++]=b;
}
TBlock* Split(TBlock*p,int pos)
{
    if(pos==0)return p;
    TBlock*R=New_Block();
    R->init();
    for(int t=pos;t<p->n;t++)
    {
        R->add(p->A[t]);
    }
    p->n-=R->n;
    R->l=p;R->r=p->r;R->l->r=R;R->r->l=R;
    R->doit();p->doit();
    return R;
}
void Find(int kth,TBlock*&p,int&pos)
{
    p=h->r;pos=kth;
    for(;p!=t;)
    {
        if(pos>=p->n)pos-=p->n,p=p->r;
        else return;
    }
}
int cnt;
void Merge(TBlock*p)//p and p->r
{
    if(p->r==t)return;
    TBlock*R=p->r;
    rep(i,R->n)
    {
        p->add(R->A[i]);
    }
    p->doit();
    p->r=R->r;p->r->l=p;
    Del_Blcok(R);
}
int Get_P(int a)
{
    int p=cnt-1;
    for(TBlock*it=t->l;it!=h;)
    {
        if(it->Max<a)
        {
            p-=it->n;it=it->l;
        }
        else
        {
            for(int j=it->n-1;j>=0;j--)
                if(it->A[j]<a)p--;
                else return p;
        }
    }
    return -1;
}
void Mantain(TBlock*p)
{
    if(p->n>2*maxs)
    {
        Split(p,maxs);
    }
    else
    {
        if(p->r!=t&&p->n+p->r->n<2*maxs)
        {
            Merge(p);
        }
    }
}
void Insert(int p,int a)
{
    TBlock*t;int pos;
    Find(p,t,pos);
    t=Split(t,pos);
    if(t->l==h)
    {
        TBlock*nt=New_Block();
        nt->init();
        nt->l=h;nt->r=t;
        nt->l->r=nt;nt->r->l=nt;
    }
    t->l->add(a);
    t->l->doit();
    Mantain(t->l);
}
int num[maxn];
void output()
{
    for(TBlock*p=h->r;p!=t;p=p->r)
    {
        rep(i,p->n)
            cout<<num[p->A[i]]<<" ";
    }
    cout<<endl;
}
int n;
int main()
{
    //freopen("in","r",stdin);
    init_Mem();
    h->r=t;t->l=h;
    int a,c;cin>>n;cnt=0;
    rep(i,n)
    {
        //cout<<i<<endl;
        scanf("%d%d",&a,&c);
        num[a]=i+1;
        int p=max(cnt-c,Get_P(a)+1);
        cnt++;
        Insert(p,a);
    }
    output();
}