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
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, k;

main(){
	scanf("%d", &n);
	vi data(n, 0), v(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		v[i] = x-1;
	}
	vector<int> head;
	REP(i, n){
		if(data[i]) continue;
		head.push_back(i+1);
		for(int j=i;!data[j];){
			data[j] = 1;
			j = v[j];
		}
	}
	scanf("%d", &k);
	int t = n - head.size() - k;
	printf("%d\n", abs(t));
	if(t > 0){
		REP(i, n){
			while(v[i] != i){
				int mini = v[i];
				for(int j=v[v[i]];j!=i;j=v[j]) mini = min(mini, j);
				printf("%d %d ", i+1, mini+1);
				swap(v[i], v[mini]);
				if(--t == 0) return 0;
			}
		}
	}else if(t < 0) REP(i, -t) printf("%d %d ", head[0], head[i+1]);
	return 0;
}