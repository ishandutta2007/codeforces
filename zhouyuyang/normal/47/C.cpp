#include<bits/stdc++.h>
using namespace std;
int len[10],ord[10],have,ansh,answ,vis[10];
char s[10][35],tmp[35][35],ans[35][35];
void check(){
	if (len[ord[1]]+len[ord[2]]-1!=len[ord[5]]) return;
	if (len[ord[3]]+len[ord[4]]-1!=len[ord[6]]) return;
	if (s[ord[1]][1]!=s[ord[3]][1]) return;
	if (s[ord[2]][len[ord[2]]]!=s[ord[4]][len[ord[4]]]) return;
	if (s[ord[1]][len[ord[1]]]!=s[ord[6]][1]) return;
	if (s[ord[3]][len[ord[3]]]!=s[ord[5]][1]) return;
	if (s[ord[2]][1]!=s[ord[6]][len[ord[6]]]) return;
	if (s[ord[4]][1]!=s[ord[5]][len[ord[5]]]) return;
	if (s[ord[5]][len[ord[1]]]!=s[ord[6]][len[ord[3]]]) return;
	int w=len[ord[5]],h=len[ord[6]],fl=have?2:1; have=1;
	memset(tmp,46,sizeof(tmp));
	for (int i=1;i<=len[ord[1]];i++)
		tmp[1][i]=s[ord[1]][i];
	for (int i=1;i<=len[ord[2]];i++)
		tmp[h][w-len[ord[2]]+i]=s[ord[2]][i];
	for (int i=1;i<=len[ord[3]];i++)
		tmp[i][1]=s[ord[3]][i];
	for (int i=1;i<=len[ord[4]];i++)
		tmp[h-len[ord[4]]+i][w]=s[ord[4]][i];
	for (int i=1;i<=len[ord[5]];i++)
		tmp[len[ord[3]]][i]=s[ord[5]][i];
	for (int i=1;i<=len[ord[6]];i++)
		tmp[i][len[ord[1]]]=s[ord[6]][i]; 
	for (int i=1;i<=30&&fl==2;i++){
		for (int j=1;j<=30&&fl==2;j++){
			if (tmp[i][j]<ans[i][j]) fl=1;
			if (tmp[i][j]>ans[i][j]) fl=0;
		}
		if (fl==2){
			if (w<answ) fl=1;
			if (w>answ) fl=0;
		}
	}
	if (fl==1){
		ansh=h; answ=w;
		memcpy(ans,tmp,sizeof(ans));
	}
}
void dfs(int x){
	if (x==7){
		check();
		return;
	}
	for (int i=1;i<=6;i++)
		if (!vis[i]){
			vis[i]=1;
			ord[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main(){
	for (int i=1;i<=6;i++)
		scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
	dfs(1);
	if (!have){
		puts("Impossible");
	}
	for (int i=1;i<=ansh;i++){
		for (int j=1;j<=answ;j++)
			printf("%c",ans[i][j]);
		puts("");
	}
}