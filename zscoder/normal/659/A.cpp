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
	a = (a+b)%n;
	if(a <= 0) a += n;
	cout << a;
	return 0;
}