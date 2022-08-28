#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define INF 100000000000000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll up[SIZE],down[SIZE];
ll left[SIZE],right[SIZE];
ll col[SIZE],row[SIZE];
vector <P> vec;
char str[SIZE];
int n,h,w;

void buildLR()
{
	int now=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='L') now--;
		else if(str[i]=='R') now++;
		if(now<0) left[-now]=min(left[-now],(ll) i+1);
		else right[now]=min(right[now],(ll) i+1);
	}
	if(now>0)
	{
		for(int i=now;i<=w;i++) right[i]=min(right[i],right[i-now]+n);
	}
	else
	{
		for(int i=-now;i<=w;i++) left[i]=min(left[i],left[i+now]+n);
	}
	for(int i=0;i<w;i++)
	{
		row[i]=min(left[i+1],right[w-i]);
		//printf("row %d : %lld\n",i,row[i]);
		vec.push_back(P(row[i],0));
	}
}
void buildUD()
{
	int now=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='U') now--;
		else if(str[i]=='D') now++;
		if(now<0) up[-now]=min(up[-now],(ll) i+1);
		else down[now]=min(down[now],(ll) i+1);
	}
	if(now>0)
	{
		for(int i=now;i<=h;i++) down[i]=min(down[i],down[i-now]+n);
	}
	else
	{
		for(int i=-now;i<=h;i++) up[i]=min(up[i],up[i+now]+n);
	}
	for(int i=0;i<h;i++)
	{
		col[i]=min(up[i+1],down[h-i]);
		//printf("col %d : %lld\n",i,col[i]);
		vec.push_back(P(col[i],1));
	}
}
int main()
{
	scanf("%d %d %d",&n,&h,&w);
	scanf("%s",&str);
	for(int i=0;i<SIZE;i++) left[i]=right[i]=up[i]=down[i]=INF;
	left[0]=right[0]=up[0]=down[0]=0;
	buildLR();
	buildUD();
	sort(vec.begin(),vec.end());
	int zw=w,zh=h;
	ll ret=0;
	for(int i=0;i<vec.size();i++)
	{
		P p=vec[i];
		if(p.first>=INF) break;
		if(p.second==0)
		{
			ret+=(ll) zh*(ll) p.first%MOD;
			if(ret>=MOD) ret-=MOD;
			zw--;
		}
		else
		{
			ret+=(ll) zw*(ll) p.first%MOD;
			if(ret>=MOD) ret-=MOD;
			zh--;
		}
	}
	if(zw>0&&zh>0) puts("-1");
	else printf("%lld\n",ret);
	return 0;
}