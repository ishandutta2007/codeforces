#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	vector<int> s(1, 0);
    int n;
    cin >> n;
    for (int i=0;i<n;++i){
        int x;
        scanf("%d", &x);
        s.push_back(x);
    }
    s.push_back(0);
    long long ans=0;
    for (int i=1;i<=n;++i){
        if (s[i] > s[i-1] && s[i] > s[i+1]){
            int m = max(s[i-1], s[i+1]);
            ans += s[i] - m;
            s[i] = m;
        }
        ans += abs(s[i] - s[i-1]);
    }
    cout << ans + s[n] << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}