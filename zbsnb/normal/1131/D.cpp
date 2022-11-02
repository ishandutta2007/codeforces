#include<iostream>
#include<algorithm>
using namespace std;

char a[1010][1010];
int rank1[2050];
int x[1010];
int y[1010];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char tmp;scanf("%c", &tmp);
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = 0, flg = 0;
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '>')sum++;
			if (a[i][j] == '=')flg = 1;
		}
		x[i] = rank1[i] = sum * 2 + flg;
	}
	for (int i = 1; i <= m; i++)
	{
		int maxn = -10; int flg = 1;
		for (int j = 1; j <= n; j++)
		{
			if (a[j][i] == '<')
			{
				maxn = max(maxn, x[j]);
			}
			if (a[j][i] == '=')
			{
				y[i] = rank1[i + n] = x[j];
				flg = 0;
				break;
			}
		}
		if (flg) y[i] = rank1[i + n] = maxn + 1;
	}
	for(int i = 1;i <= n;i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '=' && x[i] != y[j])
			{
				cout << "No" << endl;
				return 0;
			}
			if (a[i][j] == '<' && x[i] >= y[j])
			{
				cout << "No" << endl;
				return 0;
			}
			if (a[i][j] == '>' && x[i] <= y[j])
			{
				cout << "No" << endl;
				return 0;
			}
		}
	cout << "Yes" << endl;
	sort(rank1 + 1, rank1 + n + m + 1);
	int size = unique(rank1 + 1, rank1 + n + m + 1) - rank1 - 1;
	for (int i = 1; i <= n; i++)
	{
		cout << lower_bound(rank1 + 1, rank1 + size + 1, x[i]) - (rank1 + 1) + 1<< " ";
	}
	cout << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << lower_bound(rank1 + 1, rank1 + size + 1, y[i]) - (rank1 + 1) + 1<< " ";
	}
	cout << endl;
}