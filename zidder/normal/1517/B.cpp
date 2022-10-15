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
    vector<pair<int, pair<int, int> > > v;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;j++){
            int x;
            cin >> x;
            v.emplace_back(x, make_pair(j, i));
        }
    }
    swap(n, m);
    sort(v.begin(), v.end());
    vector<vector<int> > ans(n, vector<int> (m, 0));
    for (int i=0;i<n;++i){
        ans[i][v[i].second.second] = v[i].first;
    }
    for (int i=n;i<v.size();++i){
        for(int j=0;j<n;++j){
            if (ans[j][v[i].second.second] == 0){
                ans[j][v[i].second.second] = v[i].first;
                break;
            }
        }
    }
    for (int i=0;i<m;++i){
        for (int j=0;j<n;j++){
            cout << ans[j][i] << " ";
        }
        cout << endl;
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}