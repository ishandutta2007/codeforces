#include<bits/stdc++.h>
using namespace std;
int n,m,b[100005],c[100005];
int main(){
	scanf("%d%d",&n,&m);
	if (n>4){
		puts("YES");
		int tot1=0,tot2=0;
		for (int i=(n+1)/2*2-1;i>=1;i-=2)
			b[++tot1]=i;
		for (int i=n/2*2;i>0;i-=2)
			b[++tot1]=i;
		for (int i=(n+1)/2*2-1-2;i>=1;i-=2)
			c[++tot2]=i;
		c[++tot2]=(n+1)/2*2-1;
		c[++tot2]=2;
		for (int i=n/2*2;i>2;i-=2)
			c[++tot2]=i;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				printf("%d ",((j&1?b[i]:c[i])-1)*m+j);
			puts("");
		}
		return 0;
	}
	if (m>4){
		puts("YES");
		int tot1=0,tot2=0;
		for (int i=(m+1)/2*2-1;i>=1;i-=2)
			b[++tot1]=i;
		for (int i=m/2*2;i>0;i-=2)
			b[++tot1]=i;
		for (int i=(m+1)/2*2-1-2;i>=1;i-=2)
			c[++tot2]=i;
		c[++tot2]=(m+1)/2*2-1;
		c[++tot2]=2;
		for (int i=m/2*2;i>2;i-=2)
			c[++tot2]=i;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				printf("%d ",(i-1)*m+(i&1?b[j]:c[j]));
			puts("");
		}
		return 0;
	}
	if (n==1&&m==1){
		puts("YES");
		puts("1");
		return 0;
	}
	if (n==1&&m<=3){
		puts("NO");
		return 0;
	}
	if (n<=3&&m==1){
		puts("NO");
		return 0;
	}
	if (n==2&&m==2){
		puts("NO");
		return 0;
	}
	if (n==3&&m==3){
		puts("YES");
		puts("8 1 6");
		puts("3 5 7");
		puts("4 9 2");
		return 0;
	}
	if (n==3&&m==2){
		puts("NO");
		return 0;
	}
	if (n==2&&m==3){
		puts("NO");
		return 0;
	}
	if (n==1&&m==4){
		puts("YES");
		puts("3 1 4 2");
		return 0;
	}
	if (n==2&&m==4){
		puts("YES");
		puts("5 4 7 2");
		puts("3 6 1 8");
		return 0;
	}
	if (n==3&&m==4){
		puts("YES");
		puts("1 3 5 7");
		puts("9 11 2 4");
		puts("6 8 10 12");
		return 0;
	}
	if (n==4&&m==4){
		puts("YES");
		puts("1 3 5 7");
		puts("9 11 13 15");
		puts("2 4 6 8");
		puts("10 12 14 16");
		return 0;
	}
	if (n==4&&m==1){
		puts("YES");
		puts("3");
		puts("1");
		puts("4");
		puts("2");
		return 0;
	}
	if (n==4&&m==2){
		puts("YES");
		puts("4 5");
		puts("1 8");
		puts("7 2");
		puts("6 3");
		return 0;
	}
	if (n==4&&m==3){
		puts("YES");
		puts("1 3 5");
		puts("7 9 11");
		puts("2 4 6");
		puts("8 10 12");
		return 0;
	}
}