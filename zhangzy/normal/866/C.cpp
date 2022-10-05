#include<bits/stdc++.h>
#define db long double
using namespace std;

int n,m,a[55],b[55],x;
db f[55][5050],c[55],now,res;

void doit(){
	for (int i = 0; i <= m; i++) f[n+1][i]=0;
	for (int i=n;i>0;i--){
		for (int j=0;j<=m;j++){
			f[i][j]= c[i] *( a[i]+ (j+a[i]>m? now: min(f[i+1][j+a[i]],now) ) );
			f[i][j]+= (1-c[i]) *( b[i]+ (j+b[i]>m? now: min(f[i+1][j+b[i]],now) ) );
		}
	}
	res=f[1][0];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d%d%d", a+i, b+i, &x);
		c[i]= x/100.0;
	}
	db l=0.0,r=1000000000.0;
	for (int i = 1; i <= 233; i++) {
		now= (l+r) /2.0;
		doit();
		if (res > now) {
			l = now;
		} else {
			r = now;
		}
	}
	printf("%.233lf",(double)l);
}