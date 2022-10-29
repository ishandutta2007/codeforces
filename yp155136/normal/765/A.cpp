#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		char c[7];
		getchar();
		scanf("%s",c);
		int cnt=0;
		for (int i=0;n>i;i++) {
			char s[11];
			scanf("%s",s);
			if (s[0]==c[0] && s[1]==c[1] && s[2]==c[2]) cnt++;
			else if (s[5]==c[0] && s[6]==c[1] && s[7]==c[2]) cnt--;
		}
		if (cnt) puts("contest");
		else puts("home");
	}
}