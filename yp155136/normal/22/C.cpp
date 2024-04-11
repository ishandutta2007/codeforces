#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const int MAGIC = 1e3 +6;

int v[MAX_N];
bool adj[MAGIC][MAGIC];

int main () {
	int n,m,p;
	while (scanf("%d %d %d",&n,&m,&p) != EOF) {
		for (int i=1;n>=i;i++) {
			v[i]=i;
		}
		v[1]=p;
		v[p]=1;
		swap(v[1],v[2]);
		if (n-1<=m && m<=LL(n)*(n-1)/2-(n-2)) {
			//okay
			memset(adj,0,sizeof(adj));
			printf("%d %d\n",v[1],v[2]);
			m--;
			for (int i=2;n>i;i++) {
				printf("%d %d\n",v[i],v[i+1]);
				if (i+1 < MAGIC) adj[i][i+1]=adj[i+1][i]=1;
				m--;
			}
			int st=2;
			while (m--) {
				bool flag=false;
				for (st;min(MAGIC,n+1)>st;st++) {
					for (int j=2;min(MAGIC,n+1)>j;j++) {
						if (j!=st && !adj[st][j]) {
							adj[st][j] = adj[j][st] = 1;
							printf("%d %d\n",v[st],v[j]);
							flag=1;
							break;
						}
					}
					if (flag) break;
				}
			}
		}
		else {
			puts("-1");
		}
	}
}