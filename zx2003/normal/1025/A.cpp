#include<bits/stdc++.h>
bool b[260],fl;
int n,i;
char c[100005];
int main(){
	scanf("%d%s",&n,c+1);fl=n==1;
	for(i=1;i<=n;++i){
		fl|=b[c[i]-'a'];
		b[c[i]-'a']=1;
	}
	puts(fl?"Yes":"No");
	return 0;
}