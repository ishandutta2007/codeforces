#include<bits/stdc++.h>
#define N 200100
using namespace std;

int n,Q,tt;
char str[N];
struct Node
{
    int ls,rs,sum,mn,mx,qa,ha,ans;
    void chg(int u)
    {
	sum=u;
	mn=min(0,u);
	mx=max(0,u);
	qa=ha=ans=1;
    }
}node[N<<1];

inline int zh(char u){return u=='('?-1:1;}
inline void up(int now)
{
    int L=node[now].ls,R=node[now].rs;
    node[now].sum=node[L].sum+node[R].sum;
    node[now].mn=min(node[L].mn,node[L].sum+node[R].mn);
    node[now].mx=max(node[L].mx,node[L].sum+node[R].mx);
    node[now].qa=max(node[L].qa,max(node[L].sum+node[R].qa,node[L].mx*2-node[L].sum-node[R].mn));
    node[now].ha=max(node[R].ha,max(node[L].ha-node[R].sum,node[L].sum-node[L].mn+(node[R].mx*2-node[R].sum)));
    node[now].ans=max(max(node[L].ans,node[R].ans),max(node[L].ha-node[R].mn,node[L].sum-node[L].mn+node[R].qa));
}

void build(int now,int l,int r)
{
    if(l==r)
    {
	node[now].chg(zh(str[l]));
	return;
    }
    int mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
    up(now);
//    cout<<now<<" "<<l<<" "<<r<<":"<<node[now].sum<<"["<<node[now].mn<<","<<node[now].mx<<"]"<<"{"<<node[now].qa<<" "<<node[now].ha<<"}"<<"->"<<node[now].ans<<endl;
}

void chg(int now,int l,int r,int u,int v)
{
    if(l==r)
    {
	node[now].chg(v);
	return;
    }
    int mid=((l+r)>>1);
    if(u<=mid) chg(node[now].ls,l,mid,u,v);
    else chg(node[now].rs,mid+1,r,u,v);
    up(now);
}

int main()
{
    int i,j,p,q;
    cin>>n>>Q;
    n=((n-1)<<1);
    scanf("%s",str+1);
    build(tt=1,1,n);
    cout<<node[1].ans<<endl;
    while(Q--)
    {
	scanf("%d%d",&p,&q);
	if(str[p]!=str[q])
	{
	    swap(str[p],str[q]);
	    chg(1,1,n,p,zh(str[p]));
	    chg(1,1,n,q,zh(str[q]));
	}
	printf("%d\n",node[1].ans);
    }
//    printf("%s",str+1);
}