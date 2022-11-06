#include<stdio.h>
char c[1000002];
int n,m,a[26][1000002];
int main(){
	scanf("%s%d",c+1,&m);
	for(n=1;c[n];n++){
		a[c[n]-'a'][n]=1;
		for(int i=0;i<26;i++)a[i][n]+=a[i][n-1];
	}while(m--){
		int l,r;scanf("%d%d",&l,&r);
		int cnt=0;for(int i=0;i<26;i++)cnt+=a[i][r]!=a[i][l-1];
		if(l==r||cnt>2)printf("Yes\n");
		else if(cnt==1)printf("No\n");
		else printf("%s\n",c[l]==c[r]?"No":"Yes");
	}
}