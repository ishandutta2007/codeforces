#include<bits/stdc++.h>
const int mo=1e9+7,N=1e6+5;
char c[N];
int i,v,ans;
int main(){
	scanf("%s",c+1);
	for(i=1;c[i];++i)if(c[i]=='a')v=(v<<1|1)%mo;else ans=(ans+v)%mo;
	printf("%d\n",ans);
}