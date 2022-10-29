#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main () {
	string s;
	while (cin >>s) {
		int check[1343];
		memset(check,0,sizeof(check));
		int cnt=0;
		for(auto i:s) {
			check[i]++;
			for (int j='a';i>=j;j++) {
				if (check[j]==0) cnt=-2;
			}
		}
		if (cnt==-1 || cnt==0) puts("YES");
		else puts("NO");
	}
}