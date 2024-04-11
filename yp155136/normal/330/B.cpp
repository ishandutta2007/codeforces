#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1e3 + 6;

bool used[MAX_N];

int main () {
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;m>=i;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		used[x]=used[y]=1;
	}
	for (int i=1;n>=i;i++) {
		if (!used[i]) {
			printf("%d\n",n-1);
			for (int j=1;n>=j;j++) {
				if (i==j) continue;
				printf("%d %d\n",i,j);
			}
			break;
		}
	}
}