#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 2e5 + 6;

int a[MAX_N],b[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int cnt=-1;
		int id;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			if (a[i]>0 && cnt==-1) {
				cnt=a[i];
				id=i;
			}
		}
		int id2;
		for (int i=1;n>=i;i++) {
			scanf("%d",&b[i]);
			if (b[i]==cnt) {
				id2=i;
			}
		}
		int x=id+1,y=id2+1;
		bool check=false;
		while (x!=id && y!=id2) {
			if (x>n) x-=n;
			if (y>n) y-=n;
			if (a[x]==0 && b[y]==0) {
				x++;
				y++;
			}
			else if (b[y]==0) {
				y++;
			}
			else if (a[x]==0) {
				x++;
			}
			else if (a[x]==b[y]) {
				x++;
				y++;
			}
			else if (a[x]!=b[y]) {
				check=true;
				break;
			}
			if (y>n) y-=n;
			if (x>n) x-=n;
		}
		if (check) puts("NO");
		else puts("YES");
	}
}