#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

ll MOD;

ll C[402][402];
void init_C(){
	for(int i=0;i<402;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<=i-1;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=MOD)C[i][j]-=MOD;
		}
	}
}

ll A[402];
void init_A(){
	A[0]=1;
	for(int i=1;i<402;i++){
		A[i]=A[i-1]+A[i-1];
		if(A[i]>=MOD)A[i]-=MOD;
	}
}

ll dp[405][405];

int main(){
	int n;
	scanf("%d%lld",&n,&MOD);
	init_C();
	init_A();
	
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=1;;k++){
				if(i+k+1>n+1)break;
				if(j+k>n)break;
				dp[i+k+1][j+k]+=dp[i][j]*A[k-1]%MOD*C[j+k][k];
				dp[i+k+1][j+k]%=MOD;
			}
		}
	}
	ll ret=0;
	for(int j=0;j<=n;j++)ret+=dp[n+1][j];
	cout<<ret%MOD<<endl;
}