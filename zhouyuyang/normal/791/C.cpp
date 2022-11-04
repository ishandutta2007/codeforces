#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
#define N 150005
using namespace std;
char ch[10],ans[55];
int flag[55],tag[55],n,m,tot;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=m;i<=n;i++){
		scanf("%s",ch);
		if (ch[0]=='Y')
			for (int j=i-m+1;j<i;j++) flag[j]=1;
		else tag[i]=1;
	}
	for (int i=1;i<=n;i++) ans[i]=i;
	for (int i=m;i<=n;i++)
		if (tag[i]){
			int ok=0;
			for (int j=i-m+1;j<i;j++)
				if (ans[j]==ans[j+1]) ok=1;
			if (ok) continue;
			for (int j=i-m+1;j<i;j++)
				if (!flag[j]){
					ans[j+1]=ans[j];
					ok=1;
					break;
				}
			if (ok) continue;
			ans[i]=ans[i-m+1];
		}
	for (int i=1;i<=n;i++)
		if (ans[i]>26) printf("%c ",'A'+ans[i]-27);
		else printf("T%c ",'a'+ans[i]-1);
}