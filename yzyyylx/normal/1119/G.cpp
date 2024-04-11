#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 1001000
using namespace std;

int n,m,K,sum;
P num[N];
vector<int>cz[N];
priority_queue<P>pq;

inline bool judge(int u)
{
    int i,res=0;
    for(i=1;i<=min(K,m);i++) res+=num[i].fi/u;
//    cerr<<" "<<i<<endl;
    return res>=K;
}

inline void work(int u)
{
    int i,j,k,t,cnt=K;
    cz[0].push_back(u);
//    cerr<<cz[0].size()<<endl;
//    for(i=1;i<=m;i++) cout<<num[i].fi<<" ";puts("");
    for(i=1;cnt&&i<=min(m,K);i++)
    {
	t=min(cnt,num[i].fi/u);
	num[i].fi-=t*u;
	cnt-=t;
	for(j=1;j<=t;j++) cz[cz[0].size()].push_back(num[i].se);
    }
//    cerr<<" "<<i<<endl;
    for(;cnt;cnt--) cz[cz[0].size()].push_back(1);
}

int main()
{
    int i,j,l,r,mid;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
	scanf("%d",&num[i].fi);
	num[i].se=i;
	sum+=num[i].fi;
    }
    K=(sum+n-1)/n;
    n-=m;
//    cout<<" "<<K<<endl;
    for(i=1;i<=m;i++) pq.push(num[i]);
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=min(m,K);j++) num[j]=pq.top(),pq.pop();
	for(l=1,r=min(num[1].fi,n)+1;l<r;)
	{
	    mid=((l+r)>>1);
	    if(judge(mid+1)) l=mid+1;
	    else r=mid;
	}
	int t=l-1;
	work(t+1);
	n-=t;
	for(j=1;j<=min(m,K);j++) pq.push(num[j]);
//	if(i%100==0) cerr<<i<<endl;
    }
    if(n) cz[0][0]+=n;
    cout<<K<<endl;
    for(i=0;i<m;i++) printf("%d ",cz[0][i]);puts("");
    for(i=0;i<K;i++)
    {
	for(j=1;j<=m;j++) printf("%d ",cz[j][i]);
	puts("");
    }
}