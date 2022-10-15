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
	vector<int> a(n), b(n);
    for (int &i: a) scanf("%d", &i);
    for (int &i: b) scanf("%d", &i);
    vector<pair<pair<int, int>, int> > arr(n);
    for (int i=0;i<n;++i) arr[i] = {{a[i], b[i]}, i};
    sort(arr.begin(), arr.end());
    for (int i=1;i<n;++i) if (arr[i].first.second < arr[i-1].first.second) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int> > moves;

    vector<bool> visited(n, false);
    for (int i=0;i<n;++i) {
        if (visited[i]) continue;
        vector<int> cycle = {i};
        int j = arr[i].second;
        while (j != i) {
            cycle.push_back(j);
            j = arr[j].second;
        }
        for (int j: cycle) visited[j] = true;
        for (int j=1;j<cycle.size();++j) {
            moves.emplace_back(cycle[j], cycle[j-1]);
        }
    }

    cout << moves.size() << endl;;
    for (auto &p: moves) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
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