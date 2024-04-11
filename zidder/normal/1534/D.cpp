#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<vector<int> > d;
    int n;
    set<pair<int, int> > edges;

void ask(int v){
    cout << "? " << v + 1 << endl;
    fflush(stdout);
    for (int i=0;i<n;++i){
        cin >> d[v][i];
        if (d[v][i] == 1)
            edges.emplace(min(v, i), max(v, i));
    }
}

void solve(int test_ind){
    cin >> n;
    d = vector<vector<int> > (n, vector<int>(n, -1));
    
    int v=0;
    ask(0);
    
    vector<int> even, odd;

    for (int i=1;i<n;++i){
        if (d[0][i] % 2) odd.push_back(i);
        else even.push_back(i);
    }

    vector<int> a = even;
    if (a.size() > odd.size()) a = odd;
    
    for (int i: a) ask(i);

    cout << "!" << endl;
    for (auto p: edges) cout << p.first + 1 << " " << p.second + 1 << endl;
    fflush(stdout);
    return;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}