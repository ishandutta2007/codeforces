#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, d12, d23, d13;
    cin >> n >> d12 >> d23 >> d13;
    if ((d12 + d23 + d13)%2){
        printf("NO\n");
        return;
    }
    if (d12 > d23 + d13 || d13 > d12 + d23 || d23 > d12 + d13) {
        printf("NO\n");
        return;
    }
    vector<int> mp(n+1);
    for (int i=0;i<=n;++i) mp[i] = i;
    if (d13 == d12 + d23) {
        mp[1] = 1;
        mp[2] = 3;
        mp[3] = 2;
        swap(d13, d12);
    }
    else if (d23 == d12 + d13) {
        mp[1] = 2;
        mp[2] = 3;
        mp[3] = 1;
        int dd12 = d12, dd13 = d13, dd23 = d23;
        d12 = dd23;
        d23 = dd13;
        d13 = dd12;
    }
    if (d12 == d23 + d13) {
        vector<pair<int, int> > edges;
        set<int> others;
        for (int i=4;i<=n;++i) others.insert(i);
        int prev = 1;
        for (int i=1;i<d13;++i){
            int v = *others.begin();
            others.erase(v);
            edges.emplace_back(prev, v);
            prev = v;
        }
        edges.emplace_back(prev, 3);
        prev = 3;
        for (int i=1;i<d23;++i){
            int v = *others.begin();
            others.erase(v);
            edges.emplace_back(prev, v);
            prev = v;
        }
        edges.emplace_back(prev, 2);
        for (int i: others) {
            edges.emplace_back(i, 1);
        }
        printf("YES\n");
        for (auto &p: edges) {
            printf("%d %d\n", mp[p.first], mp[p.second]);
        }
        return;
    }
    if (d13 < d12 + d23) {
        mp[1] = 1;
        mp[2] = 3;
        mp[3] = 2;
        swap(d13, d12);
    }
    else if (d23 < d12 + d13) {
        mp[1] = 2;
        mp[2] = 3;
        mp[3] = 1;
        int dd12 = d12, dd13 = d13, dd23 = d23;
        d12 = dd23;
        d23 = dd13;
        d13 = dd12;
    }
    if (d12 < d23 + d13 && (d12 + d23 + d13) % 2 == 0) {
        int k = (d23 + d13 - d12) / 2;
        if (k + d12 + 1 <= n && d13 - k < d12 && d23 - k < d12) {
            vector<pair<int, int> > edges;
            set<int> others;
            for (int i=4;i<=n;++i) others.insert(i);
            int prev = 1;
            for (int i=1;i<d12;++i){
                int v = *others.begin();
                others.erase(v);
                edges.emplace_back(prev, v);
                prev = v;
            }
            edges.emplace_back(prev, 2);
            prev = edges[d13-k].first;
            for (int i=1;i<k;++i){
                int v = *others.begin();
                others.erase(v);
                edges.emplace_back(prev, v);
                prev = v;
            }
            edges.emplace_back(prev, 3);
            for (int i: others) {
                edges.emplace_back(i, 1);
            }
            printf("YES\n");
            for (auto &p: edges) {
                printf("%d %d\n", mp[p.first], mp[p.second]);
            }
            return;
        }
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