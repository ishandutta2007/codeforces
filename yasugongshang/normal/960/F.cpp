#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;
//
// #define f first
// #define s second
// #define mp make_pair
// #define pb push_back
// #define ub upper_bound
// #define lb lower_bound
// #define er erase
// #define en end()
// #define b begin()
// #define i insert
// #define OPTIMIZE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int ll
// #define endl "\n"
// #define nl cout << endl;
// #define DEBUG {int debug ; cin >> debug;}
// #define LEN(x) x.length()
// #define PI 3.1415926535897932384626433832795
// #define MAX 1e6 + 6
// #define MOD 1e9 + 7

typedef long long ll;
// typedef pair<int,int> ii;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<ii> vii;
// typedef set<int> si;
// typedef multiset<int> msi;
// typedef long double ld;
// template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
// int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

bool comparator(int i , int j)
{
    return (i < j);
}

// ll power(ll x, ll i)
// {
// 	ll ans = 1;
// 	while(i > 0)
// 	{
// 		if(i&1)
// 			ans = (ans*x)%MOD;
// 		i >>=1;
// 		x = (x*x)%MOD;
// 	}
// 	return ans;
// }
//
// ll modInverse(ll x, ll mod)
// {
// 	return power(x , mod-2,mod);
// }

// bool isPalindrome(string s)
// {
// 	int limit = s.length()/2;
// 	for(int i =  0 ; i < limit ; i++)
// 	{
// 		if(s[i] != s[s.length()-i-1])
// 			return 0;
// 	}
// 	return true;
// }

ll gcd(ll x, ll y)
{
	ll t;
	while(y != 0)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return x;
}

bool isVowel(char ch)
{

    if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'u' || ch == '0' || ch == 'y'){
        return true;
    }
    return false;
}

bool isPrime(int n)
{
	int root = sqrt(n);
	for(int i = 2 ; i <= root ; i++) if(n%i == 0) return 0;
	return 1;
}

// eratoshenes sieve ...
// Once eratoshtenes is activated, use the isPrime function below it,
// and deactivate above function

/*
int lp[maxn];
vector<int> pr;
void generatePrimes()
{
	for (int i=2; i<=maxn; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back (i);
		}
		for (unsigned j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=maxn;)
		{
			lp[i * pr[j]] = pr[j];
			j++;
		}
	}
	return;
}
bool isPrime(int n)
{
	int root = sqrt(n);
	for(int i = 0 ; i < pr.size() && pr[i] <= root ; i++) if(n%pr[i] == 0) return 0;
	return 1;
}

*/

/////////////////////////
// declaration section //
/////////////////////////
const int mx=(int)1e5+5;
map<int,int> ft[mx];

void update(int node, int idx, int val){
	while(idx<mx){
		ft[idx][node]=max(ft[idx][node], val);
		idx+=(idx & -idx);
	}
}

int get(int node, int idx){
	int ans=0;
	while(idx>0){
		if(ft[idx].count(node))ans=max(ans, ft[idx][node]);
		idx-=(idx & -idx);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;

	int ans=0;
	while(m-->0){
		int a,b,w;
		cin >> a >> b >> w;
		w+=2;
		update(b, w, get(a, w-1)+1);
		ans=max(ans, get(b, w));
	}
	cout << ans;


	return 0;
}