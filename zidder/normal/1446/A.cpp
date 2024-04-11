#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    long long W;
    cin >> n >> W;
    vector<pair<long long, int>> w(n);
    for (int i=0;i<n;++i){
        scanf("%lld", &w[i].first);
        w[i].second = i + 1;
    }
    sort(w.begin(), w.end());
    long long s = 0;
    vector<int> ans;
    for(int i=n-1;i>=0;--i){
        if (w[i].first >= (W+1)/2 && w[i].first <= W){
            cout << "1\n" << w[i].second << endl;
            return;
        }
        if (s + w[i].first > W)
            continue;
        s += w[i].first;
        ans.push_back(w[i].second);
        if (s >= (W + 1) / 2){
            break;
        }
    }
    if (s < (W+1)/2){
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for(int i:ans)
        cout << i << " ";
    cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}