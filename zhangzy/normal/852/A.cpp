#include<bits/stdc++.h>
using namespace std;

int n,a[233333],v[233333],g,t,b,c,vb[233],gb,vc[233],gc,d;
int len[233333];
char s[233333];

int main(){
	scanf("%d\n%s",&n,s+1);
	for (int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	while (1){
		g=b=t=0;
		for (int i=1;i<=n;i+=t){
			t= i==n?1:(rand()&1)+1;
			b+= ( v[++g]= ((len[g]=t)==1? a[i] : a[i]*10+a[i+1] ) );
		}
		c=gb=0;
		for (int bb=b;bb;bb/=10){
			c+=( vb[++gb]=bb%10 );
		}
		d=gc=0;
		for (int cc=c;cc;cc/=10){
			d+=( vc[++gc]=cc%10 );
		}
		//printf(" %d %d %d\n",b,c,d);
		if (d<10){
			len[1]==2?printf("%02d",v[1]):printf("%d",v[1]);for (int i=2;i<=g;i++) len[i]==2?printf("+%02d",v[i]):printf("+%d",v[i]);printf("\n");
			printf("%d",vb[gb]);for (int i=gb-1;i>0;i--)printf("+%d",vb[i]);printf("\n");
			printf("%d",vc[gc]);for (int i=gc-1;i>0;i--)printf("+%d",vc[i]);printf("\n");
			return 0;
		}
	}
}