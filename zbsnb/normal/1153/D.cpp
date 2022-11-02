#include<iostream>
#include<algorithm>
using namespace std;
struct
{
	int u, v, nxt;
}e[1000010];
int head[500010], cnt;
void add(int u, int v) { e[++cnt] = { u,v,head[u] }; head[u] = cnt; }

int tag[500010];
int sum;
int dfs(int u)
{
	if (head[u] == 0)
	{
		sum++;
		return 1;
	}
	int ret = 0;
	if (tag[u] == 1)
	{
		int minn = 1e9;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			minn = min(minn, dfs(v));
		}
		ret = minn;
	}
	else
	{
		int sum = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			sum += dfs(v);
		}
		ret = sum;
	}
	return ret;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> tag[i];
	for (int i = 2; i <= n; i++)
	{
		int tmp; cin >> tmp;
		add(tmp, i);
	}
	int ans = -dfs(1);
	ans += sum + 1;
	cout << ans << endl;
}