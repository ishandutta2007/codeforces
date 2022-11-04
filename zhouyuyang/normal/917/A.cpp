#include<bits/stdc++.h>
using namespace std;
int f[5005],g[5005];
char s[5005];
int ans;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++){
		f[i-1]=g[i-1]=0;
		for (int j=i;j<=n;j++){
			f[j]=f[j-1]+(s[j]==')'?-1:1);
			g[j]=(s[j]=='('?g[j-1]+1:max(g[j-1]-1,(j-i+1)&1));
			if (f[j]<0) break;
			ans+=(g[j]==0);
		}
	}
	printf("%d",ans);
}