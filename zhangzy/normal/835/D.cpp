#include<bits/stdc++.h>
using namespace std;
int f[5010][5010],cnt[5010],l;
char s[10010];

void doit(int p1,int p2,int p){
	while (p1>0&&p2<=l){
		if (s[p1]!=s[p2]){
			return;
		}
		f[p1][p2]=f[p1][p]+1;
		cnt[f[p1][p2]]++;
		p1--;p2++;
	}
}
int main(){
	scanf("%s",s+1);
	l=strlen(s+1);
	memset(f,0,sizeof(f));
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=l;i++){
		f[i][i]=1;
		cnt[1]++;
		doit(i,i+1,i);
		doit(i,i+2,i);
	}
	for (int i=l;i>1;i--){
		cnt[i-1]+=cnt[i];
	}
	for (int i=1;i<=l;i++){
		printf("%d ",cnt[i]);
	}
}