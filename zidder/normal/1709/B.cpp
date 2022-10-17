#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int &i: c) scanf("%d", &i);
    vector<long long> l(n), r(n);
    for (int i=0;i<n-1;++i) l[i+1] = l[i] + max(c[i+1] - c[i], 0);
    for (int i=0;i<n-1;++i) r[i+1] = r[i] + max(c[i] - c[i+1], 0);
    for (int i=0;i<m;++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        --s;--t;
        if (s < t) printf("%lld\n", r[t] - r[s]);
        else printf("%lld\n", l[s] - l[t]);
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}