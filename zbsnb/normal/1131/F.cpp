#include<iostream>
#include<algorithm>
using namespace std;
int fa[150010];
int son[150010];
int pre[150010];
int nxt[150010];
int findfa(int x) { return pre[x] == x ? x : pre[x] = findfa(pre[x]); }
int findson(int x) { return nxt[x] == x ? x : nxt[x] = findson(nxt[x]); }
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)pre[i] = fa[i] = nxt[i] = son[i] = i;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		int x = findson(a), y = findfa(b);
		pre[y] = fa[y] = x;
		nxt[x] = son[x] = y;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (fa[i] == i)ans = i;
	cout << ans << " ";
	while (son[ans]!=ans)
	{
		cout << son[ans] <<" ";
		ans = son[ans];
	}
	cout << endl;
}