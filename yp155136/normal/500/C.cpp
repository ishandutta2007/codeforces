#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 502;
const int MAX_M = 1003;

int w[MAX_N];
int a[MAX_M];
int used[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=1;n>=x;x++) scanf("%d",&w[x]);
		int ans=0;
		for (int x=1;m>=x;x++) {
			scanf("%d",&a[x]);
			int tmp=0;
			memset(used,0,sizeof(used));
			for (int y=x-1;y>=1;y--) {
				if (a[y]==a[x]) break;
				else if (!used[a[y]]) {
					tmp += w[a[y]];
					used[a[y]]=1;
				}
			}
			ans += tmp;
		}
		printf("%d\n",ans);
	}
}