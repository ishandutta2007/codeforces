#include<iostream>
#include<vector>
using namespace std;

int main(){
	static long long int n,m,k,a[200000+2],d[200000+2],b;
	vector<long long int>A,D;
	scanf("%I64d%I64d",&n,&k);
	m=n;
	for(int i=1;i<n+1;i++)scanf("%I64d",&a[i]);
	d[1]=0; b=0;
	A.push_back(a[1]); D.push_back(d[1]);
	for(int i=2;i<n+1;i++){
		d[i]=D[b]+A[b]*b+b*(m-b-1)*A[b]-(b+1)*(m-b-2)*a[i];
		if(d[i]<k){printf("%d\n",i); m--; D[b]+=b*A[b];}
		else {A.push_back(a[i]); D.push_back(d[i]); b++;}
	}
}