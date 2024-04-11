#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 400002;
vector<int> divs[N];

void solve(int test_ind){
	int l, r;
    cin >> l >> r;
    long long c = 0;
    for (int i=l+2;i<=r;++i){
        c += (i - l) * 1ll * (i - l - 1) / 2;
        // 2/3i + i + j > 2i
        // j | 2i, j >= l, j < i, j > i / 3, j != 2/3i
        if (i%3 == 0 && i / 3 * 2 >= l)  c -= lower_bound(divs[2*i].begin(), divs[2*i].end(), i) - lower_bound(divs[2*i].begin(), divs[2*i].end(), max(l, i/3+1)) - 1;
        // i + d1 + d2 > i
        // d1 | i, d2 | i, d1 < d2, d1, d2 >= l
        int d = lower_bound(divs[i].begin(), divs[i].end(), i) - lower_bound(divs[i].begin(), divs[i].end(), l);
        c -= d * (d - 1) / 2;
    }
    cout << c << endl;
}

int main(){
    for (int i=1;i<N;++i) {
        for (int j=i;j<N;j+=i) {
            divs[j].push_back(i);
        }
    }
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}