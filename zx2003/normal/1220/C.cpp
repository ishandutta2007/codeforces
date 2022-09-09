#include<bits/stdc++.h>
const int N=5e5+5;
char c[N];
int n,i;
int main(){
	scanf("%s",c+1);n=strlen(c+1);char mn='z'+1;
	for(i=1;i<=n;++i){
		puts(mn<c[i]?"Ann":"Mike");
		mn=std::min(mn,c[i]);
	}
	return 0;
}