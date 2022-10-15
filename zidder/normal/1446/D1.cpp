#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d", &a[i]);
        a[i]--;
    }
    int mx = a[0], mn=a[0];
    for (int i=1;i<n;++i){
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (mx == mn){
        cout << 0 << endl;
        return;
    }
    vector<int> cnt(100);
    for(int i=0;i<n;++i){
        cnt[a[i]]++;
    }
    
    int mxelem, mxcnt = 0;
    for(int j=0;j<100;++j){
        if (cnt[j] > mxcnt){
            mxcnt = cnt[j];
            mxelem = j;
        }
    }
    int cntmax = 0;
    for (int j=0;j<100;++j){
        cntmax += cnt[j] == mxcnt;
    }
    if (cntmax > 1){
        cout << n << endl;
        return;
    }
    int mxlen = 2;
    for (int j=0;j<100;++j){
        if (j == mxelem)
            continue;
        int df = 0; // cnt j - cnt mxelem
        unordered_map<int, pair<int, int> > mp;
        mp[0] = make_pair(-1, -1);
        for (int i=0;i<n;++i){
            if (a[i] == j)
                df++;
            if (a[i] == mxelem)
                df--;
            if (mp.count(df) == 0)
                mp[df] = make_pair(i, i);
            else
                mp[df].second = i;
        }
        for (auto p: mp){
            mxlen = max(mxlen, (p.second.second - p.second.first));
        }
    }
    cout << mxlen << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}