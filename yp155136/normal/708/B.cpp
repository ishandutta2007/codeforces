#include <iostream>
#include <stdio.h>
using namespace std;

int f(int x) {
	for (int ret=1;;ret++) {
//		cout<<"ret="<<ret<<endl;
		if (ret*(ret-1) == x) return ret;
		else if (ret*(ret-1)>x) return 0;
	}
}

int main () {
	int a,b,c,d;
	while (scanf("%d %d %d %d",&a,&b,&c,&d) != EOF) {
		int i=f(2*a);
		int j=f(2*d);
//		cout<<"i="<<i<<" , j="<<j<<endl;
//		if (i==0 && j==0 && b==0&&)
		if (i==0||j==0) {
//			cout<<"in\n";
			puts("Impossible");
			continue;
		}
		if (b+c != i*j) {
			if (b==0 && c==0) {
				if (i!=1 && j==1) {
					for (int x=0;i>x;x++) printf("0");
					puts("");
				}
				else if (i==1 && j!=1){
					for (int x=0;j>x;x++) printf("1");
					puts("");
				}
				else if (i==1 && j==1) {
					puts("1");
				}
				else {
					puts("Impossible");
				}
				continue;
			}
			puts("Impossible");
			continue;
		}
		int x=b/i;
		int y=b%i;
		for (int t=0;(j-(x+(y!=0)))>t;t++) printf("1");
		for (int t=0;y>t;t++) printf("0");
		if (y!=0) printf("1");
		for (int t=0;(i-y)>t;t++) printf("0");
		for (int t=0;x>t;t++) printf("1");
		puts("");
	}
}