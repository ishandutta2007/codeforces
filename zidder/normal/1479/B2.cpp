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
    vector<int> a(n), a1;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n;++i) if (a1.empty() || a1.back() != a[i]) a1.push_back(a[i]);
    a = a1;
    n = a.size();
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    int ans = 1;
    int l = a[0], r = 0;
    for (int i=1;i<n;++i){
        if (a[i] == l || a[i] == r)
            continue;
        set<int> s;
        s.insert(l);
        s.insert(r);
        int ind=0;
        for (int j=i;j<n;++j){
            if (s.find(a[j]) != s.end()){
                ind = j;
                break;
            }
            s.insert(a[j]);
        }
        if (ind == 0){
            cout << ans + n-i << endl;
            return;
        }
        l = a[ind];
        r = a[ind-1];
        ans += ind - i;
        i = ind;
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