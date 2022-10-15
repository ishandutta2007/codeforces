#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> p;

void solve(int test_ind){
    // 
	// 2 3 4 1 6 7 5 9 10 8
    
    // -6 3 4 1 -2 7 5 9 10 8
    // -6 2 4 1 -3 7 5 9 10 8
    // -6 2 3 1 -4 7 5 9 10 8
    // -6 2 3 4 -1 7 5 9 10 8
    // -7 2 3 4 -1 6 5 9 10 8
    // -5 2 3 4 -1 6 7 9 10 8
    // 1 2 3 4 5 6 7 9 10 8
    // -9 2 3 4 5 6 7 -1 10 8
    // -10 2 3 4 5 6 7 -1 9 8
    // -8 2 3 4 5 6 7 -1 9 10
    // 1 2 3 4 5 6 7 8 9 10

    int n;
    cin >> n;
    p = vector<int> (n);
    for (int i=0;i<n;++i) scanf("%d", &p[i]);
    for (int &i: p) --i;

    vector<bool> visited(n);
    vector<vector<int> > cycles;
    vector<int> inplace;
    for (int i=0;i<n;++i) {
        if (visited[i]) continue;
        if (p[i] == i) {inplace.push_back(i); continue;}
        int j = i;
        cycles.emplace_back();
        do {
            j = p[j];
            visited[j] = true;
            cycles.back().push_back(j);
        } while (j != i);
    }
    
    if (cycles.size() == 0) {
        cout << 0 << endl;
        return;
    }

    vector<pair<int, int> > actions;

    auto act = [&](int a, int b){
        actions.emplace_back(a+1, b+1);
        int c = p[a];
        p[a] = -p[b];
        p[b] = -c;
    };

    if (cycles.size() == 1) {
        if (inplace.empty()) {
            // 2 3 4 5 1
            // -3 -2 4 5 1
            // -4 -2 3 5 1
            // -5 -2 3 4 1
            // -5 -1 3 4 2
            // -2 -1 3 4 5
            // 1 2 3 4 5
            for (int i=1;i+1<cycles[0].size();++i) {
                act(cycles[0][i], cycles[0][0]);
            }
            act(cycles[0].back(), cycles[0][1]);
            act(cycles[0].back(), cycles[0][0]);
            act(cycles[0][1], cycles[0][0]);
        } else {
            int a = inplace[0];
            for (int i: cycles[0]) {
                act(a, i);
            }
            act(a, cycles[0][0]);
        }
    } else {
        // 2 3 1 5 4
        // -5 3 1 -2 4
        // -5 2 1 -3 4
        // -5 2 3 -1 4
        // -4 2 3 -1 5
        // 1 2 3 4 5

        for (int i=1;i<cycles.size();i+=2) {
            // cycles[i] and cycles[i-1]
            int a = cycles[i][0];
            for (int j: cycles[i-1]) act(j, a);
            int b = cycles[i-1][0];
            for (int j=1;j<cycles[i].size();++j) act(b, cycles[i][j]);
            act(a, b);
            inplace.push_back(cycles[i][0]);
        }

        if (cycles.size() % 2) {
            int a = inplace[0];
            for (int i: cycles.back()) act(a, i);
            act(a, cycles.back()[0]);
        }
    }

    cout << actions.size() << endl;
    for (auto &p: actions) printf("%d %d\n", p.first, p.second);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
        for (int i=0;i<p.size();++i) if (p[i] != i) throw "erorr";
	}
	return 0;
}