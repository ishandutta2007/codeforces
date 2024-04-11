#include<bits/stdc++.h>
using namespace std;
char s[1001000];
int n,tp;
char S[1001000];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while(r-l>2){
		if(s[l]==s[r])
			S[++tp]=s[l],l++,r--;
		else if(s[l]==s[r-1])
			S[++tp]=s[l],l++,r-=2;
		else if(s[l+1]==s[r])
			S[++tp]=s[r],l+=2,r--;
		else if(s[l+1]==s[r-1])
			S[++tp]=s[l+1],l+=2,r-=2;
	}
	printf("%s%c",S+1,s[l]);
	reverse(S+1,S+tp+1);
	puts(S+1);
}