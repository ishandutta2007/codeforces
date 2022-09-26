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

ll c[100001];
int special[100001];
bool good[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin>>n>>k;
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		sum += c[i];
	}
	ll sos = 0; ll sum2 = 0;
	for(int i = 0; i < k; i++)
	{
		cin >> special[i];
		special[i]--;
		good[special[i]] = true;
		sum2 += c[special[i]];
		sos += ll(c[special[i]])*ll(c[special[i]]);
	}
	ll ans = 0;
	for(int i = 0; i < k; i++)
	{
		ans += (sum-c[special[i]])*c[special[i]];
	}
	//cout << sum2 << ' ' << sos << '\n';
	ans -= ((ll(sum2)*sum2)-sos)/2;
	for(int i = 0; i < n; i++)
	{
		if((!good[i])&&(!good[(i+1)%n]))
		{
			ans += ll(c[i])*ll(c[(i+1)%n]);
		}
	}
	cout << ans;
}