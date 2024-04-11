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
    set<pair<int, int> > v;

    for (int i=0;i<n;++i){
        v.emplace(i, i);
        v.emplace(i-1, i);
        v.emplace(i, i-1);
        v.emplace(i-1, i-1);
        v.emplace(i+1, i);
        v.emplace(i, i+1);
        v.emplace(i+1, i+1);
    }
    cout << v.size() << endl;
    for(auto p: v){
        cout << p.first << " " << p.second << endl;
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