#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
	string i;
	while (cin >> i) {
		i += "a";
		long long ans=0;
		int len=i.size();
		long long tmp=0;
		bool check=false;
		bool dot=false;
		int cnt=0;
		for (int x=0;len>x;x++) {
//			cout << "i["<<x<<" ] = "<<i[x]<<endl;
			if ('0' <= i[x] && i[x] <= '9') {
//				cout<<"in2\n";
				check=true;
				tmp *= 10;
				tmp += (i[x] - '0');
				cnt++;
			}
			else if (i[x] == '.') {
				cnt = 0;
				dot = true;
			}
			else {
				if (check) {
//					cout<<"tmp = "<<tmp<<endl;
//					cout<<"in\n";
					if (cnt == 3 || !dot) ans += tmp*100;
					else ans += tmp;
					tmp = 0;
					check=false;
				}
			}
		}
//		cout <<"ans = "<<ans<<endl;
		vector<int> v;
		if (ans % 100 == 0) {
			ans /= 100;
			while (ans > 0) {
				v.push_back(ans % 10);
				ans /= 10;
			}
			int sz=v.size();
			for (int x=sz-1;x>=0;x--) {
				printf("%d",v[x]);
				if (x==0) break;
				else if (x%3==0) printf(".");
			}
			puts("");
		}
		else {
			while (ans > 0) {
				v.push_back(ans % 10);
				ans /= 10;
			}
			while (v.size() < 3) v.push_back(0);
			int sz=v.size();
			for (int x=sz-1;x>=0;x--) {
				printf("%d",v[x]);
				if (x%3==2) printf(".");
			}
			puts("");
		}
	}
}