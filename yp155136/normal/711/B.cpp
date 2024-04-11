#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LL;
const int MAX_N = 503;

LL num[MAX_N][MAX_N];

int main () {
	srand(time(NULL));
	int n;
	while (scanf("%d",&n) != EOF) {
		if (n==1) {
			scanf("%d",&n);
			printf("%d\n",rand() + 123456);
			continue;
		}
		else {
			for (int x=1;n>=x;x++) {
				for (int y=1;n>=y;y++) {
					scanf("%I64d",&num[x][y]);
				}
			}
			LL sum=0;
			LL ans=0;
			//row first
			for (int x=1;n>=x;x++) {
				LL tmp=0;
				for(int y=1;n>=y;y++) {
					if (num[x][y] == 0) {
						tmp=-1;
						break;
					}
					tmp += num[x][y];
				}
				if (sum==0 && tmp!=-1) sum=tmp;
				else if (tmp!=-1 && sum!=tmp) {
					ans=-1;
					break;
				}
			}
			if (ans==-1) {
				printf("%I64d\n",ans);
				continue;
			}
			for (int x=1;n>=x;x++) {
				LL tmp=0;
				for(int y=1;n>=y;y++) {
					if (num[y][x] == 0) {
						tmp=-1;
						break;
					}
					tmp += num[y][x];
				}
				if (sum==0 && tmp!=-1) sum=tmp;
				else if (tmp!=-1 && sum!=tmp) {
					ans=-1;
					break;
				}
			}
			if (ans==-1) {
				printf("%I64d\n",ans);
				continue;
			}
			for (int x=1;n>=x;x++) {
				int sy=-1;
				LL tmp=0;
				for (int y=1;n>=y;y++) {
					tmp += num[x][y];
					if (num[x][y] == 0) {
						sy=y;
					}
				}
				if (sy!=-1) {
					ans = sum - tmp;
					num[x][sy] = ans;
				}
			}
			if (ans<1) {
				ans=-1;
				printf("%I64d\n",ans);
				continue;
			}
			for (int x=1;n>=x;x++) {
				LL tmp=0;
				for(int y=1;n>=y;y++) {
					if (num[y][x] == 0) {
						tmp=-1;
						break;
					}
					tmp += num[y][x];
				}
				if (sum==0 && tmp!=-1) sum=tmp;
				else if (tmp!=-1 && sum!=tmp) {
					ans=-1;
					break;
				}
			}
			if (ans==-1) {
				printf("%I64d\n",ans);
				continue;
			}
			LL cnt=0;
			for (int x=1;n>=x;x++) {
				cnt += num[x][x];
			}
			if (cnt!=sum) {
				printf("-1\n");
				continue;
			}
			cnt=0;
			for (int x=1;n>=x;x++) {
				cnt += num[x][n-x+1];
			}
			if (cnt!=sum) {
				printf("-1\n");
				continue;
			}
			printf("%I64d\n",ans);
		}
	}
}