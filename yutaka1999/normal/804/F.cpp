#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#define MX 2000005
#define SIZE 5005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char mp[SIZE][SIZE];
ll C[SIZE][SIZE];
vector <int> nd[SIZE];
vector <int> vs;
int cmb[SIZE];
bool use[SIZE];
char str[MX];
string A[SIZE];
string B[SIZE];
P pos[SIZE];
int n;

void init()
{
	for(int i=0;i<SIZE;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=MOD) C[i][j]%=MOD;
		}
	}
}
int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<n;i++) if(!use[i]&&mp[v][i]=='1') dfs(i);
	vs.push_back(v);
}
void rdfs(int v,int k)
{
	use[v]=true;
	cmb[v]=k;
	nd[k].push_back(v);
	for(int i=0;i<n;i++) if(!use[i]&&mp[i][v]=='1') rdfs(i,k);
}
int scc()
{
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=n-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
	return k;
}
int main()
{
	init();
	int a,b;
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	for(int i=0;i<n;i++)
	{
		int DM;
		scanf("%d %s",&DM,&str);
		A[i]=str;
	}
	int sz=scc();
	int nm=0;
	for(int i=0;i<sz;i++)
	{
		//for(int j=0;j<nd[i].size();j++) printf("%d ",nd[i][j]);puts("");
		int g=i>0?B[i-1].size():0;
		for(int j=0;j<nd[i].size();j++)
		{
			int v=nd[i][j];
			g=gcd(g,A[v].size());
		}
		for(int j=0;j<g;j++) B[i]+="0";
		if(i>0)
		{
			for(int j=0;j<B[i-1].size();j++)
			{
				if(B[i-1][j]=='1')
				{
					B[i][j%g]='1';
				}
			}
		}
		for(int j=0;j<nd[i].size();j++)
		{
			int v=nd[i][j];
			for(int k=0;k<A[v].size();k++)
			{
				if(A[v][k]=='1')
				{
					B[i][k%g]='1';
				}
			}
		}
		for(int j=0;j<nd[i].size();j++)
		{
			int v=nd[i][j];
			int a=0,b=0;
			for(int k=0;k<A[v].size();k++)
			{
				if(A[v][k]=='1') a++;
				if(B[i][k%g]=='1') b++;
			}
			pos[nm++]=P(b,a);
		}
		//printf("%s\n",B[i].c_str());
	}
	sort(pos,pos+n);
	priority_queue <int> que;
	ll ret=0;
	int cnt=0;
	a--,b--;
	for(int i=n-1;i>=0;i--)
	{
		P p=pos[i];
		while(!que.empty()&&que.top()>p.first)
		{
			cnt++;
			que.pop();
		}
		//printf("%d %d : %d %d\n",p.first,p.second,i,cnt);
		for(int j=0;j<=min(b,cnt);j++)
		{
			int zb=b-j;
			if(zb<=que.size()&&b+(cnt-j)<=a)
			{
				ll way=C[que.size()][zb]*C[cnt][j]%MOD;
				ret+=way;
				if(ret>=MOD) ret-=MOD;
			}
		}
		que.push(p.second);
	}
	printf("%lld\n",ret);
	return 0;
}