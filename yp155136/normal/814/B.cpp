#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1006;

int a[MAX_N];
int b[MAX_N];
int ans[MAX_N];
bool check[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(ans,0,sizeof(ans));
		memset(check,0,sizeof(check));
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&b[i]);
			if (a[i] == b[i]) ans[i] = a[i];
		}
		for (int i=1;n>=i;i++) {
			check[ans[i]] = 1;
		}
		for (int i=1;n>=i;i++) {
			if (ans[i] == 0) {
				for (int j=i+1;n>=j;j++) {
					if (ans[j] == 0) {
						if (check[a[i]]) ans[i] = b[i];
						else if (check[b[i]]) ans[i] = a[i];
						if (check[a[j]]) ans[j] = b[j];
						else if (check[b[j]]) ans[j] = a[j];
						if (ans[i] == 0 && ans[j] == 0) {
							ans[i] = a[i];
							ans[j] = b[j];
						}
						else if(ans[i] == 0) {
							if (ans[j] == a[j]) ans[i] = b[i];
							else ans[i] = a[i];
						}
						else if(ans[j] == 0) {
							if (ans[i] == a[i]) ans[j] = b[j];
							else ans[j] = a[j];
						}
						break;
					}
				}
				if (ans[i] == 0) {
					for (int j=1;n>=j;j++) {
						if (!check[j]) {
							ans[i] =j;
						}
					}
				}
				break;
			}
		}
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
}