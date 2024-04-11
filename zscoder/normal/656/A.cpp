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
/*
ll a[36];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("AMAEXPER.in", "r", stdin);
	for(int x = -1000; x <= 1000; x++)
	{
		for(int y = -1000; y <= 1000; y++)
		{
			a[0] = x; a[1] = y;
			for(int i = 0; i < 15; i++)
			{
				if(i >= 2) a[i] = a[i-1]+a[i-2];
			}
			if(a[2] == 8 && a[9] == 1024) cout << x << " " << y << endl;
		}
	}
	return 0;
}
*/
ll a[36] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8092, 16184, 32368, 64736, 129472, 258944, 517888, 1035776, 2071552, 4143104, 8286208, 16572416, 33144832, 66289664, 132579328, 265158656, 530317312, 1060634624LL, 2121269248LL, 4242538496LL, 8485076992LL, 16970153984LL, 33940307968LL};
int main()
{
	int n; cin >> n;
	cout << a[n];
	return 0;
}