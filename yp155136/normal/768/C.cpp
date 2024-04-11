#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1024;
const int MAX_K = 1e5 + 1;

int cnt[2][MAX_N];

int main () {
	int n,k,x;
	while (scanf("%d %d %d",&n,&k,&x) != EOF) {
		for (int i=1;n>=i;i++) {
			int a;
			scanf("%d",&a);
			cnt[1][a]++;
		}
		int i=0;
		for (int ala=1;k>=ala;ala++) {
			i=1-i;
			int tmp=0;
			for (int j=0;MAX_N>j;j++) {
				cnt[1-i][j]=0;
			}
			for (int j=0;MAX_N>j;j++) {
				cnt[1-i][j] += (cnt[i][j]/2 + ((cnt[i][j]&1) && (tmp&1)));
				cnt[1-i][j^x]+=(cnt[i][j]/2 + ((cnt[i][j]&1) && !(tmp&1)));
				tmp+=cnt[i][j];
			}
		}
		i=1-i;
		int mx=-1,mn=1024;
		for (int j=0;MAX_N>j;j++) {
			if (cnt[i][j]) mx=j,mn=min(mn,j);
		}
		printf("%d %d\n",mx,mn);
	}
}