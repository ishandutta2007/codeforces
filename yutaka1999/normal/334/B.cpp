#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int x[10],y[10];
bool mp[10][10];
vector <int> vx,vy;

int main()
{
	for(int i=0;i<8;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	for(int i=0;i<8;i++)
	{
		x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin();
		y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin();
		mp[x[i]][y[i]]=true;
	}
	int sum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==1&&j==1) continue;
			sum+=mp[i][j];
		}
	}
	if(sum==8) puts("respectable");
	else puts("ugly");
	return 0;
}