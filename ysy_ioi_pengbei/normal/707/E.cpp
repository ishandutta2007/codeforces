#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define SZ 2333333
#define S2 2333333
int ch[S2][2],an=0;
ll sum[S2];
void clr()
{
	for(int i=1;i<=an;i++) ch[i][0]=ch[i][1]=sum[i]=0;
	an=0;
}
void ins(int r1,int& r2,int l,int r,int p,int q)
{
	r2=++an;
    sum[r2]=sum[r1]+q;
    if(l==r) return;
    int mid=l+r>>1;
    if(p<=mid) ins(ch[r1][0],ch[r2][0],l,mid,p,q), ch[r2][1]=ch[r1][1];
    else ins(ch[r1][1],ch[r2][1],mid+1,r,p,q), ch[r2][0]=ch[r1][0];
}
ll query(int r1,int r2,int l,int r,int p)
{
    if(l>p) return 0;
    if(sum[r1]==sum[r2]) return 0;
    if(r<=p) return sum[r2]-sum[r1];
    int mid=l+r>>1; ll ans=0;
    ans+=query(ch[r1][0],ch[r2][0],l,mid,min(p,mid));
    if(p>mid) ans+=query(ch[r1][1],ch[r2][1],mid+1,r,p);
    return ans;
}
#define SS 2010
int n,m,k,l,q=0;
struct pnt {int a,b,c;}ps[SZ];
bool operator < (pnt a,pnt b)
{
	return a.a<b.a;
}
bool rq[SS][SS],sta[SS];
int qx1[SS],qx2[SS],qy1[SS],qy2[SS],rs[SS];
int ls[SS],i_[SS][SS],j_[SS][SS],w_[SS][SS];
ll anss[SZ];
int main()
{
	//cout<<(sizeof(ch)+sizeof(sum))/1024.0/1024.0<<"\n";
	scanf("%d%d%d",&n,&m,&k);
	n=max(n,m); m=n; //in case of typo
	for(int i=1;i<=k;i++)
	{
		scanf("%d",ls+i); sta[i]=1;
		for(int j=1;j<=ls[i];j++)
		scanf("%d%d%d",i_[i]+j,j_[i]+j,w_[i]+j);
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		char sb[11];
		scanf("%s",sb);
		if(sb[0]=='S')
		{
			int x; scanf("%d",&x);
			sta[x]^=1; continue;
		}
		++q; scanf("%d%d%d%d",qx1+q,qy1+q,qx2+q,qy2+q);
		for(int j=1;j<=k;j++) rq[q][j]=sta[j];
	}
	for(int i=1;i<=k;i++)
	{
		clr();
		int l=ls[i];
		for(int j=1;j<=l;j++)
		ps[j].a=i_[i][j], ps[j].b=j_[i][j], ps[j].c=w_[i][j];
		sort(ps+1,ps+1+l);
		int cur=1,rr=0,rt=0;
		for(int j=1;j<=n;j++)
		{
			while(cur<=l&&ps[cur].a==j)
			ins(rr,rt,1,m,ps[cur].b,ps[cur].c),
			rr=rt, ++cur;
			rs[j]=rt;
		}
		for(int j=1;j<=q;j++)
		{
			if(!rq[j][i]) continue;
			anss[j]+=query(rs[qx1[j]-1],rs[qx2[j]],1,m,qy2[j]);
			anss[j]-=query(rs[qx1[j]-1],rs[qx2[j]],1,m,qy1[j]-1);
		}
	}
	for(int j=1;j<=q;j++) printf("%I64d\n",anss[j]);
}