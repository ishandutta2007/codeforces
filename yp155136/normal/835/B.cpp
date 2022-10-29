#include <iostream>
#include <stdio.h>
using namespace std;

int cnt[10];

int main () {
	ios::sync_with_stdio(0);
	int k;
	cin >> k;
	string s;
	cin >>s;
	int tot=0;
	for (char i:s) {
		tot += (i-'0');
		cnt[i-'0']++;
	}
	if (tot >= k) {
		cout<<0<<endl;
		return 0;
	}
	else {
		int ans=0;
		for (int i=0;9>=i;i++) {
			int need=k-tot;
			if (need > (9-i)*cnt[i]) {
				tot += (9-i)*cnt[i];
				ans += cnt[i];
			}
			else {
				int gett=((need + (9-i)-1)/(9-i));
				ans += gett;
				break;
			}
		}
		cout<<ans<<endl;
	}
}