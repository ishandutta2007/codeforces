#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int idx = 0;
	if(a*b < n)
	{
		cout << -1;
		return 0;
	}
	else
	{
		if(b % 2 == 1)
		{
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					idx++;
					if(idx <= n) cout << idx << " ";
					else cout << 0 << " ";
				}
				cout << "\n";
			}
		}
		else if(a % 2 == 1)
		{
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					idx = a*j+i+1;
					if(idx <= n) cout << idx << " ";
					else cout << 0 << " ";
				}
				cout << "\n";
			}
		}
		else
		{
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					if(i % 2)
					{
						idx = b*i+j+1;
						if(j % 2)
						{
							idx--;
						}
						else
						{
							idx++;
						}
					}
					else
					{
						idx = b*i+j+1;
					}
					if(idx <= n) cout << idx << " ";
					else cout << 0 << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/