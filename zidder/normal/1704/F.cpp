#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct S {
    char c;
    int cnt;
    int ends;
    S(){};
    S(char cc, int ccnt, int e): c(cc), cnt(ccnt), ends(e){}
};

void solve(int test_ind){
	int n;
    cin >> n;
    string s;
    cin >> s;
    char c = '-';
    int cnt = 0;
    vector<S> C; // ()
    for (int i=0;i<n;++i) {
        if (s[i] == c) {
            cnt++;
        } else {
            if (c != '-') C.push_back(S(c, cnt, 0));
            c = s[i];
            cnt = 1;
        }
    }
    C.push_back(S(c, cnt, 0));
    
    for (int i=0;i<C.size();++i) {
        C[i].ends = (i > 0) + (i + 1 < C.size());
    }

    int cr = 0, cb = 0;
    for (int i=0;i<C.size();++i) {
        if (C[i].c == 'R') cr += C[i].cnt;
        else cb += C[i].cnt;
    }

    if (cr > cb) {
        cout << "Alice" << endl;
        return;
    }
    if (cr < cb) {
        cout << "Bob" << endl;
        return;
    }
    // cr = cb

    // odd moves

    vector<int> edges; // bitmasks (removes left, removes right)
    for (int i=0;i+1<C.size();++i) {
        if (C[i].cnt == 1 && C[i+1].cnt == 1 && C[i].ends > 1 && C[i+1].ends > 1) {
            edges.push_back(3);
            continue;
        }
        if (C[i].cnt == 1 && C[i].ends > 1) {
            edges.push_back(1);
        } else if (C[i+1].cnt == 1 && C[i+1].ends > 1) {
            edges.push_back(2);
        } else edges.push_back(0);
    }

    vector<int> cs;
    for (int i:edges) {
        if (i == 0) cs.push_back(1);
        if (i == 2) cs.push_back(2);
        if (i == 3) cs[cs.size()-1]++;
    }
    int mx = 0;
    for (int i: cs) mx = max(mx, i);

    vector<int> g = {0, 1, 1};
    g.reserve(100000);
    for (int i=3;i<=mx;++i) {
        vector<int> v = {g[i-2], g[i-3]};
        for (int j=2;j<=min((i+1)/2, 90);++j){
            v.push_back(g[j-1] ^ g[i-j-2]);
        }
        sort(v.begin(), v.end());
        int grr = 0;
        for (int j: v) {
            if (j == grr) grr++;
            if (j > grr) break;
        }
        g.push_back(grr);
    }

    int gr = 0;
    for (int i: cs) gr ^= g[i];

    if (gr == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}