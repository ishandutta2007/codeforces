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
main(){
	int i,j;
	while(cin >> n){
		vector<pii> data;
		REP(i, n){
			int x;
			cin >> x;
			data.push_back(pii(x, i+1));
		}
		sort(data.rbegin(), data.rend());
		cout << data[0].second << " " << data[1].first << endl;
	}
	return 0;
}