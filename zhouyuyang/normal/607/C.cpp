#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int n,nxt[N*2],tot;
char a[N],b[N];
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	n--;
	reverse(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		if (b[i]=='E') b[i]='W';
		else if (b[i]=='W') b[i]='E';
		else if (b[i]=='S') b[i]='N';
		else b[i]='S';
	b[tot=n+1]=' ';
	for (int i=1;i<=n;i++)
		b[++tot]=a[i];
	for (int i=2,j=0;i<=tot;i++){
		for (;j&&b[i]!=b[j+1];j=nxt[j]);
		if (b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
	puts(nxt[tot]?"NO":"YES");
}