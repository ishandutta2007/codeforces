#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;

void solve(int L,int R) {
	if (R-L+1 == 2) {
		v.push_back(R);
		v.push_back(L);
		v.push_back(R);
		return;
	}
	else if (R-L+1 == 3) {
		int mid=(L+R)>>1;
		v.push_back(mid);
		v.push_back(L);
		v.push_back(R);
		v.push_back(mid);
	}
	else {
		v.push_back(L+1);
		v.push_back(L);
		v.push_back(R-1);
		v.push_back(R);
		solve(L+1,R-1);
	}
}

int main () {
	int n;
	scanf("%d",&n);
//	if (n==5) {
//		puts("7");
//		puts("2 4 3 1 5 2 4");
//	}
//	if (n>1) {
//		if (n==3) {
//			puts("4");
//			puts("2 1 3 2");
//		}
//		else if (n==2){
//			puts("3");
//			puts("2 1 2");
//		}
//		else {
//			printf("%d\n",4+(n-3)*2);
//			for (int i=2;n>=i;i++) {
//				if (i==2) printf("2 1");
//				else printf(" %d %d",i,i-1);
//			}
//			puts("");
//		}
//	}
//	solve(1,n);
	for (int i=2;n>=i;i+=2) v.push_back(i);
	for (int i=1;n>=i;i+=2) v.push_back(i);
	for (int i=2;n>=i;i+=2) v.push_back(i);
	printf("%d\n",v.size());
	bool gett=false;
	for (int i:v) {
		if (gett) printf(" ");
		printf("%d",i);
		gett=true;
	}
	puts("");
}