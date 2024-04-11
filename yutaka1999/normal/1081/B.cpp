#include <bits/stdc++.h>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int ans[SIZE];
vector <int> pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		pos[n-a].push_back(i);
	}
	int sz=0;
	for(int i=1;i<=n;i++)
	{
		if(pos[i].size()%i!=0)
		{
			puts("Impossible");
			return 0;
		}
		for(int j=0;j<pos[i].size();j++) ans[pos[i][j]]=sz+j/i;
		sz+=pos[i].size()/i;
	}
	puts("Possible");
	for(int i=0;i<n;i++) printf("%d ",ans[i]+1);
	puts("");
	return 0;
}