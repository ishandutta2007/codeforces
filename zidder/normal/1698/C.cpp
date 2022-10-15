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
    for (int &i: a) scanf("%d", &i);
    sort(a.begin(), a.end());
    int p = 0, neg=0, z=0;
    for (int i: a) {
        if (i > 0) p++;
        if (i < 0) neg++;
        if (i == 0) z++;
    }
    if (neg > 2 || p > 2) {
        cout << "NO" << endl;
        return;
    }
    vector<int> v1;
    if (z) v1.push_back(0);
    for (int i:a) {
        if (i) v1.push_back(i);
    }

    for (int i=0;i<v1.size();++i){
        for (int j=0;j<i;++j){
            for (int k=0;k<j;++k){
                bool ok = false;
                for (int l: v1) {
                    if (v1[i] + 0ll + v1[j] + 0ll + v1[k] == l) {
                        ok = true;
                    }
                }
                if (!ok) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}