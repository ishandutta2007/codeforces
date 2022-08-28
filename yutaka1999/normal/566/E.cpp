#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 1005
#define M1 1000000007LL
#define M2 1000000009LL
#define B1 892373LL
#define B2 7821434LL

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> PT;
typedef pair <int,int> P;
typedef pair <PT,int> PP;

set <int> st[SIZE];
set <int>::iterator it;
PT hs[SIZE];
int cnt[SIZE],par[SIZE];
bool use[SIZE];
vector <P> ans;
ll r1[SIZE],r2[SIZE];
P now[SIZE];
PP vt[SIZE];
int n;

void init()
{
	r1[0]=r2[0]=1;
	for(int i=1;i<SIZE;i++)
	{
		r1[i]=r1[i-1]*B1%M1;
		r2[i]=r2[i-1]*B2%M2;
	}
}
PT rem(PT p,int v)
{
	p.first-=r1[v];
	if(p.first<0) p.first+=M1;
	p.second-=r2[v];
	if(p.second<0) p.second+=M2;
	return p;
}
void solve()
{
	int zan=0;
	for(int i=0;i<n;i++) zan+=!use[i];
	//if(n>=50) printf("* %d\n",zan);
	bool up=true;
	for(int i=0;i<n;i++) if(!use[i]&&st[i].size()<zan) up=false;
	if(up)
	{
		int rt=-1;
		//for(int i=0;i<n;i++) if(cnt[i]>0) printf("[%d %d] ",i,par[i]);
		for(int i=0;i<n;i++) if(cnt[i]>0&&par[i]!=-1&&i!=rt) rt=par[i];
		if(rt==-1) {for(int i=0;i<n;i++) if(cnt[i]>0) rt=i;}
		//printf("%d\n",rt);
		for(int i=0;i<n;i++) if(cnt[i]>0&&rt!=i) ans.push_back(P(i,rt));
		return;
	}
	int all=0;
	for(int i=0;i<n;i++) if(!use[i]) vt[all++]=PP(hs[i],i);
	sort(vt,vt+all);
	for(int i=0;i<all;)
	{
		int f=i,g=vt[f].second;
		for(;i<all&&vt[i].first==vt[f].first;i++);
		if(st[g].size()==i-f+2&&st[g].size()<zan)
		{
			int sz=0;
			for(it=st[g].begin();it!=st[g].end();it++)
			{
				int t=*it;
				now[sz++]=P(cnt[t],t);
			}
			sort(now,now+sz);
			int rt=now[i-f].second,R=now[i-f+1].second;
			cnt[rt]-=i-f,cnt[R]-=i-f;
			for(int j=0;j<i-f;j++)
			{
				int v=now[j].second;
				if(par[v]==R) swap(rt,R);
			}
			for(int j=0;j<i-f;j++) cnt[now[j].second]=0;
			for(int j=0;j<n;j++) if(cnt[j]>0&&par[j]==rt) swap(rt,R);
			//for(int j=0;j<i-f;j++) printf("%d ",now[j].second);printf(": %d %d\n",rt,R);
			par[rt]=R;
			for(int j=0;j<i-f;j++)
			{
				int v=now[j].second;
				ans.push_back(P(v,rt));
				for(int k=0;k<n;k++)
				{
					if(st[k].count(v))
					{
						st[k].erase(v);
						hs[k]=rem(hs[k],v);
					}
				}
				//printf("* %d ",v);
			}
			//printf(": %d %d\n",rt,R);
			for(int j=f;j<i;j++)
			{
				st[vt[j].second].clear();
				hs[vt[j].second]=PT(0,0);
				use[vt[j].second]=true;
			}
			solve();
			return;
		}
	}
	//...
	puts("NONO");
	return;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);
		ll a=0,b=0;
		for(int j=0;j<c;j++)
		{
			int v;
			scanf("%d",&v);v--;
			st[i].insert(v);
			cnt[v]++;
			a+=r1[v];
			if(a>=M1) a-=M1;
			b+=r2[v];
			if(b>=M2) b-=M2;
		}
		hs[i]=PT(a,b);
	}
	memset(par,-1,sizeof(par));
	solve();
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	return 0;
}