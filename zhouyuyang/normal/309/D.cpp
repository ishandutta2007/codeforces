#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int main(){
	scanf("%d%d",&n,&m); n++; m++;
	for (int i=m;i*2<=n;i++){
		for (int j=m,k=n-m;j<=n-m;j++){
			for (;k>=m&&(j-2*i)*(2*(i-n)+k)-3*j*k<=0;k--);
			if (k<m) break; ans+=(k-m+1)*(i*2==n?1:2);
		}
	}
	printf("%lld\n",ans*3);
}
/*
Pta=(0,i)
Ptb=(sqrt3j/2,j/2)
Ptc=(sqrt3k/2,n-k/2)

A=(0,2*i)
B=(G3j,j)
C=(G3k,2n-k)

ab=3j^2+(4i^2-4ij+j^2)=4i^4-4ij+4j^2
ac=3k^2+(4i^2+4n^2+k^2+4ik-8in-4kn)
  =4i^2+4n^2+4k^2+4ik-8in-4kn
bc=(3j^2+3k^2-6jk)+(j^2+k^2+4n^2+2jk-4jn-4kn)
  =4j^2+4k^2+4n^2-4jk-4jn-4kn
bc-ac-ab=8i^2+4ij-4ik+8in-4jk-4jn

(2i-j)*(2i-2n+k)
-4i^2-4in+2ik-2ij+2jn-2jk
*/