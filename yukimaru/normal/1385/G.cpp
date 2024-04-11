/*********************************************************************
    > File Name: 1385_G.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		vector<vector<int>> a(3, vector<int>(n+1));
		vector<int> num(n+1, 0);
		vector<vector<int>> pos(n+1);
		for(int i=1; i<=2; i++)
			for(int j=1; j<=n; j++) 
			{
				scanf("%d", &a[i][j]);
				num[a[i][j]]++;
				pos[a[i][j]].push_back(j);
			}
		bool f=1;
		for(int i=1; i<=n; i++)
			if(num[i] != 2)
			{
				f=0;
				break;
			}
		if(!f)
		{
			printf("-1\n");
			continue;
		}
		vector<bool> vis(n+1, 0);
		vector<int> ans;
		for(int i=1; i<=n; i++)
		{
			if(vis[i]) continue;
			if(pos[i][0] == pos[i][1]) continue;
			vector<int> tmp1, tmp2;
			for(int j=i, k=pos[i][0]; !vis[j]; )
			{
//				printf("!%d %d\n", j, k);
				vis[j]=1;
				k=k^pos[j][0]^pos[j][1];
				if(a[1][k] == j)
				{
					tmp1.push_back(k);
					j=a[2][k];
				}
				else
				{
					tmp2.push_back(k);
					j=a[1][k];
				}
			}
//			for(auto i : tmp1) printf("%d ", i); printf("\n");
//			for(auto i : tmp2) printf("%d ", i); printf("\n");
			if(tmp1.size() <= tmp2.size())
				ans.insert(ans.end(), tmp1.begin(), tmp1.end());
			else ans.insert(ans.end(), tmp2.begin(), tmp2.end());
		}
		printf("%d\n", (int)ans.size());
		for(auto i : ans) printf("%d ", i);
		printf("\n");
	}
	return 0;
}