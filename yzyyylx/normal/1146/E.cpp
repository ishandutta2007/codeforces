#include<bits/stdc++.h>
#define N 200100
#define MN 100000
using namespace std;

int n,m,tt,num[N];
char str[5];
struct Node
{
    int ls,rs,dw,ad;
    void chg(int u){ad=0,dw=u;}
    void add(){if(dw) dw=-dw;else ad^=1;}
}node[N<<1];

inline void down(int now)
{
    int L=node[now].ls,R=node[now].rs;
    if(node[now].dw)
    {
	node[L].chg(node[now].dw);
	node[R].chg(node[now].dw);
	node[now].dw=0;
	return;
    }
    if(node[now].ad)
    {
	node[L].add();
	node[R].add();
	node[now].ad=0;
    }
}

void build(int now,int l,int r)
{
    if(l==r)
    {
	if(l<=MN) node[now].dw=-1;
	else node[now].dw=1;
	return;
    }
    int mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
}

void chg(int now,int l,int r,int u,int v,int w)
{
//    if(now==1) cout<<"chg:"<<u-MN<<" "<<v-MN<<" "<<w<<endl;
    if(u>v) return;
    if(u<=l&&r<=v)
    {
	node[now].chg(w);
	return;
    }
    down(now);
    int mid=((l+r)>>1);
    if(u<=mid) chg(node[now].ls,l,mid,u,v,w);
    if(mid<v) chg(node[now].rs,mid+1,r,u,v,w);
}

void add(int now,int l,int r,int u,int v)
{
//    if(now==1) cout<<"add:"<<u-MN<<" "<<v-MN<<endl;
    if(u>v) return;
    if(u<=l&&r<=v)
    {
	node[now].add();
	return;
    }
    down(now);
    int mid=((l+r)>>1);
    if(u<=mid) add(node[now].ls,l,mid,u,v);
    if(mid<v) add(node[now].rs,mid+1,r,u,v);
}

int ask(int now,int l,int r,int u)
{
    if(l==r) return node[now].dw;
    down(now);
    int mid=((l+r)>>1);
    if(u<=mid) return ask(node[now].ls,l,mid,u);
    return ask(node[now].rs,mid+1,r,u);
}

int main()
{
    int i,j,t;
    cin>>n>>m;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    build(tt=1,0,MN*2);
    while(m--)
    {
	scanf("%s%d",str+1,&t);
	if(str[1]=='<')
	{
	    t--;
	    if(t<=0)
	    {
		chg(1,0,MN*2,0,t+MN,1);
		chg(1,0,MN*2,MN-t,MN*2,1);
	    }
	    else
	    {
		chg(1,0,MN*2,0,MN-t-1,1);
		chg(1,0,MN*2,MN+t+1,MN*2,1);
		add(1,0,MN*2,MN-t,MN+t);
	    }
	}
	else
	{
	    t++;
	    if(t>=0)
	    {
		chg(1,0,MN*2,0,MN-t,-1);
		chg(1,0,MN*2,MN+t,MN*2,-1);
	    }
	    else
	    {
		chg(1,0,MN*2,0,MN+t-1,-1);
		chg(1,0,MN*2,MN-t+1,MN*2,-1);
		add(1,0,MN*2,MN+t,MN-t);
	    }
	}
    }
    for(i=1;i<=n;i++) printf("%d ",abs(num[i])*ask(1,0,MN*2,num[i]+MN));
}