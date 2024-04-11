#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << " is " << x << endl;
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
#define scan scanf
#define print printf
#define mp make_pair
#define ones __builtin_popcountll
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}

ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	if(a == 0) return b;
	else if(b == 0) return a;
    return b ? gcd(b, a%b) : a;
}
//__gcd(value1, value2)
//

/*ll power(ll base, ll exp)
{
	ll ans = 1;
    while (exp != 0) 
	{
        if (exp % 2) 
		{    // q is odd
            ans = (ans * base)%MOD;
			exp--;
        }
        base = (base * base)%MOD;
        exp /= 2;
    }
	ans %= MOD;
	if(ans < 0)
	{
		ans += MOD;
	}
    return ans;
}
*/

/*
ll choose(ll n, ll r)
{
	if(r == 0)
	{
		return 1;
	}
	if(n == r)
	{
		return 1;
	}
	long long denom = 1;
	for (long long i = 2; i <= r; i++)
	{
		denom = (denom * i) % MOD;
	}
	long long res = 1;
	for (long long i = n; i > n - r; i--) 
	{
		res = (res * i) % MOD;
	}
	res = (res * power(denom, p- 2)) % MOD;
	return res;
}
*/
string p1[12] = {"XA","BA","BA","BX","XB","CB","CB","CX","XC","AC","AC","AX"};
string p2[12] = {"BC","XC","CX","CA","CA","XA","AX","AB","AB","XB","BX","BC"};
string q1[12] = {"XA","CA","CA","CX","XC","BC","BC","BX","XB","AB","AB","AX"};
string q2[12] = {"CB","XB","BX","BA","BA","XA","AX","AC","AC","XC","CX","CB"};
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	string a1,a2;
	string b1,b2;
	cin>>a1>>a2;
	cin>>b1>>b2;
	//cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
	bool pos = true;
	for(int i = 0; i < 12; i++)
	{
		//cout << i << " " << p1[i] << " " << p2[i] << " " << q1[i] << " " << q2[i] << endl;
		if(p1[i] == a1)
		{
			if(p2[i] == a2)
			{
				//cout << i << endl;
				break;
			}
		}
		if(q1[i] == a1)
		{
			if(q2[i] == a2)
			{
				pos = false;
				break;
			}
		}
	}
	bool pos2 = true;
	for(int i = 0; i < 12; i++)
	{
		if(p1[i] == b1)
		{
			if(p2[i] == b2)
			{
				//cout << i << endl;
				break;
			}
		}
		if(q1[i] == b1)
		{
			if(q2[i] == b2)
			{
				pos2 = false;
				break;
			}
		}
	}
	if(pos2 == pos) cout << "YES";
	else cout << "NO";
	return 0;
}


/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/