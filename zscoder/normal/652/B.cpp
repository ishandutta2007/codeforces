#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;
vi vec;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int  x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.pb(x);
	}
	sort(vec.begin(), vec.end());
	int a = 0; int b = n - 1;
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			cout << vec[a];
			a++;
		}
		else
		{
			cout << vec[b];
			b--;
		}
		cout << " ";
	}
	return 0;
}