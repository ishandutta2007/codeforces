#include<bits/stdc++.h>
int n,i;
char c[199];
int main(){
	for(scanf("%d",&n);n--;){
		scanf("%s",c);
		int c0=0,c1=0,c2=0;
		for(i=0;c[i];++i)c0+=c[i]=='0',c1+=c[i]%2==0,c2+=c[i]-'0';
		puts(c2%3 || !c0 || c1==1?"cyan":"red");
	}
	return 0;
}