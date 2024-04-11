#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = ll(1e18);
const int MOD = 1e9 + 7;

string tanks[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> tanks[i];
	}
	int special = -1;
	char num;
	int zeroes = 0;
	bool is_zero = false;
	for(int i = 0; i < n; i++)
	{
		num = '0';
		for(int j = 0; j < tanks[i].length(); j++)
		{
			if(j == 0)
			{
				if(tanks[i][j] == '0')
				{
					is_zero = true;
					break;
				}
				else if(tanks[i][j] != '1')
				{
					special = i;
					break;
				}
			}
			else
			{
				if(tanks[i][j] != '0')
				{
					special = i;
					zeroes -= j - 1;
					break;
				}
				else
				{
					zeroes++;
				}
			}
		}
		if(is_zero)
		{
			break;
		}
	}
	if(is_zero)
	{
		cout << 0 << endl;
	}
	else
	{
		if(special != -1)
		{
			cout << tanks[special];
		}
		else{
			cout << 1;
		}
		for(int i = 0; i < zeroes; i++)
		{
			cout << 0;
		}
	}
	return 0;
}