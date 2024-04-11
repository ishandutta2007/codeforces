#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005
#define BB 1145143
#define MOD 1000000007
#define BT 20

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
vector <int> get[SIZE];
int par[SIZE][BT],dep[SIZE];
ll hash1[SIZE],hash2[SIZE],rt[SIZE];
int nd[SIZE],nxt[SIZE],id[SIZE],pos[SIZE];
int n1[SIZE],n2[SIZE];
char str[SIZE];
int n,m;

void dfs(int v=0,int p=-1,int d=0,ll h1=0,ll h2=0)
{
	par[v][0]=p;
	dep[v]=d;
	h1*=BB;
	hash1[v]=h1+(str[v]-'a'+1);
	hash2[v]=h2+(ll) (str[v]-'a'+1)*rt[d];
	hash1[v]%=MOD;
	hash2[v]%=MOD;
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v,d+1,hash1[v],hash2[v]);
			nd[v]+=nd[to];
		}
	}
}
void make()
{
	for(int i=0;i<BT-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
ll get1(int s,int t)
{
	int p=par[t][0];
	return (hash1[s]-(p==-1?0:hash1[p]*rt[dep[s]-dep[p]]%MOD)+MOD)%MOD;
}
ll get2(int s,int t)
{
	int p=par[s][0];
	return (hash2[t]-(p==-1?0:hash2[p])+MOD)%MOD;
}
int LCA(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]==-1||dep[par[b][i]]<dep[a]) continue;
		b=par[b][i];
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
int sz;
void heavy_light(int v=0,int p=-1,int last=-1)
{
	bool up=false;
	pos[v]=sz;
	id[v]=get[sz].size();
	nxt[v]=last;
	get[sz].push_back(v);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&nd[to]*2>=nd[v])
		{
			heavy_light(to,v,last);
			up=true;
			break;
		}
	}
	if(!up) sz++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&nd[to]*2<nd[v])
		{
			heavy_light(to,v,v);
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%s",&str);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*(ll) BB%MOD;
	dfs();
	make();
	heavy_light();/*
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<get[i].size();j++) printf("%d ",get[i][j]);
		puts("");
	}*/
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);a--;b--;c--;d--;
		if(str[a]!=str[c])
		{
			puts("0");
			continue;
		}
		int p=LCA(a,b),q=LCA(c,d);
		if(dep[a]-dep[p]>dep[c]-dep[q])
		{
			swap(a,c);
			swap(b,d);
			swap(p,q);
		}
		int A=b,bef=-1;
		while(A!=-1)
		{
			n1[pos[A]]=bef;
			bef=get[pos[A]][0];
			A=nxt[A];
		}
		int C=d;
		bef=-1;
		while(C!=-1)
		{
			n2[pos[C]]=bef;
			bef=get[pos[C]][0];
			C=nxt[C];
		}
		bool up=true;
		int ret=1;
		while(a!=p)
		{
			int ta=nxt[a];
			if(ta==-1||dep[ta]<dep[p]) ta=p;
			int tc=nxt[c];
			if(tc==-1||dep[tc]<dep[q]) tc=q;
			int la=dep[a]-dep[ta],lc=dep[c]-dep[tc];
			int ml=min(la,lc);
			int va=ml==la?ta:get[pos[a]][id[a]-ml];
			int vc=ml==lc?tc:get[pos[c]][id[c]-ml];
			if(get1(a,va)!=get1(c,vc))
			{
				int s=-1,e=ml;
				while(e-s>1)
				{
					int m=(s+e)/2;
					va=get[pos[a]][id[a]-m];
					vc=get[pos[c]][id[c]-m];
					if(get1(a,va)!=get1(c,vc)) e=m;
					else s=m;
				}
				ret+=s;
				up=false;
				break;
			}
			ret+=ml;
			a=va;
			c=vc;
		}
		if(!up)
		{
			printf("%d\n",ret);
			continue;
		}
		while(c!=q&&a!=b)
		{
			int ta=n1[pos[a]];
			if(ta==-1||dep[ta]>dep[b]) ta=b;
			int tc=nxt[c];
			if(tc==-1||dep[tc]<dep[q]) tc=q;
			int la=dep[ta]-dep[a],lc=dep[c]-dep[tc];
			int ml=min(la,lc);
			int va=ml==la?ta:get[pos[a]][id[a]+ml];
			int vc=ml==lc?tc:get[pos[c]][id[c]-ml];
			if(get2(a,va)!=get1(c,vc)*rt[dep[a]]%MOD)
			{
				int s=-1,e=ml;
				while(e-s>1)
				{
					int m=(s+e)/2;
					va=get[pos[a]][id[a]+m];
					vc=get[pos[c]][id[c]-m];
					if(get2(a,va)!=get1(c,vc)*rt[dep[a]]%MOD) e=m;
					else s=m;
				}
				ret+=s;
				up=false;
				break;
			}
			ret+=ml;
			a=va;
			c=vc;
		}
		if(!up)
		{
			printf("%d\n",ret);
			continue;
		}
		while(a!=b&&c!=d)
		{
			int ta=n1[pos[a]];
			if(ta==-1||dep[ta]>dep[b]) ta=b;
			int tc=n2[pos[c]];
			if(tc==-1||dep[tc]>dep[d]) tc=d;
			int la=dep[ta]-dep[a],lc=dep[tc]-dep[c];
			int ml=min(la,lc);
			int va=ml==la?ta:get[pos[a]][id[a]+ml];
			int vc=ml==lc?tc:get[pos[c]][id[c]+ml];
			if(get2(a,va)*rt[dep[c]]%MOD!=get2(c,vc)*rt[dep[a]]%MOD)
			{
				int s=-1,e=ml;
				while(e-s>1)
				{
					int m=(s+e)/2;
					va=get[pos[a]][id[a]+m];
					vc=get[pos[c]][id[c]+m];
					if(get2(a,va)*rt[dep[c]]%MOD!=get2(c,vc)*rt[dep[a]]%MOD) e=m;
					else s=m;
				}
				ret+=s;
				up=false;
				break;
			}
			ret+=ml;
			a=va;
			c=vc;
		}
		printf("%d\n",ret);
	}
	return 0;
}