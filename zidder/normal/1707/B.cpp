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
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    vector<int> b(n-1);
    for (int i=0;i<n-1;++i) b[i] = a[i+1] - a[i];
    sort(b.begin(), b.end());
    if (n == 2) {
        cout << b[0] << endl;
        return;
    }

    map<int, int> c;
    for (int i=0;i<b.size();++i) {
        c[b[i]]++;
    }

    auto mv = [&](map<int, int> &c) {
        map<int, int> c1;
        int prev = -1;
        for (auto &p : c) {
            if (prev != -1) {
                c1[p.first - prev]++;
            }
            if (p.second > 1) c1[0] += p.second - 1;
            prev = p.first;
        }
        return c1;
    };

    while (c.size() != 1) {
        c = mv(c);
        // for (auto &p: c) cout << p.first << " " << p.second << endl; cout << endl;
    }
    if (c.begin()->second > 1) {
        cout << 0 << endl;
    } else {
        cout << c.begin()->first << endl;
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