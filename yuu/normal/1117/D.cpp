#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using matrix=ll[100][100];
const ll base=1000000007;
void multi(matrix &a, matrix &b, matrix &c){
	for(int i=0; i<100; i++) for(int j=0; j<100; j++){
		c[i][j]=0;
		for(int k=0; k<100; k++) (c[i][j]+=a[i][k]*b[k][j])%=base;
	}
}
void power(matrix &a, long long x, matrix &res){
	for(int i=0; i<100; i++) for(int j=0; j<100; j++) res[i][j]=a[i][j];
	matrix temp;
	for(int i=__lg(x)-1; i>=0; i--){
		multi(res, res, temp);
		if((x>>i)&1) multi(temp, a, res);
		else for(int i=0; i<100; i++) for(int j=0; j<100; j++) res[i][j]=temp[i][j];
	}
}
long long n, m;
matrix core, res;
int main(){
	cin>>n>>m;
	for(int i=1; i<m; i++) core[i][i-1]++;
	core[0][m-1]++;
	core[m-1][m-1]++;
	power(core, n, res);
	cout<<res[m-1][m-1]<<'\n';
}