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
    vector<int> b(n);
    for (int &i: b) scanf("%d", &i);
    vector<pair<int, int> > ll; // (left, right)
    for (int i=0;i<n;++i) {
        // (i+1) / a[i] = b[i]
        int l, r;
        if (b[i] == 0) {
            l = i + 2;
            r = n;
        } else {
            r = (i + 1) / b[i];
            l = (i + 1) / (b[i] + 1) + 1;
        }
        ll.emplace_back(l, r);
    }
    vector<vector<int> > inds(n + 1);
    for (int i=0;i<n;++i) inds[ll[i].first].push_back(i);
    vector<int> a(n);
    set<pair<int, int> > li; // (rigth, index)
    for (int i=1;i<=n;++i) {
        for (int ind: inds[i]) li.emplace(ll[ind].second, ind);
        a[li.begin()->second] = i;
        li.erase(li.begin());
    }
    for (int i: a) printf("%d ", i);
    printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}