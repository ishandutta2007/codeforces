#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int l[2002],r[2002];
int imos[2002][2002];

int f(int a,int b,int c,int d){
	return max(0,min(b,d)-max(a,c)+1);
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&l[i],&r[i]);
		l[i]--; r[i]--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x=max(f(i,i+k-1,l[j],r[j]),f(0,k-1,l[j],r[j]));
			int y=max(f(i,i+k-1,l[j],r[j]),f(n-k,n-1,l[j],r[j]));
			imos[i][0]+=x;
			imos[i][1]-=x;
			imos[i][min(2001,max(0,l[j]-k+1+x))]++;
			imos[i][min(2001,max(0,r[j]-k+2))]--;
			imos[i][min(2001,l[j]+1)]--;
			imos[i][min(2001,max(0,r[j]+2-y))]++;
		}
		for(int j=1;j<2002;j++)imos[i][j]+=imos[i][j-1];
		for(int j=1;j<2002;j++)imos[i][j]+=imos[i][j-1];
	}
	int ret=0;
	for(int i=0;i<2002;i++){
		for(int j=0;j<2002;j++){
			ret=max(ret,imos[i][j]);
		}
	}
	cout<<ret<<endl;
}