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
    vector<int> twos, threes;
    vector<pair<int, int> > ret;
    map<int, int> three_one, two_one;
    int ind = 1;
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            if (!twos.empty()){
                int j = twos.back();
                twos.pop_back();
                if (two_one.count(j))
                    ret.emplace_back(two_one[j], i);
                else{
                    ret.emplace_back(ind, i);
                    ret.emplace_back(ind, j);
                    ind++;
                }
            } else if (!threes.empty()){
                int j = threes.back();
                threes.pop_back();
                if (three_one.count(j)){
                    ret.emplace_back(three_one[j], i);
                } else {
                    ret.emplace_back(ind, i);
                    ret.emplace_back(ind, j);
                    ind++;
                }
                ret.emplace_back(ind, i);
                ind++;
            } else {
                ret.emplace_back(ind, i);
                ind++;
            }
        }
        if (a[i] == 2) {
            if (!threes.empty()){
                int j = threes.back();
                threes.pop_back();
                if (three_one.count(j)){
                    ret.emplace_back(three_one[j], i);
                }
                else{
                    ret.emplace_back(ind, i);
                    ret.emplace_back(ind, j);
                    ind++;
                }
                ret.emplace_back(ind, i);
                two_one[i] = ind;
                ind++;
            }
            twos.push_back(i);
        }
        if (a[i] == 3){
            if (!threes.empty()){
                int j = threes.back();
                threes.pop_back();
                if (three_one.count(j)){
                    ret.emplace_back(three_one[j], i);
                }
                else{
                    ret.emplace_back(ind, i);
                    ret.emplace_back(ind, j);
                    ind++;
                }
                ret.emplace_back(ind, i);
                three_one[i] = ind;
                ind++;
            }
            threes.push_back(i);
        }
    }
    if (!twos.empty() || !threes.empty()){
        cout << -1 << endl;
    } else {
        cout << ret.size() << endl;
        for (auto p: ret) {
            cout << p.first << " " << p.second + 1 << endl;
        }
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