#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, H, x[NN], y[NN];
ld has;
ll belok(ll X1, ll Y1, ll X2, ll Y2)
{
	return (X1 * Y2 - X2 * Y1);
}
ld belok2(ld X1, ld Y1, ld X2, ld Y2)
{
	return (X1 * Y2 - X2 * Y1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> H;
    for(ll i = 1; i <= n; i++)
    	cin >> x[i] >> y[i];
    ll tX = x[n];
    ll tY = y[n];
    ll mX = tX;
    ll mY = tY + H;
    for(ll i = n - 1; i >= 1; i--)
    {
    	ll coba = 200;
    	ld X = x[i];
    	ld Y = y[i];
    	ld dX = (x[i + 1] - x[i]);
    	ld dY = (y[i + 1] - y[i]);
    	ld L = 0, R = 1;
    	ll A = belok(X - mX, Y - mY, tX - mX, tY - mY);
    	ll B = belok(x[i + 1] - mX, y[i + 1] - mY, tX - mX, tY - mY);
    	// cout << i << " " << A << " " << B << "\n";
    	if(A < 0 && B < 0)
    	{

    	}
    	else
    	if(A < 0 && B >= 0)
    	{
	    	while(coba--)
	    	{
	    		ld C = (L + R) / 2.0;
	    		if(belok2(X + dX * C - mX, Y + dY * C - mY, tX - mX, tY - mY) >= 0)
	    			R = C;
	    		else
	    			L = C;
	    	}
    		// cout << i << " " << (1.0 - L) << "\n";
	    	has += (1.0 - L) * sqrt(dX * dX + dY * dY);
    	}
    	else
    	if(A >= 0 && B < 0)
    	{
    		while(coba--)
	    	{
	    		ld C = (L + R) / 2.0;
	    		if(belok2(X + dX * C - mX, Y + dY * C - mY, tX - mX, tY - mY) >= 0)
	    			L = C;
	    		else
	    			R = C;
	    	}
    		// cout << i << " " << L << "\n";
	    	has += L * sqrt(dX * dX + dY * dY);
    	}
    	else
    	{
    		// cout << i << " " << 1<< "\n";
    		has += sqrt(dX * dX + dY * dY);
    	}
    	// cout << i << " " << L << "\n";
    	// cout << tX << " " << tY << "@\n";
    	if(belok(tX - mX, tY - mY, x[i] - mX, y[i] - mY) < 0)
    	{
    		tX = x[i];
    		tY = y[i];
    	}
    }
    cout << fixed << setprecision(10) << has << "\n";
    // cout << tX << " " << tY << "@\n";
}