#include<bits/stdc++.h>
using namespace std;
#define N 600005
struct ACM{
	int ch[N][26],fail[N];
	int s[N],s2[N],rt[N];
	int w,sz,num[N];
	ACM(){
		w=1; sz=0;
	}
	int merge(int x,int y){
		if (!x||!y) return x|y;
		s[x]|=s[y];
		for (int i=0;i<26;i++)
			ch[x][i]=merge(ch[x][i],ch[y][i]);
		return x;
	}
	void getfail(int rt){
		static int q[N];
		int h=0,t=0;
		for (int i=0;i<26;i++){
			int to=ch[rt][i];
			if (to){
				fail[to]=rt;
				q[++t]=to;
				s2[to]=s[to];
			}
		}
		while (h!=t){
			int x=q[++h];
			for (int i=0;i<26;i++)
				if (ch[x][i]){
					int to=ch[x][i],k=fail[x];
					for (;k!=rt&&!ch[k][i];k=fail[k]);
					fail[to]=(ch[k][i]?ch[k][i]:rt);
					q[++t]=to; s2[to]=s2[fail[to]]+s[to];
				}
		}
	}
	void ins(char *c){
		int x=rt[++w]=++sz;
		num[w]=1; fail[x]=x;
		for (int i=0;c[i];i++){
			int tmp=c[i]-'a';
			ch[x][tmp]=++sz;
			x=ch[x][tmp];
		}
		s[x]=1;
		for (;w>1&&num[w]==num[w-1];){
			rt[w-1]=merge(rt[w-1],rt[w]);
			num[w-1]<<=1; w--;
		}
		getfail(rt[w]);
	}
	int que(char *c){
		int ans=0;
		for (int i=1;i<=w;i++){
			int x=rt[i];
			for (int j=0;c[j];j++){
				int tmp=c[j]-'a';
				for (;!ch[x][tmp]&&x!=rt[i];x=fail[x]);
				if (ch[x][tmp]){
					x=ch[x][tmp];
					ans+=s2[x];
				}
			}
		}
		return ans;
	}
}in,out;
char s[N];
int main(){
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int tp;
		scanf("%d%s",&tp,s);
		if (tp==1) in.ins(s);
		if (tp==2) out.ins(s);
		if (tp==3){
			printf("%d\n",in.que(s)-out.que(s));
			fflush(stdout);
		}
	}
}