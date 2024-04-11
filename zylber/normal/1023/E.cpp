#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(int a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define eps 0.000000000001
typedef long long tint;
using namespace std;
#define MAXN 1000010

int main() {
	int n;
	cin >> n;
	string ans;
	int acti = 1, actj = 1;
	forn(i, n-1) {
		cout << "? " << acti+1 << " " << actj << " " << n << " " << n << endl;
		cout.flush();
		string res;
		cin >> res;
		if(res == "YES") {
			ans += "D";
			acti++;
		} else {
			ans += "R";
			actj++;
		}
	}
	
	string revans;
	acti = n, actj = n;
	forn(i, n-1) {
		cout << "? 1 1 " << acti << " " << actj-1 << endl;
		cout.flush();
		string res;
		cin >> res;
		if(res == "YES") {
			revans += "R";
			actj--;
		} else {
			revans += "D";
			acti--;
		}
	}
	reverse(revans.begin(), revans.end());
	cout << "! " << ans << revans << endl;
}