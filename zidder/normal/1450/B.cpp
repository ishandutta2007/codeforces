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
    int k;
    cin >> k;
    vector<pair<int, int > > v(n);
    for (int i=0;i<n;++i){
        cin >> v[i].first >> v[i].second;
    }
    for (int i=0;i<n;++i){
        bool b=true;
        for (int j=0;j<n;++j){
            if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) >k){
                b=false;
                break;
            }

        }
        if (b){
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}