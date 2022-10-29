#include <iostream>
#include <stdio.h>
using namespace std;

int cnt[1243];

int main () {
	string s;
	getline(cin,s);
	for (auto i:s) cnt[i]++;
	int ans=0;
	for (int i='a';'z'>=i;i++) {
		ans += (cnt[i]>0);
	}
	cout<<ans<<endl;
}