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

int n,m;

vector<int> gen_vec(int n){
	vector<int> res(n, 1);
	if(n == 1) return res;
	if(n == 2){
		res[0] = 3;res[1] = 4;
	}else if(n&1){
		res[0] = (n+1)/2;
		res[1] = 2;
	}else{
		res[0] = n/2-1;
	}
	return res;
}

main(){
	scanf("%d%d", &n, &m);
	vector<int> y = gen_vec(n);
	vector<int> x = gen_vec(m);
	REP(i,n)REP(j,m) printf("%d%s", y[i]*x[j], j==m-1?"\n":" ");
	return 0;
}