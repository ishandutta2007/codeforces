#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int tot[52],ans[3];
char s[N];
bool cmp(int a,int b){
	return a>b;
}
int Turn(char ch){
	if ('A'<=ch&&ch<='Z')
		return ch-'A'+26;
	return ch-'a';
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<3;i++){
		scanf("%s",s);
		int len=strlen(s);
		memset(tot,0,sizeof tot);
		for (int j=0;j<len;j++){
			tot[Turn(s[j])]++;
		}
		sort(tot,tot+52,cmp);
		ans[i]=0;
		for (int j=0;j<52;j++){
			if (tot[j]+n<=len)
				ans[i]=max(ans[i],tot[j]+n);
			else if (tot[j]==len&&n==1)
				ans[i]=max(ans[i],len-1);
			else
				ans[i]=max(ans[i],len);
		}
	}
	if (ans[0]>ans[1]&&ans[0]>ans[2]){
		puts("Kuro");
		return 0;
	}
	if (ans[1]>ans[0]&&ans[1]>ans[2]){
		puts("Shiro");
		return 0;
	}
	if (ans[2]>ans[0]&&ans[2]>ans[1]){
		puts("Katie");
		return 0;
	}
	puts("Draw");
	return 0;
}