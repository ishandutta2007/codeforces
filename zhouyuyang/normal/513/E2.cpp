#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int c[30005], n, dp[205][30005][3], b[5][3];

int &dpc(int i, int k, int t) {return dp[k][i][t+1];}
int &bc(int i, int j) {return b[i+2][j+1];}

int main() {
	int K;
	scanf("%d %d", &n, &K);
	FO(i,1,n+1) {
		scanf("%d", c+i);
		c[i] += c[i-1];
	}
	FO(k,1,K+1) {
		FO(t,-1,2) {
			dpc(n,k,t) = -1e9;
			FO(i,-2,3) FO(j,-1,2) bc(i,j) = i*c[n] + dpc(n,k-1,-j);
			for (int i=n;i>=0;i--) {
				if (i!=n) {
					dpc(i,k,t) = dpc(i+1,k,t);
					FO(nek,-1,2) if ((k==1) == (nek==0)) dpc(i,k,t) = max(dpc(i,k,t), bc(t+nek,nek) - (t+nek)*c[i]);
				}
				FO(I,-2,3) FO(j,-1,2) bc(I,j) = max(bc(I,j), I*c[i] + dpc(i,k-1,-j));
			}
		}
	}
	printf("%d\n", dpc(0,K,0));
}