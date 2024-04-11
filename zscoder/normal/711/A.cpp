#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 1000;
char bus[N][5];

void printbus(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << bus[i][j];
		}
		cout << '\n';
	}
}

void yes()
{
	cout << "YES" << '\n';
}

void no()
{
	cout << "NO" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> bus[i][j];
		}
	}
	bool possible = false;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(bus[i][j*3] == 'O' && bus[i][j*3+1] == 'O')
			{
				bus[i][j*3] = '+';
				bus[i][j*3+1] = '+';
				possible = true;
				break;
			}
		}
		if(possible) break;
	}
	if(!possible)
	{
		no();
		return 0;
	}
	else
	{
		yes();
		printbus(n);
		return 0;
	}
	return 0;
}