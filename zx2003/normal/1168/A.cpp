#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,a[N],i,L,R,M,x;
int main(){
	scanf("%d%d",&n,&m);L=0;R=m-1;
	for(i=0;i<n;++i)scanf("%d",a+i);
	for(;L<R;){
		M=L+R>>1;x=0;
		for(i=0;i<n;++i)if(a[i]+M<m){
			if(x>a[i]+M)break;
			x=max(x,a[i]);
		}else{
			if(x>(a[i]+M)%m)x=max(x,a[i]);
		}
		if(i<n)L=M+1;else R=M;
	}
	printf("%d\n",L);
	return 0;
}