#include<bits/stdc++.h>
using namespace std;

int n;

void PlanA() {
	int tot=0;
	for (int i=1;i<8;i++) {
		if (i&1) {
			for (int j=1;j<=8;j++) {
				printf("%c%d ",'a'+j-1,i);
				tot++;
				if (tot==n-2) {
					if (j==8) printf("h%d h8\n",i+1);
					else printf("%c8 h8\n",'a'+j-1);
					return;
				}
			}
		}
		else {
			for (int j=8;j>=1;j--) {
				printf("%c%d ",'a'+j-1,i);
				tot++;
				if (tot==n-2) {
					if (j==8) printf("h%d h8\n",i+1);
					else printf("%c8 h8\n",'a'+j-1);
					return;
				}
			}
		}
	}
}

void PlanB() {
	int tot=0;
	for (int i=1;i<7;i++) {
		if (i&1) {
			for (int j=1;j<=8;j++) {
				printf("%c%d ",'a'+j-1,i);
				tot++;
			}
		}
		else {
			for (int j=8;j>=1;j--) {
				printf("%c%d ",'a'+j-1,i);
				tot++;
			}
		}
	}
	for (int j=1;j<8;j++) {
		printf("%c8 ",'a'+j-1);
		tot++;
	}
	printf("g7 ");
	tot++;
	for (int j=1;tot+2<n;j++) printf("%c7 ",'a'+j-1),tot++;
	puts("h7 h8");
}

int main() {
	scanf("%d",&n);n++;
	if (n<=57) PlanA();
	else PlanB();
}