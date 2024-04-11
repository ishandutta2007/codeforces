#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

typedef pair<int, int> pii;
int n, k,m;
main(){
	map<int, int> se;
	cin >> n >> k;
	vector<int> a(n), b(n);
	vector<int> arr(k);
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	REP(i, n) b[i] = a[i]-b[i]*k;
	int ans = -1;
	se[0] = 0;
	for(int i=0;i<n;i++){
		map<int, int> tmp = se;
		FOR(it, se){
			tmp[it->first + b[i]] = max(it->second + a[i], tmp[it->first + b[i]]);
		}
		se = tmp;
	}
	printf("%d\n", se[0] ? se[0] : -1);
	return 0;
}