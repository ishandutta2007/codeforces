#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const int N=100010,mod=1000000007;
int n;
long long f[N][2]={};
vector<int> v[N];
void init()
{
	scanf("%d",&n);
	for(int i=2,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		v[x].push_back(i);
	}
}
void dfs(int s)
{
	for(vector<int>::iterator it=v[s].begin();it!=v[s].end();++it)
		dfs(*it);
	
	sort(v[s].begin(),v[s].end());
	long long d[2][2]={{1,0},{0,0}},tmp=1;
	int pre=1,now=0;
	for(vector<int>::iterator it=v[s].begin();it!=v[s].end();++it)
	{
		swap(pre,now);
		d[now][1]=(d[pre][1]*f[*it][0] + d[pre][0]*f[*it][1])%mod;
		d[now][0]=(d[pre][0]*f[*it][0] + d[pre][1]*f[*it][1])%mod;
	}
	f[s][0]+=d[now][1]*2;
	f[s][1]+=d[now][0]*2;
	
	d[0][0]=1,d[0][1]=d[1][0]=d[1][1]=0;
	pre=1,now=0;
	for(vector<int>::iterator it=v[s].begin();it!=v[s].end();++it)
	{
		swap(pre,now);
		d[now][1]=(d[pre][1] + d[pre][0]*f[*it][1])%mod;
		d[now][0]=(d[pre][0] + d[pre][1]*f[*it][1])%mod;
	}
	f[s][0]-=d[now][1];
	
	for(vector<int>::iterator it=v[s].begin();it!=v[s].end();++it)
		tmp=(tmp*f[*it][0])%mod;
	f[s][1]-=tmp;
	
	f[s][0]=(f[s][0]%mod+mod+1)%mod;
	f[s][1]=(f[s][1]%mod+mod)%mod;
	//cout<<"s="<<s<<" f[s][0]="<<f[s][0]<<" f[s][1]="<<f[s][1]<<endl<<endl;
}
void work()
{
	dfs(1);
	cout<<(f[1][0]+f[1][1]-1)%mod<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}