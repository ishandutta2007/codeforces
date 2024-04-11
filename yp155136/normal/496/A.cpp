#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		int a[n];
		for (int i=0;n>i;i++) cin >>a[i];
		int ans=123456789;
		vector<int> v;
		for (int i=0;n>i;i++) v.push_back(a[i]);
		for (int i=1;n-2>=i;i++) {
			vector<int> tmp;
			tmp=v;
			tmp.erase(tmp.begin()+i);
			int mx=-1;
			for (int x=0;n-2>x;x++) {
				mx = max(mx,tmp[x+1]-tmp[x]);
			}
			ans = min(ans,mx);
		}
		cout<<ans<<endl;
	}
}