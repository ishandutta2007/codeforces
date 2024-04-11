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
	
	int a[4] = {1, 6, 8, 9};
	int tbl[100];
	do{
		int x = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
		for(int i=0;i<100;i++) 
			if((x*100 + i)%7 == 0) tbl[i] = x;
	}while(next_permutation(a, a+4));
//	REP(i, 100) cout << ans[i] << endl;
//	return 0;
	string s;
	while(cin >> s){
		bool f[10]={0};
		vector<int> ans;
		FOR(c, s){
			if(*c == '1' || *c == '6' || *c == '8' || *c == '9'){
				if(!f[*c-'0']){
					f[*c-'0'] = 1;
					continue;
				}
			}
			ans.push_back(*c - '0');
		}
		sort(ans.begin(), ans.end());
		vector<int> tmp = ans;
		REP(i, (int)tmp.size() - 2){
			int x = (tmp[i+2]*10 + tmp[i+1] - tmp[i]*2 + 21) % 7;
			tmp[i+2] = x / 10;
			tmp[i+1] = x % 10;
		}
		int x = 0;
		if(tmp.size() == 1) x += tmp[tmp.size()-1]*10;
		else if(tmp.size() != 0) x = tmp[tmp.size()-1]*10 + tmp[tmp.size()-2];
		cout << tbl[x];
		RFOR(c, ans) cout << *c;
		cout << endl;
	}
	return 0;
}