#include<bits/stdc++.h>
#define N 1000005
using namespace std;
char s[N],t[N],S[N];
int n,ch[N][26],len[N],fa[N];
int top,la,dif[N],lk[N];
void extend(int n){
	int w=S[n],p=la;
	for (;S[n-len[p]-1]!=w;p=fa[p]);
	if (!ch[p][w-'a']){
		len[++top]=len[p]+2;
		int q=top,now=p;
		do now=fa[now]; while (S[n-len[now]-1]!=w);
		fa[q]=ch[now][w-'a']; ch[p][w-'a']=q;
		dif[q]=len[q]-len[fa[q]];
		lk[q]=(dif[q]==dif[fa[q]]?lk[fa[q]]:fa[q]);
	}
	la=ch[p][w-'a'];
}
int ans[N],_ans[N],from[N];
int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
		S[i*2-1]=s[i],S[i*2]=t[i];
	fa[0]=top=1; len[1]=-1; n*=2;
	for (int i=1;i<=n;i++)
		ans[i]=1e9;
	_ans[0]=1;
	for (int i=1;i<=n;i++){
		extend(i);
		for (int p=la;p;p=lk[p]){
			_ans[p]=i-(len[lk[p]]+dif[p]);
			if (dif[fa[p]]==dif[p]&&ans[_ans[p]]>ans[_ans[fa[p]]])
				_ans[p]=_ans[fa[p]];
			if (!(i&1)&&ans[i]>ans[_ans[p]]+1)
				ans[i]=ans[_ans[p]]+1,from[i]=_ans[p];
		}
		if (!(i&1)&&S[i-1]==S[i]&&ans[i]>ans[i-2])
			ans[i]=ans[i-2],from[i]=i-2;
	}
	if (ans[n]<1e9){
		printf("%d\n",ans[n]);
		for (int i=n;i;i=from[i])
			if (i-from[i]>2) printf("%d %d\n",(from[i]>>1)+1,i>>1);
	}
	else puts("-1");
}