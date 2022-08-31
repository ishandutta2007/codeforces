#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define SQR 320

using namespace std;
typedef long  long int ll;

vector <int> vec[SIZE];
vector <int> big;
int cnt[SQR][SIZE],id[SIZE];
ll ans[SIZE],in[SIZE];
bool ok[SIZE];
ll pl[SQR],add[SIZE];
char str[5];

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++) scanf("%I64d",&in[i]);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		ans[i]=0;
		for(int j=0;j<a;j++)
		{
			int b;
			scanf("%d",&b);b--;
			vec[i].push_back(b);
			ans[i]+=in[b];
		}
		if(a>=SQR)
		{
			id[i]=big.size();
			big.push_back(i);
		}
	}
	for(int i=0;i<big.size();i++)
	{
		int v=big[i];
		memset(ok,false,sizeof(ok));
		for(int j=0;j<vec[v].size();j++) ok[vec[v][j]]=true;
		for(int j=0;j<m;j++)
		{
			cnt[i][j]=0;
			for(int k=0;k<vec[j].size();k++) cnt[i][j]+=ok[vec[j][k]];
		}
	}
	for(int i=0;i<q;i++)
	{
		scanf("%s",&str);
		if(str[0]=='?')
		{
			int a;
			scanf("%d",&a);a--;
			ll ret=ans[a];
			for(int j=0;j<big.size();j++) ret+=(ll) cnt[j][a]*(ll) pl[j];
			if(vec[a].size()>=SQR) printf("%I64d\n",ret);
			else
			{
				for(int j=0;j<vec[a].size();j++) ret+=add[vec[a][j]];
				printf("%I64d\n",ret);
			}
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;
			if(vec[a].size()>=SQR) pl[id[a]]+=(ll) b;
			else
			{
				for(int j=0;j<big.size();j++) ans[big[j]]+=(ll) cnt[j][a]*(ll) b;
				for(int j=0;j<vec[a].size();j++) add[vec[a][j]]+=(ll) b;
			}
		}
	}
	return 0;
}