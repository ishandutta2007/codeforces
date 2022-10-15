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
    int mxx = 0, mnx = 0, mny = 0, mxy = 0;
    for (int i=0;i<n;++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        mnx = min(mnx, x);
        mxx = max(mxx, x);
        mny = min(mny, y);
        mxy = max(mxy, y);
    }
    cout << 2 * (mxx - mnx + mxy - mny) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}