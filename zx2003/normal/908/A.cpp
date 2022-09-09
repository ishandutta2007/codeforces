#include<bits/stdc++.h>
char c[55];
int ans,i,x;
int main(){
	scanf("%s",c+1);
	for(i=1;c[i];++i)
		if(isdigit(c[i]))x=c[i]-'0',ans+=x&1;
			else ans+=c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u';
	return printf("%d\n",ans),0;
}