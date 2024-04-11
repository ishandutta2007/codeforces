#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n, q;
    cin >> n >> q;
    set<int> p;
    map<int, int> dst;
    for(int i=0;i<n;++i){
        int x;
        scanf("%d", &x);
        p.insert(x);
    }
    int last = -1;
    for (int i: p){
        if (last == -1){
            last=i;
            continue;
        }
        dst[i-last]++;
        last = i;
    }
    for(int i=0;i<=q;++i){
        int a, x;
        if (i){
            scanf("%d%d", &a, &x);
            if (a){
                if (!p.empty()){
                    auto l = p.upper_bound(x);
                    auto q = l;
                    l--;
                    if (q != p.end()){
                        dst[(*q) - x]++;
                    }
                    if (q != p.begin()){
                        dst[x - (*l)]++;
                    }
                    if (q != p.begin() && q != p.end()) {
                        dst[(*q) - (*l)]--;
                    }
                }
                p.insert(x);
            } else {
                auto l = p.upper_bound(x);
                auto q = l;
                bool beg = false;
                l--;
                if (l!=p.begin())
                    l--;
                else beg=true;
                if (q != p.end()){
                    dst[(*q) - x]--;
                }
                if (q != p.begin() && !beg){
                    dst[x - (*l)]--;
                }
                if (q != p.begin() && q != p.end() && !beg) {
                    dst[(*q) - (*l)]++;
                }
                p.erase(x);
            }
        }
        while (!dst.empty() && dst.rbegin()->second == 0)
            dst.erase(dst.rbegin()->first);
        int total = 0;
        if (!p.empty())
            total = (*p.rbegin()) - (*p.begin());
        if (p.size() < 2)
            cout << 0 << endl;
        else
            cout << total - (dst.rbegin()->first) << endl;
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}