#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map <int , int> m;

int n;
int x[100010];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		m.clear();
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		sort(x + 1 , x + n + 1);
		for(int i = 1; i <= n; i++)
		{
			if(m[x[i]] == 1)
			{
				if(!m[x[i] + 1])
					ans++;
				m[x[i] + 1] = 1;
			}
			else
			{
				if(!m[x[i]])
					ans++;
				m[x[i]] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}