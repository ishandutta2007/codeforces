#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cmath>
#include <map>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int px[SIZE],py[SIZE];
int cx[SIZE],cy[SIZE],cz[SIZE];
P pos[SIZE];
vector <int> vx,vy;
vector <P> vp;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&px[i],&py[i]);
		pos[i]=P(px[i],py[i]);
		vx.push_back(px[i]);
		vy.push_back(py[i]);
		vp.push_back(pos[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	sort(vp.begin(),vp.end());
	vp.erase(unique(vp.begin(),vp.end()),vp.end());
	for(int i=0;i<n;i++)
	{
		px[i]=lower_bound(vx.begin(),vx.end(),px[i])-vx.begin();
		cx[px[i]]++;
		py[i]=lower_bound(vy.begin(),vy.end(),py[i])-vy.begin();
		cy[py[i]]++;
		int p=lower_bound(vp.begin(),vp.end(),pos[i])-vp.begin();
		cz[p]++;
	}
	ll ret=0;
	for(int i=0;i<vx.size();i++)
	{
		ret+=(ll) cx[i]*(ll) (cx[i]-1)/2;
	}
	for(int i=0;i<vy.size();i++)
	{
		ret+=(ll) cy[i]*(ll) (cy[i]-1)/2;
	}
	for(int i=0;i<vp.size();i++)
	{
		ret-=(ll) cz[i]*(ll) (cz[i]-1)/2;
	}
	printf("%lld\n",ret);
	return 0;
}