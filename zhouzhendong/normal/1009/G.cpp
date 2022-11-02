#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
char s[N];
int n,v[N],suf[N][64],tot[64],sum[64],Log[64];
void getv(){
	int m=read();
	memset(v,0,sizeof v);
	while (m--){
		int id=read();
		char s[10];
		scanf("%s",s+1);
		int len=strlen(s+1);
		for (int i=1;i<=len;i++)
			v[id]|=1<<(s[i]-'a');
	}
	for (int i=1;i<=n;i++)
		if (v[i]==0)
			v[i]=63;
}
bool check(int p){
	sum[0]=0;
	for (int i=1;i<64;i++){
		sum[i]=sum[i^(i&-i)]+tot[i&-i];
		if (sum[i]<suf[p][i])
			return 0;
	}
	return 1;
}
int main(){
	Log[1]=0;
	for (int i=2;i<64;i++)
		Log[i]=Log[i>>1]+1;
	gets(s+1);
	n=strlen(s+1);
	getv();
	memset(tot,0,sizeof tot);
	for (int i=1;i<=n;i++)
		tot[1<<(s[i]-'a')]++;
	memset(suf,0,sizeof suf);
	for (int i=n;i>=1;i--){
		for (int j=0;j<64;j++)
			suf[i][j]=suf[i+1][j];
		suf[i][v[i]]++;
	}
	for (int id=1;id<=n;id++)
		for (int i=1;i<64;i<<=1)
			for (int j=0;j<64;j++)
				if (j&i)
					suf[id][j]+=suf[id][j^i];
	if (!check(1)){
		printf("Impossible");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=v[i],k=j&-j;j;j^=k,k=j&-j){
			tot[k]--;
			if (check(i+1)){
				putchar('a'+Log[k]);
				break;
			}
			tot[k]++;
		}
	return 0;
}