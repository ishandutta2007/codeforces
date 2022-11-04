#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[10],e[10][10],at[10];
bool in[10];
bool check(bool wzp=0){
	for (int i=0;(i+1)<(1<<m);i++){
		int e=0,v=0;
		for (int j=0;j<m;j++)
			if ((i>>j)&1) v+=cnt[j+1];
		for (int a=0;a<m;a++)
			for (int b=a;b<m;b++)
				if (((i>>a)&1)||((i>>b)&1))
					e+=::e[a+1][b+1];
		if (e<v+(bool)(i%2&&wzp)) return 0;
	}
	return 1;
}
char s1[10],s2[10];
void init(){
	memset(in,0,sizeof(in));
	at[1]=1;
	for (int i=2;i<=6;i++)
		at[i]=at[i-1]*10;
	scanf("%d",&n);
	int x=n; m=0;
	for (;x;x/=10,m++);
	for (int i=1;i<m;i++)
		cnt[i]=at[i+1]-at[i];
	cnt[m]=n-at[m]+1;
	for (int i=1;i<n;i++){
		scanf("%s%s",s1,s2);
		int l1=strlen(s1);
		int l2=strlen(s2);
		e[l1][l2]++;
		if (l1!=l2)
			e[l2][l1]++;
	}
	cnt[1]--;
	in[1]=1;
	at[1]=2;
}
void solve(){
	if (!check(1)){
		puts("-1");
		return;
	}
	int ans=0;
	for (;ans<n-1;){
		for (int b=1;b<=m;b++)
			for (int a=1;a<=m;a++){
				if (!in[b]||!e[a][b]||!cnt[a]) continue;
				e[a][b]--; cnt[a]--;
				if (a!=b) e[b][a]--;
				if (check()){
					printf("%d %d\n",at[b]-1,at[a]);
					at[a]++; in[a]=1; ans++;
				}
				else{
					e[a][b]++; cnt[a]++;
					if (a!=b) e[b][a]++;
				}
			}
	}
}
int main(){
	init();
	solve();
}