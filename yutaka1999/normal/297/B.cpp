#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

vector <int> a,b;
vector <int> vx;
int ua[SIZE],ub[SIZE];
int diff[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a.push_back(x);
		vx.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		b.push_back(x);
		vx.push_back(x);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	memset(ua,0,sizeof(ua));
	memset(ub,0,sizeof(ub));
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(vx.begin(),vx.end(),a[i])-vx.begin();
		ua[a[i]]++;
	}
	for(int i=0;i<m;i++)
	{
		b[i]=lower_bound(vx.begin(),vx.end(),b[i])-vx.begin();
		ub[b[i]]++;
	}
	int len=(int) vx.size()+1;
	for(int i=0;i<len;i++) diff[i]=ua[i]-ub[i];
	for(int i=len-1;i>=0;i--)
	{
		if(diff[i]>0)
		{
			printf("YES\n");
			return 0;
		}
		if(i>0) diff[i-1]+=diff[i];
	}
	printf("NO\n");
	return 0;
}