#include<bits/stdc++.h>
using namespace std;
int n,a[10][2],A,B=1023,C;
char s[100];
int main(){
	scanf("%d",&n);
	for(int i=0;i<10;++i)	
		for(int j=0;j<2;++j)
			a[i][j]=j; 
	for(int i=1,x;i<=n;i++){
		scanf("%s%d",s,&x);
		if(s[0]=='|')for(int i=0;i<10;++i)for(int j=0;j<2;++j)a[i][j]|=x>>i&1;
		if(s[0]=='^')for(int i=0;i<10;++i)for(int j=0;j<2;++j)a[i][j]^=x>>i&1;
		if(s[0]=='&')for(int i=0;i<10;++i)for(int j=0;j<2;++j)a[i][j]&=x>>i&1;
	}
	for(int i=0;i<10;++i){
		if(a[i][0]==0&&a[i][1]==0)B^=1<<i;
		else if(a[i][0]==1&&a[i][1]==0)C^=1<<i;
		else if(a[i][0]==1&&a[i][1]==1)A^=1<<i;
	}
	printf("3\n");
	printf("| %d\n",A);
	printf("& %d\n",B);
	printf("^ %d\n",C);
}