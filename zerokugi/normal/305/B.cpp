#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
#define REP(i, n) for(int i=0;i<(int)n;i++)
#define REPS(i, n) for(int i=1;i<=(int)n;i++)
#define RREP(i, n) for(int i=n-1;i>=0;i--)
#define RREPS(i, n) for(int i=n;i>0;i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const int MOD = 1000000007;
ll p, q;
int n;

int main(){
	cin >> p >> q >> n;
	REP(i, n){
		ll x;
		cin >> x;
		if((long double)q*x > (long double)p + 1e-8){
			cout << "NO" << endl;
			return 0;
		}
		p -= q*x;
		swap(p, q);
	}
	cout << (q ? "NO" : "YES") << endl;
	return 0;
}