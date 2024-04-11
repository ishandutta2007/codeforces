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
    for (int i=0;i<n;++i) cin >> a[i];
    int ans=0;
    vector<pair<int, int> > as;
    as.emplace_back(0, 0);
    for (int i=0;i<n;++i){
        vector<pair<int, int> > as1;
        for (auto p: as){
            if (p.first != a[i])
                as1.emplace_back(a[i], p.second);
            if (p.second != a[i])
                as1.emplace_back(p.first, a[i]);
        }
        if (!as1.empty()){
            ans++;
            sort(as1.begin(), as1.end());
            as.clear();
            as.push_back(as1[0]);
            for (auto p: as1){
                if (p.first != as[0].first && p.second!=as[0].second){
                    as.push_back(p);
                    break;
                }
            }
            if (as.size() == 1){
                for (auto p: as1){
                    if (p.second != as[0].second)
                        as.push_back(p);
                }
                for (auto p: as1){
                    if (p.first != as[0].first)
                        as.push_back(p);
                }
                continue;
            }
            for (auto p: as1){
                if (p.first != as[0].first && p.second!=as[1].second){
                    as.push_back(p);
                    break;
                }
            }
            for (auto p: as1){
                if (p.first != as[0].second && p.second!=as[1].first){
                    as.push_back(p);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}