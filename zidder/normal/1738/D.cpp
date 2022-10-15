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
    int c0=0, cn=0;
    for (int i=0;i<n;++i) {
        if (b[i] == 0) c0++;
        if (b[i] == n+1) cn++;
    }
    if (c0 == n) {
        printf("0\n");
        for (int i=1;i<=n;++i) printf("%d ", i);
        printf("\n");
        return;
    }
    if (cn == n) {
        printf("%d\n", n);
        for (int i=1;i<=n;++i) printf("%d ", i);
        printf("\n");
        return;
    }

    int k = 0;

    for (int i=1;i<=n;++i) {
        if (i <= b[i-1]) k = i;
    }

    vector<vector<int> > nxt(n+2);
    for (int i=0;i<n;++i) nxt[b[i]].push_back(i+1);
    int cur = 0;
    if (nxt[0].empty()) cur = n+1;
    vector<int> ans;
    while (cur >= 0) {
        for (int i: nxt[cur]) {
            if (nxt[i].empty()) ans.push_back(i);
        }
        int sz = ans.size();
        for (int i: nxt[cur]) {
            if (!nxt[i].empty()) {
                ans.push_back(i);
                cur = i;
            }
        }
        if (ans.size() == sz) break;
    }
    printf("%d\n", k);
    for (int i: ans) printf("%d ", i);
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