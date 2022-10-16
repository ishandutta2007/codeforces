#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using matrix=ll[4][4];
const ll base=1000000007;
void multi(matrix &a, matrix &b, matrix &c){
	for(int i=0; i<4; i++) for(int j=0; j<4; j++){
		c[i][j]=0;
		for(int k=0; k<4; k++) (c[i][j]+=a[i][k]*b[k][j])%=base;
	}
}
void power(matrix &a, int x, matrix &res){
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) res[i][j]=a[i][j];
	matrix temp;
	for(int i=__lg(x)-1; i>=0; i--){
		multi(res, res, temp);
		if((x>>i)&1) multi(temp, a, res);
		else for(int i=0; i<4; i++) for(int j=0; j<4; j++) res[i][j]=temp[i][j];
	}
}
int n;
matrix core, res;
int main(){
	cin>>n;
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) core[i][j]=(i!=j);
	power(core, n, res);
	cout<<res[0][0]<<'\n';
}