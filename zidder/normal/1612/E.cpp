// https://codeforces.com/problemset/problem/1612/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    cin >> n;
    vector<pair<int, int> > mk(n);
    for (int i=0;i<n;++i){
        scanf("%d%d", &mk[i].first, &mk[i].second);
    }

    // having mi will add \sum ki / t for each k where m = mi

    long double ml = 0;
    vector<int> mc;
    long double one = 1;
    for (int l=1;l<=20;++l){
        map<int, long double> m;
        vector<pair<long double, int> > ms;
        for (int i=0;i<n;++i){
            m[mk[i].first] += (l<=mk[i].second?1:mk[i].second * one / l);
        }
        if (m.size() < l) break;
        for (auto &p: m){
            ms.emplace_back(p.second, p.first);
        }
        long double cur = 0;
        sort(ms.begin(), ms.end());
        auto it = ms.rbegin();
        int cl = 0;
        vector<int> curc;
        while (it != ms.rend() && cl < l){
            cur += it->first;
            curc.push_back(it->second);
            ++it;
            ++cl;
        }
        if (cur > ml){
            ml = cur;
            mc = curc;
        }
    }

    cout << mc.size() << endl;
    for (int i: mc) printf("%d ", i);
    cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}