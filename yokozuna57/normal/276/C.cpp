#include<iostream>
using namespace std;

int main(){
	static long long int n,q,a[200000+5],b[200000+5],c,d,e[200000+5];
	long long int ans=0;
	for(int i=0;i<200000+5;i++){a[i]=0; b[i]=0; e[i]=0;}
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&c);
		a[c]++;
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&c,&d);
		b[c]++;
		b[d+1]--;
	}
	for(int i=1;i<n+1;i++){
		b[i]=b[i-1]+b[i];
		e[b[i]]++;
	}
	c=200000+4;
	d=200000+4;
	for(int i=0;i<n;i++){
		while(a[c]==0)c--;
		while(e[d]==0)d--;
		ans+=c*d;
		a[c]--;
		e[d]--;
	}
	printf("%I64d",ans);
}