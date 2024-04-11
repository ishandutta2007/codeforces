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
main(){
	int n, m;
	while(cin >> n){
		REP(i, n){
			if(i) cout << "R";
			cin >> m;
			REP(j, m){
				if(j){
					if(i) cout << "LRP";
					else cout << "RLP";	
				}else cout << "P";
			}
		}
		cout << endl;
	}
	return 0;
}