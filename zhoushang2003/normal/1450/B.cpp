#include <bits/stdc++.h>

using namespace std;

int t;
int n , k;
int a[110] , b[110];
int fa[110];

int dis(int i , int j)
{
	return abs(a[i] - a[j]) + abs(b[i] - b[j]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i] >> b[i];
		int ans = -1;
		for(int i = 1; i <= n; i++)
		{
			int flag = true;
			for(int j = 1; j <= n; j++)
				if(dis(i , j) > k)
				{
					flag = false;
					break;
				}
			if(flag == true)
			{
				ans = 1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;

}