#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 5002;
int v[MAX_N];
int z[MAX_N]; //number of time
int ans[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(ans,0,sizeof(ans));
		for (int x=1;n>=x;x++) scanf("%d",&v[x]);
		for (int x=1;n>=x;x++) {
			memset(z,0,sizeof(z));
			int num=1;
			int id=v[x];
			ans[id]++;
			z[id]=1;
			for (int j=x+1;n>=j;j++) {
				z[v[j]]++;
				if (v[j] == id) {
					ans[id]++;
					num++;
				}
				else {
					if (z[v[j]]>num) {
						num=z[v[j]];
						id = v[j];
						ans[id]++;
					}
					else if (z[v[j]] == num && v[j]<id) {
						num=z[v[j]];
						id = v[j];
						ans[id]++;
					}
					else {
						ans[id]++;
					}
				}
			}
		}
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",ans[x]);
		}
		puts("");
	}
}