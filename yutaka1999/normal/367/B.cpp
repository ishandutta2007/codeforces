#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 200005

using namespace std;
typedef long long int ll;

vector <int> vx,ans;
int sum[SIZE*2],now[SIZE*2];
int in[SIZE],ob[SIZE];
int cnt;

void add(int x)
{
	cnt-=sum[x]==now[x];
	now[x]++;
	cnt+=sum[x]==now[x];
}
void rem(int x)
{
	cnt-=sum[x]==now[x];
	now[x]--;
	cnt+=sum[x]==now[x];
}

int main()
{
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	if((ll) (m-1)*(ll) p+1LL>(ll) n)
	{
		puts("0");
		puts("");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		vx.push_back(in[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&ob[i]);
		vx.push_back(ob[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<m;i++)
	{
		ob[i]=lower_bound(vx.begin(),vx.end(),ob[i])-vx.begin();
		sum[ob[i]]++;
	}
	for(int i=0;i<vx.size();i++) if(sum[i]==0) cnt++;
	for(int i=0;i<n;i++) in[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
	for(int i=0;i<p;i++)
	{
		for(int j=i,k=i-m*p;k<n;j+=p,k+=p)
		{
			if(j<n) add(in[j]);
			if(k>=0) rem(in[k]);
			if(cnt==vx.size()) ans.push_back(k+p);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}