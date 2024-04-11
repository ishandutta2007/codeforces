#include <bits/stdc++.h>
using namespace std;
 
 
struct NODE{
	int x, y;
} ans[200005*2];
 
char s[200005], t[200005];
int n, ant = 0, cnt1 = 0, cnt2 = 0;
int f01[200005], f10[200005];
 
int main()
{
	cin >> n;
	scanf("%s%s", s+1, t+1);
	for(int i = 1; i <= n; i++)
	{
		if (s[i] != t[i])
		{
			if (s[i] == 'a') f01[++cnt1] = i;
			else f10[++cnt2] = i;
		}
	}
	for(int i = 1; i+1 <= cnt1; i+=2)
	{
		ant++;
		ans[ant].x = f01[i];
		ans[ant].y = f01[i+1];
	}
	for(int i = 1; i+1 <= cnt2; i+=2)
	{
		ant++;
		ans[ant].x = f10[i];
		ans[ant].y = f10[i+1];
	}
	if (cnt1 & 1 > 0 || cnt2 & 1 > 0)
	{
		ant++;
		ans[ant].x = f01[cnt1];
		ans[ant].y = f01[cnt1];
		ant++;
		ans[ant].x = f01[cnt1];
		ans[ant].y = f10[cnt2];
	}
	if ( (cnt1 & 1) + (cnt2 & 1) == 1 )
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ant << endl;
	for(int i = 1; i <= ant; i++)
	{
		cout << ans[i].x << ' ' << ans[i].y << endl;
	}
	return 0;
}