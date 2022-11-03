#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, m, A, B, a[NN];
ll cek(ll bts)
{
	ll tam = 0;
	for(ll i = bts; i >= 1; i--)
	{
		// cout << bts << " " << a[i] + tam << "@\n";
		if(a[i] + tam >= B - 1)
			return 0;
		tam++;
	}
	return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> m >> A >> B;
    	if(A > B)
    	{
    		A = n - A + 1;
    		B = n - B + 1;
    	}
    	// cout << A << " " << B << "_\n";
    	ll has = 0;
    	for(ll i = 1; i <= m; i++)
    		cin >> a[i];
    	sort(a + 1, a + 1 + m);
    	ll L = 0, R = min(m, (B - A - 1));
    	while(L <= R)
    	{
    		ll C = (L + R) / 2;
    		if(cek(C))
    		{
    			has = C;
    			L = C + 1;
    		}
    		else
    			R = C - 1;
    	}
    	// cout << B - A - 1 << "\n";
    	// for(ll i = 1; i <= min((B - A - 1), m); i++)
    	// {
    	// 	ll ta = a[i];
    	// 	cout << ta + i - 1 << "   " << B - 1 << "\n";
    	// 	if(ta + i - 1 <= B - 1)
    	// 		has++;
    	// }
    	cout << has << "\n";
    }
}