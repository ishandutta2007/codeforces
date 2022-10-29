#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 1e3 + 6;

int n;

int a[MAX_N];

int ask() {
	printf("? ");
	for (int i=1;n>=i;i++) printf("%d",a[i]);
	puts("");
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}

int main () {
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	int ret1=ask();
	a[1] = 1;
	int ret2=ask();
	int pos0=-1,pos1=-1;
	if (ret2 > ret1) {
		pos0=1;
		//find 1
		int L=1,R=n+1;  //R is the answer
		while (R-L!=1) {
			int mid=(L+R)>>1;
			memset(a,0,sizeof(a));
			for (int i=1;mid>=i;i++) {
				a[i] = 1;
			}
			int ret=ask();
			if (ret-ret1 == mid) L=mid;
			else R=mid;
		}
		pos1 = R;
	}
	else {
		pos1 = 1;
		for (int i=1;n>=i;i++) {
			a[i] = 1;
		}
		ret1 = ask();
		int L=1,R=n+1;  //R is the answer
		while (R-L!=1) {
			int mid=(L+R)>>1;
			memset(a,0,sizeof(a));
			for (int i=mid+1;n>=i;i++) {
				a[i] = 1;
			}
			int ret=ask();
			if (ret-ret1 == mid) L=mid;
			else R=mid;
		}
		pos0 = R;
	}
	printf("! %d %d\n",pos0,pos1);
	fflush(stdout);
	return 0;
}