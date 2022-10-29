#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int m,s;
	while (scanf("%d %d",&m,&s) != EOF) {
		if (m==1 && s==0) {
			puts("0 0");
			continue;
		}
		else if (s==0) {
			puts("-1 -1");
			continue;
		}
		if (9*m<s) {
			puts("-1 -1");
			continue;
		}
		//print min first
		int _=s;
		for (int q=1;m>=q;q++) {
			if (q==1) {
				if ((m-1)*9 >= _-1) {
					printf("1");
					_ -= 1;
				}
				else {
					printf("%d",s-9*(m-1));
					_ -= (s-9*(m-1));
				}
			}
			else {
				//already print q
				if ((m-q)*9 >= _) printf("0");
				else {
					printf("%d",_ - (m-q)*9);
					_ -= (_ - (m-q)*9);
				}
			}
		}
		printf(" ");
		for (int q=0;m>q;q++) {
			printf("%d",min(s,9));
			s-=min(s,9);
		}
		puts("");
	}
}