#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long f(vector<int> hh, int m){
	long long ans = 0;
	multiset<int> h(hh.begin(), hh.end());
	while (!h.empty() && *h.rbegin() >= m - 1) {
		if (*h.rbegin() == m) {
			h.erase(m);
			continue;
		}
		ans++;
		h.erase(h.find(m - 1));
		if (h.empty()) return ans;
		ans++;
		if (*h.begin() < m - 1) {
			int q = *h.begin();
			h.erase(h.find(q));
			h.insert(q + 2);
		}
	}
	if (h.empty()) return ans;
	vector<int> h1;
	for (int i: h) h1.push_back(i);
	if (h1.size() == 1) {
		return ans + (m - h1[0]) / 3 * 2 + (m - h1[0]) % 3;
	}
	// cout << "m: " << m << endl;
	// for (int i: h1) cout << i << " ";
	// cout << endl;
	for (int i=0, j=(int)h1.size()-1;i<=j;){
		if (i == j) {
			h1[0]++;
			h1[i]+=2;
			ans+=2;
			break;
		} else {
			h1[i]++;
			h1[j]+=2;
			ans+=2;
			i++;
			j--;
		}
	}
	long long d = 0;
	for (int i=0;i<h1.size();++i){
		d += m - h1[i];
	}
	// cout << m << " " << ans << " " <<  h1.size() << " " << d << endl;
	return ans + (d / 3) * 2 + d % 3;
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i=0;i<n;++i) scanf("%d", &h[i]);
	sort(h.begin(), h.end());
	int m = h[n-1];
	cout << min(f(h, m), min(f(h, m+1), f(h, m+2))) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}