#include<bits/stdc++.h>
const int N=1e3+5,as[4][4]={
{8,9,1,13},
{3,12,7,5},
{0,2,4,11},
{6,10,15,14}
};
int n,a[N][N],i,j,k,l,m,s;
int main(){
	scanf("%d",&n);m=n/4;
	for(i=0;i<m;++i)for(j=0;j<m;++j){
		for(k=0;k<4;++k)for(l=0;l<4;++l)
			a[i+k*m][j+l*m]=s+as[k][l];
		s+=16;
	}
	/*
	std::set<int>ss;
	for(i=0;i<n;++i){
		for(j=s=0;j<n;++j)s^=a[i][j];
		ss.insert(s);
		for(j=s=0;j<n;++j)s^=a[j][i];
		ss.insert(s);
	}
	assert(ss.size()==1);
	*/
	for(i=0;i<n;++i,puts(""))for(j=0;j<n;++j)printf("%d ",a[i][j]);
}