#include <bits/stdc++.h>
using namespace std;
#define pii pair < int, int >
#define mkp make_pair 
int ask1(int x) {
	cout << "? 1 " << x << endl; 
	char ans; cin >> ans; return ans - 'a';
}
int ask2(int l, int r) {
	cout << "? 2 " << l << ' ' << r << endl; 
	int ans; cin >> ans; return ans ;
}	
int lst[26], ans[1005]; 
int calc(int x) {
	int ans = 0; 
	for( int i = 0; i < 26; i++) ans += lst[i] >= x; 	
	return ans; 
}
int main() {
	int n; cin >> n; 
	for(int i = 1; i <= n; i++) {
		vector < pii > tmp; tmp.push_back(mkp(0, -1)); 
		for(int i = 0; i < 26; i++) {
			if(lst[i]) tmp.push_back(mkp(lst[i], i)); 
		}
		sort(tmp.begin(), tmp.end()); 
		int l = 1, r = tmp.size() - 1, pos = 0; 
		while(l <= r) {
			int mid = (l + r) >> 1; 
//			cerr << "! " << calc(tmp[mid].first) << endl; 
			if(calc(tmp[mid].first) == ask2(tmp[mid].first, i)) pos = mid, l = mid + 1;
			else r = mid - 1;  
		}
		if(!pos) ans[i] = ask1(i); 
		else ans[i] = tmp[pos].second; 
		lst[ans[i]] = i; 
	}
	cout << "! "; 
	for(int i = 1; i <= n; i++) {
		printf("%c", ans[i] + 'a'); 	
	}
	return 0; 
}