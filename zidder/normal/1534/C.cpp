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
    vector<int> p1(n), p2(n);
    for (int i=0;i<n;++i){int x;scanf("%d", &x);p1[i]=x;}
    for (int i=0;i<n;++i){int x;scanf("%d", &x);p2[i]=x;}
    map<int, int> mp1;
    for (int i=0;i<n;++i) mp1[p1[i]] = i;
    set<int> v;
    long long ans = 1;
    for (int i=0;i<n;++i){
        int j = i, cnt = 0;
        while (v.find(p1[j]) == v.end()){
            v.insert(p1[j]);
            j = mp1[p2[j]];
            cnt++;
        }
        if (cnt > 1)
            (ans *= 2) %= 1000000007;
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}