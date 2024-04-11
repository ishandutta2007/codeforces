#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cnt[1234];

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mx=0,tmp=0;
	for (int i:s) {
		if (i>'Z') {
			cnt[i]++;
			if (cnt[i] == 1) {
				tmp++;
			}
		}
		else {
			memset(cnt,0,sizeof(cnt));
			tmp=0;
		}
		mx = max(mx,tmp);
	}
	cout<<mx<<endl;
}