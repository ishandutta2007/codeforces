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

int n;
vector<int> t;

bool check(int k){
	vector<int> m(k);
	REP(i, t.size()){
		if(m[i%k]++ > t[i]) return false;
	}
	return true;
}

main(){
	int i,j;
	while(cin >> n){
		t.clear();
		REP(i, n){
			int x;
			cin >> x;
			t.push_back(x);
		}
		sort(t.begin(), t.end());
		REP(i, n){
			if(check(i+1)){
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}