#include<bits/stdc++.h>
using namespace std;
char s[520233];
int b[2222],l,k,cnt;

int main(){
	scanf("%s",s+1);
	l=strlen(s+1);
	scanf("%d",&k);
	if (l<k){
		printf("impossible\n");
		return 0;
	}
	for (int i=1;i<=l;i++){
		cnt+=b[s[i]]++==0?1:0;
	}
	printf("%d\n",cnt>k?0:k-cnt);
}