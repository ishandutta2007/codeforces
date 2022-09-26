#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	if(n % 3 == 0) cout << n/3 * 2;
	else cout << n/3 * 2 + 1;
	return 0;
}