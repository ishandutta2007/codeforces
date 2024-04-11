#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n, m;
int in(){
	int x;
	cin >> x;
	return x;
}
main(){
	int i,j;
	while(cin >> n){
		vector<int> v;
		int sum[2] = {0};
		REP(i, n){
			cin >> m;
			REP(j, m/2)	sum[0] += in();
			if(m&1) v.push_back(in());
			REP(j, m/2)	sum[1] += in();
		}
		sort(v.rbegin(), v.rend());
		REP(i, v.size()) sum[i&1] += v[i];
		cout << sum[0] << " " << sum[1] << endl;
	}
	return 0;
}