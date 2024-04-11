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
    vector<vector<int> > g(n);
    for(int i=0; i < m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x-1].push_back(y-1);
    }
    set<int> ans;
    vector<set<int> > rg(n);
    vector<set<int> > fg(n);
    for(int i=0;i<n;++i){
        for (int j :g[i]){
            rg[j].insert(i);
            fg[i].insert(j);
        }
    }
    map<int, long long> ends;
    for(int i=0;i<n;++i){
        for(int j: fg[i]){
            for(int k: fg[j])
                ends[k]++;
        }
    }
    while(ends.size()){
        int rm = ends.begin()->first;
        if (ends[rm] <= 0){
            ends.erase(rm);
            continue;
        }
        for (int j: fg[rm]){
            rg[j].erase(rm);
            for(int k: fg[j]){
                ends[k]--;
            }
            if (rg[rm].size() != 0){
                ends[j] -= (int)rg[rm].size();
            }
        }
        ends.erase(rm);
        ans.insert(rm);
    }
    if (ans.size() > 4 * n / 7){
        throw "nnoooo";
    }
    cout << ans.size() << endl;
    for(auto i:ans)
        cout << i + 1 << " ";
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