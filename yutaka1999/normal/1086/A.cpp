#include <bits/stdc++.h>
#define SIZE 1005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int X[SIZE],Y[SIZE];
bool use[SIZE][SIZE];

int main()
{
	vector <int> vx,vy;
	for(int i=0;i<3;i++)
	{
		scanf("%d %d",&X[i],&Y[i]);
		vx.push_back(X[i]);
		vy.push_back(Y[i]);
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	int a=vx[1],b=vy[1];
	for(int i=0;i<3;i++)
	{
		int x=X[i],y=Y[i];
		use[x][y]=true;
		while(x!=a)
		{
			use[x][y]=true;
			if(a<x) x--;
			else x++;
		}
		while(y!=b)
		{
			use[x][y]=true;
			if(y<b) y++;
			else y--;
		}
		use[x][y]=true;
	}
	vector <P> ans;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(use[i][j]) ans.push_back(P(i,j));
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}