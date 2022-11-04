#include<bits/stdc++.h>
using namespace std;
char s[125005],t[125005];
int a[6][6],f[6];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1);
	int m=strlen(t+1);
	for (int i=m;i<=n;i++){
		memset(a,0,sizeof(a));
		for (int j=1;j<=m;j++)
			a[s[i-m+j]-'a'][t[j]-'a']=1;
		for (int j=0;j<6;j++) f[j]=j;
		int ans=0;
		for (int j=0;j<6;j++)
			for (int k=0;k<6;k++)
				if (a[j][k]){
					int x=get(j),y=get(k);
					if (x!=y) f[x]=y,ans++;
				}
		printf("%d ",ans);
	}
}