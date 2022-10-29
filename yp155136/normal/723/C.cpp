#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 2003;

int a[MAX_N];
int cnt[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(cnt,0,sizeof(cnt));
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			if (a[x]<=m) {
				cnt[a[x]]++;
			}
		}
		int g=n/m;
		int ans1=0;
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				if (a[i] > m && cnt[j] < g) {
					cnt[j]++;
					a[i]=j;
					ans1++;
				}
				else if (a[i]<=m && cnt[a[i]] > g && cnt[j]<g) {
					cnt[a[i]]--;
					cnt[j]++;
					a[i]=j;
					ans1++;
				}
			}
		}
//		int q=1;
//		for (int i=1;n>=i;i++) {
//			if (a[i] > m) {
//				a[i]=q++;
//				ans1++;
//			}
//		}
		printf("%d %d\n",g,ans1);
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",a[x]);
		}
		puts("");
	}
}