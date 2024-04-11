#include <bits/stdc++.h>

using namespace std;

int T;
int n;
char c[310][310];
char t[310][310];

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int k = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> c[i][j];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(c[i][j] != '.')
					k++;
		int flag = false;
		for(int k1 = 0; k1 <= 2; k1++)
		{
			for(int k2 = 0; k2 <= 2; k2++)
				if(k1 != k2)
				{
					for(int i = 1; i <= n; i++)
						for(int j = 1; j <= n; j++)
							t[i][j] = c[i][j];
					for(int i = 1; i <= n; i++)
						for(int j = 1; j <= n; j++)
							if(c[i][j] != '.' && (i + j) % 3 == k1)
								t[i][j] = 'X';
					for(int i = 1; i <= n; i++)
						for(int j = 1; j <= n; j++)
							if(c[i][j] != '.' && (i + j) % 3 == k2)
								t[i][j] = 'O';
					int f = false;
					for(int i = 1; i <= n; i++)
						for(int j = 1; j <= n - 2; j++)
							if(t[i][j] == t[i][j + 1] && t[i][j + 1] == t[i][j + 2] && t[i][j] != '.')
								f = true;
					for(int i = 1; i <= n - 2; i++)
						for(int j = 1; j <= n; j++)
							if(t[i][j] == t[i + 1][j] && t[i + 1][j] == t[i + 2][j] && t[i][j] != '.')
								f = true;
					int temp = 0;
					for(int i = 1; i <= n; i++)
						for(int j = 1; j <= n; j++)
							if(c[i][j] != t[i][j])
								temp++;
					if(temp > k / 3)
						f = true;
					if(!f)
					{
						flag = true;
						break;
					}
				} 
			if(flag)
				break;
		}
		for(int i = 1; i <= n; i++ , cout << endl)
			for(int j = 1; j <= n; j++)
				cout << t[i][j];
	}
	return 0;
}