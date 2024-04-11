#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k;
int Next[N][26],tot=1;
char s[N];
void build(char ch[]){
	int rt=1,len=strlen(ch),t;
	for (int i=0;i<len;i++){
		t=ch[i]-'a';
		if (Next[rt][t]==0)
			Next[rt][t]=++tot;
		rt=Next[rt][t];
	}
}
int solve(int rt){
	int ans=0;
	for (int i=0;i<26;i++)
		if (Next[rt][i]!=0)
			ans|=!solve(Next[rt][i]);
	return ans;
}
int solve2(int rt){
	int ans=0,f=0;
	for (int i=0;i<26;i++)
		if (Next[rt][i]!=0)
			f=1,ans|=!solve2(Next[rt][i]);
	return ans||!f;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		build(s);
	}
	int win=solve(1),lose=solve2(1);
	if (!win)
		puts("Second");
	else if (win&&lose)
		puts("First");
	else
		puts(k%2==0?"Second":"First");
	return 0;
}