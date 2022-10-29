#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 26;

int a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				scanf("%d",&a[x][y]);
			}
		}
		bool ans=false;
		//no change
		bool tmp=true;
		for (int x=1;n>=x;x++) {
			int f=0;
			for (int y=1;m>=y;y++) {
				if (a[x][y] != y) f++;
			}
			if (f>2) tmp=false;
		}
		ans = tmp;
		for (int i=1;m>=i;i++) {
			for (int j=i+1;m>=j;j++) {
				//swap col i & j
				for (int x=1;n>=x;x++) {
					for (int y=1;m>=y;y++) {
						b[x][y] = a[x][y];
					}
				}
				for (int x=1;n>=x;x++) {
					swap(b[x][i],b[x][j]);
				}
				bool tmp=true;
				for (int x=1;n>=x;x++) {
					int f=0;
					for (int y=1;m>=y;y++) {
						if (b[x][y] != y) f++;
					}
					if (f>2) tmp=false;
				}
				if (!ans) ans=tmp;
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
}