#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int l, r;
    cin >> l >> r;
    int k = r - l + 5;
    int n = 1;
    while (k){
        n++;
        k /= 2;
    }
    n++;
    vector<pair<pair<int, int>, int> > m;
    vector<int> dl(n+1), dr(n+1);
    // dl[i] = 2**(i-2)
    // dr[i] = 2**(i-1) not reached
    // count[i] = 2 ** (i-2)
    dr[1] = 1;
    dl[1] = 0;
    for (int i=2;i<=n;i++){
        dr[i] = (1<<(i-2)) + 1;
        dl[i] = 1;
        int dd = dl[i];
        for (int j=1;j<i;++j){
            m.emplace_back(make_pair(j, i), dd - dl[j]);
            dd += dr[j] - dl[j];
        }
    }
    int nn = n-1;
    while (l <= 1 && l <= r){
        if (l == 1){
            m.emplace_back(make_pair(1, 0), 1);
            l++;
            continue;
        }
        n++;
        m.emplace_back(make_pair(1, n), 1);
        m.emplace_back(make_pair(n, 0), l-1);
        l++;
    }

    k = r - l + 1;
    for (int i=0;i<nn;++i){
        if (k & (1<<i)){
            m.emplace_back(make_pair(i + 2, 0), l - dl[i + 2]);
            l += dr[i + 2] - dl[i+2];
        }
    }
    cout << "YES" << endl;
    cout << n + 1 << " " << m.size() << endl;
    for (auto p: m){
        cout << p.first.first << " ";
        if (p.first.second)
            cout << p.first.second;
        else
            cout << n + 1;
        cout << " " << p.second << endl;
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