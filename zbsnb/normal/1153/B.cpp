#include<iostream>
#include<algorithm>
using namespace std;
int a[100][100];
int main()
{
	int n, m, h; cin >> n >> m >> h;
	for (int i = 1; i <= m; i++)
	{
		int tmp; cin >> tmp;
		for (int j = 1; j <= n; j++)a[j][i] = tmp;
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp; cin >> tmp;
		for (int j = 1; j <= m; j++)a[i][j] = min(a[i][j], tmp);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int tmp; cin >> tmp;
			if (tmp)cout << a[i][j] << " ";
			else cout << "0 ";
		}
		cout << endl;
	}
}