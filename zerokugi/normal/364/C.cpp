#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

int n;

void check(vector<int> in, int p){
	int res = 0;
	REP(i, n) if(!(in[i]%p)) res ++;
	printf("mod %d is %d\n", p, res);
}
main(){
	int i,j;
	while(cin >> n){
		vector<int> ans;
		for(int i=2;i<2*n*n;i*=2){
			if(5 < n){
				for(int j=i;j<2*n*n;j*=3){
					if(50 < n){
						for(int k=j;k<2*n*n;k*=5)
							for(int k2=k;k2<2*n*n;k2*=7){
								if(500 < n){
									for(int k3=k2;k3<2*n*n;k3*=11)
										ans.push_back(k3);
								}else ans.push_back(k2);
							}
					}else ans.push_back(j);
				}
			}else ans.push_back(i);
		}
		sort(ans.rbegin(), ans.rend());
		REP(i, n-1) cout << ans[i] << " ";
		cout << ans[n-1] << endl;
	}
	return 0;
}