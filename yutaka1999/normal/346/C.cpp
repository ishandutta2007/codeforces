#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1000005
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int last[SIZE];
vector <int> vec;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		vec.push_back(a);
	}
	int a,b;
	scanf("%d %d",&a,&b);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=0;i<=a-b;i++) last[i]=i-1;
	for(int i=0;i<vec.size();i++)
	{
		int p=vec[i];
		int f=((b+p-1)/p)*p-b;
		f--;
		if(f<0) f+=p;
		for(;f<=a-b;f+=p) if(f-p+1>=0) last[f]=min(last[f],f-p+1);
		if(f-p+1>=0) last[a-b]=min(last[a-b],f-p+1);
	}
	for(int i=a-b-1;i>=0;i--) last[i]=min(last[i],last[i+1]);
	int cnt=0,now=a-b;
	while(now>0)
	{
		now=last[now];
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}