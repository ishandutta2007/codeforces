#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,i,j,x,l,r,su[N][26];
char c[N];
int main(){
	scanf("%s%d",c+1,&q);n=strlen(c+1);
	for(i=1;i<=n;++i)memcpy(su[i],su[i-1],104),++su[i][c[i]-'a'];
	for(;q--;){
		scanf("%d%d",&l,&r);
		if(l==r || c[l]!=c[r]){puts("Yes");continue;}
		x=0;for(j=0;j<26;++j)x+=su[r][j]>su[l-1][j];
		puts(x>=3?"Yes":"No");
	}
	return 0;
}