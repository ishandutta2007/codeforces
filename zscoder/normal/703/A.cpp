#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int a = 0; int b = 0;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x > y) a++;
		else if(x < y) b++;
	}
	if(a < b) cout << "Chris";
	else if(a > b) cout << "Mishka";
	else cout << "Friendship is magic!^^";
}