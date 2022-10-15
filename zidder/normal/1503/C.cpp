#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    long long ans = 0;
    vector<pair<int, int> > ac(n);
    for (int i=0;i<n;++i) scanf("%d%d", &ac[i].first, &ac[i].second);
    sort(ac.begin(), ac.end());
    for (auto &p: ac) ans += p.second;
    int right = ac[0].first;
    for (int i=0;i<n;++i){
        if (right >= ac[i].first)
            right = max(right, ac[i].first + ac[i].second);
        else {
            ans += ac[i].first - right;
            right = ac[i].first + ac[i].second;
        }
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}