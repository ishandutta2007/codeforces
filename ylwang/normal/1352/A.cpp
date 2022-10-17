#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> ans;
    	int power = 1;
    	while (n) {
    		if (n % 10) ans.push_back((n % 10) * power);
    		n /= 10;
    		power *= 10;
		}
		cout << ans.size() << '\n';
		for (auto k : ans) cout << k << ' ';
		cout << '\n';
	}
	
	return 0;
}