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
    vector<int> d1(n), d2(n);
    for (int &i: d1) scanf("%d", &i);
    for (int &i: d2) scanf("%d", &i);
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    bool swp = false;
    if (d1.back() < d2.back()) {swap(d1, d2);swp=true;}

    int p1 = 0;
    int e1 = d1.back();
    auto trial = [&](int p2) -> bool {
        multiset<int> D1, D2;
        for (int i: d1) D1.insert(i);
        for (int i: d2) D2.insert(i);
        D1.erase(D1.find(e1));
        D2.erase(D2.find(abs(p2-e1)));
        vector<int> h;
        h.push_back(e1);
        int d = abs(p1 - p2);
        while (!D1.empty()) {
            if (*D1.rbegin() > *D2.rbegin()) {
                h.push_back(p1 + *D1.rbegin());
                if (*D1.rbegin() < d) {
                    int tmp = d - *D1.rbegin();
                    D1.erase(D1.find(*D1.rbegin()));
                    if (D2.find(tmp) == D2.end()) return false;
                    D2.erase(D2.find(tmp));
                } else {
                    int tmp = *D1.rbegin() - d;
                    D1.erase(D1.find(*D1.rbegin()));
                    if (D2.find(tmp) == D2.end()) return false;
                    D2.erase(D2.find(tmp));
                }
            } else {
                h.push_back(p2 - *D2.rbegin());
                if (*D2.rbegin() < d) {
                    int tmp = d - *D2.rbegin();
                    D2.erase(D2.find(*D2.rbegin()));
                    if (D1.find(tmp) == D1.end()) return false;
                    D1.erase(D1.find(tmp));
                } else {
                    int tmp = *D2.rbegin() - d;
                    D2.erase(D2.find(*D2.rbegin()));
                    if (D1.find(tmp) == D1.end()) return false;
                    D1.erase(D1.find(tmp));
                }
            }
        }
        int mn = 0;
        for (int i: h) mn = min(i, mn);
        printf("YES\n");
        for (int i: h) printf("%d ", i-mn);
        printf("\n");
        if (swp) {
            printf("%d %d\n", p2-mn, p1-mn);
        } else {
            printf("%d %d\n", p1-mn, p2-mn);
        }
        return true;
    };

    for (int i: d2) {
        if (trial(e1 + i)) return;
        if (trial(e1 - i)) return;
    }
    printf("NO\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}