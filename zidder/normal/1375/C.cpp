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
    vector<int> v(n), m(n);
    vector<int> pre(n), post(n);
    for(int i=0;i<n;++i){
        scanf("%d", &v[i]);
        v[i]--;
        m[v[i]] = i;
    }
    vector<int> q;
    q.push_back(v[0]);
    for (int i=1;i<n;++i){
        if (v[i] > q.front()){
            int x = q.front();
            q.clear();
            q.push_back(x);
            continue;
        }
        if (v[i] > q.back())
            continue;
        q.push_back(v[i]);
    }
    if (q.size() == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}