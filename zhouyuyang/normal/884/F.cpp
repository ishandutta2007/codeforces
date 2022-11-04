#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],C[105];
int n,ans,S,tot;
char s[105];
int calc(int v,int c){
	tot=0;
	for (int i=1;i<=n/2;i++)
		if (s[i]!=s[n-i+1]&&s[i]!=v&&s[n-i+1]!=v)
			b[++tot]=min(a[i],a[n-i+1]);
	sort(b+1,b+tot+1);
	for (int i=1;i<=c;i++)
		ans-=b[i];
}

int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans+=a[i];
	for (int i=1;i<=n/2;i++)
		if (s[i]==s[n-i+1]){
			C[s[i]-'a']++; S++;
			ans-=min(a[i],a[n-i+1]);
		}
	for (int i=0;i<26;i++)
		if (C[i]*2>S) calc(i+'a',C[i]*2-S);
	printf("%d",ans);
}