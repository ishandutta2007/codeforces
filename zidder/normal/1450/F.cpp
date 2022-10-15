#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    scanf("%d", &n);
    vector<int> v(n);
    map<int, int> mp;
    int mxcnt = 0, mxx=0;
    for (int i=0;i<n;++i){
        scanf("%d", &v[i]);
        mp[v[i]]++;
        if (mxcnt < mp[v[i]]){
            mxcnt = mp[v[i]];
            mxx = v[i];
        }

    }
    if (mxcnt * 2 > n + 1){
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    map<int, int> mrc;
    for (int i=1;i<n;++i){
        if (v[i] != v[i-1])
            continue;
        ans++;
        mrc[v[i]] += 2;
    }
    mrc[v.back()]++;
    mrc[v[0]]++;
    int mmrc = v[0];
    for (auto p: mrc){
        if (p.second > mrc[mmrc])
            mmrc = p.first;
    }
    int aans = -2 + mrc[mmrc];
    mrc[v.back()]--;
    mrc[v[0]]--;
    aans -= 2 * ans - mrc[mmrc];
    if (v[0] != mmrc)
        aans--;
    if (v.back() != mmrc)
        aans--;
    cout << ans + (aans>0?aans/2:0) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}