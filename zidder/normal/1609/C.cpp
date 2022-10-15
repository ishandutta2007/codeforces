#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool prime[1000001];

void solve(int test_ind){
	int n, e;
	cin >> n >> e;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	long long ans = 0;
	for (int i=0;i<e;++i){
		long long l=0, r=0;
		bool p = false;
		for (int j=i;j<n;j+=e){
			// cout << a[j] << " " << l << " " << r << endl;
			if (prime[a[j]]){
				if (p){
					ans += l * r - 1;
					l = r;
					r = 1;
				} else {
					p = true;
					l++;
					r = 1;
				}
			}
			else {
				if (a[j] == 1){
					if (!p) l++;
					else r++;
				}
				else {
					if (l && r) ans += l*r - 1;
					p=false;
					l=0;
					r=0;
				}
			}
		}
		// cout << "end: " << l << " " << r << endl;
		if (l && r) ans+=l*r-1;
	}
	cout << ans << endl;
}

int main(){
	prime[0] = false;
	prime[1] = false;
	for (int i=2;i<=1000000;++i){
		prime[i] = true;
		for (int j=2;j*j<=i;++j){
			if (i%j==0) {prime[i]=false;break;}
		}
	}
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}