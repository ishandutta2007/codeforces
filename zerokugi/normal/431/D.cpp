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
#include <cmath>
#include <ctime>
using namespace std;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
ull C[1010][1010];

void make_C(){
    memset(C, 0, (int)sizeof(C));    
    for(int i = 0; i < 1010; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]);
    }
}

ull m;
int k;

ull count(string s, int k){
	if(!k) return 0;
	int d = s.size();
	s.erase(s.end()-1);
	while(s.size() && *(s.end()-1)=='0') s.erase(s.end()-1);
	ull ans = C[d-1][k];
	if(s.size()) ans += count(s, k-1);
	return ans; 
}
string tostring(ull k){
	string ret = k?"":"0";
	for(;k;k>>=1) ret.push_back('0'+(k&1));
	return ret;
}

ull search(ull m, int k){
	ull l=0, r=1000000000000000000ULL;
	while(l<r-1){
		ull mid = (l+r)/2;
		ull ret = count(tostring(mid*2+1), k) - count(tostring(mid), k);
		if(ret == m) return mid;
		if(ret < m) l = mid;
		else r = mid;
	}
	return 0;
}

main(){
	make_C();
	while(cin >> m >> k){
		cout << search(m, k) << endl;
	}
	return 0;
}