#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2000005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m,id[N],pos[N],len[N],st[N],top=0;
char s[N],t[N];
char get_top(int i){
	while (top>0){
		int ID=id[st[top]];
		if (ID==0||st[top]+len[ID]-1<i)
			top--;
		else
			return t[pos[ID]+i-st[top]];
	}
	return 'a';
}
int main(){
	n=read(),m=0;
	memset(id,0,sizeof id);
	pos[1]=0;
	for (int i=1;i<=n;i++){
		scanf("%s",t+pos[i]);
		len[i]=strlen(t+pos[i]);
		pos[i+1]=pos[i]+len[i];
		int k=read();
		while (k--){
			int x=read();
			if (!id[x]||len[i]>len[id[x]])
				id[x]=i;
			m=max(m,x+len[i]-1);
		}
	}
	for (int i=1;i<=m;i++){
		st[++top]=i;
		putchar(get_top(i));
	}
	return 0;
}