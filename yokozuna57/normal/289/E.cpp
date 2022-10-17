#include<iostream>
using namespace std;

int main(){
	static int n,m,a[1000000+2],k=1;
	static long long int ans=0;
	static bool b[1000000+2],c[1000000+2];
	fill(b,b+1000000+2,true);
	fill(c,c+1000000+2,false);
	scanf("%d",&n);
	m=n+1;
	ans=n;
	while(k-1<n)k*=2;
	k--;
	for(int i=0;i<=n;i++){
		a[i]=k-i;
		if(a[i]<=n&&b[a[i]]){m--; b[a[i]]=false; c[i]=true;}
	}
	k++; k/=2;
	while(m>0){
		for(int i=0;i<=n;i++){
			if(!c[i]){
				a[i]%=k;
				if(b[a[i]]){m--; b[a[i]]=false; c[i]=true;}
			}
		}
		k/=2;
	}
	printf("%I64d\n",ans*(ans+1));
	printf("%d",a[0]);
	for(int i=1;i<=n;i++)printf(" %d",a[i]);
}