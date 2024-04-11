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

int gcd(int a,int b){
	return b>0?gcd(b,a%b):a;
}

const int INF = 1<<27;
int n, m;
set<int> bad;
int isBad(int t){
	if(t == 1) return 0;
	return bad.count(t) ? -1:1;
}

int f(int t){
	if(t==1) return 0;
	int p = 0;
//for(int i=2;i*i<=t;i++) if(t%i == 0) return f(t/i) + isBad(i);
	for(int j=2;j*j<=t;){
		if(t%j == 0){
			while(t%j == 0){
				p += isBad(j);
				t /= j;
			}
		}else j++;
	}
	return p + isBad(t);
}


main(){
	scanf("%d%d", &n, &m);
	vector<int> data(n);
	REP(i, n) scanf("%d", &data[i]);
	REP(i, m){
		int t;
		scanf("%d", &t);
		bad.insert(t);
	}
	vector<int> g(n);
	g[0] = data[0];
	REP(i, n-1) g[i+1] = gcd(g[i], data[i+1]);
	int dived = 1;
	int sum = 0;
	REP(i, n) sum += f(data[i]);
	for(int i=n-1;i>=0;i--){
		int t = g[i]/dived;
		int p = 0;
		for(int j=2;j*j<=t;){
			if(t%j == 0){
				while(t%j == 0){
					p += isBad(j);
					t /= j;
				}
			}else j++;
		}
		p += isBad(t);
		
		if(p < 0){
			dived = g[i];
			sum -= p*(i+1);
		}
	}
	printf("%d\n", sum);
	return 0;
}

// 2*2 2*2*5 2*17 2*5 2*5