#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		string a;
		cin >> a;
		int num[27]={0};
		if (a.size()>26) puts("-1");
		else {
			for (int x=0;a.size()>x;x++) num[a[x]-'a']++;
			int ans=0;
			for (int x=0;27>x;x++) {
				if (num[x]>1) ans+=(num[x]-1);
			}
			printf("%d\n",ans);
		}
	}
}