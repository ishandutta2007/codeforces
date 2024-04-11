#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, H, M;
    cin >> n >> H >> M;
    int v = H * 60 + M;
    int s = 24 * 60;
    for (int i=0;i<n;++i){
        int h, m;
        cin >> h >> m;
        int a = h * 60 + m;
        s = min(s, (24 * 60 + a - v) % (24 * 60));
    }
    cout << s / 60 << " " << s%60 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}