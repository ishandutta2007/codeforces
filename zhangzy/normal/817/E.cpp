#include<bits/stdc++.h>
using namespace std;

int T,t,x,v,aim,ch[3003000][2],cnt=1,sz[3003000];

void add(){
	int p=1,c;
	for (int i=27;i>=0;i--){
		c=!!(x&(1<<i));
		if (!ch[p][c]) ch[p][c]=++cnt;
		p=ch[p][c];
		sz[p]+=v;
	}
}
void que(){
	int ans=0,p=1,c,ac;
	for (int i=27;i>=0;i--){
		c=!!(x&(1<<i)); ac=!!(aim&(1<<i));
		if (ac) ans+=sz[ch[p][c]];
		p=ch[p][ac^c];
	}
	printf("%d\n",ans);
}

int main(){
	for (scanf("%d",&T);T--;){
		scanf("%d%d",&t,&x);
		if (t==3){
			scanf("%d",&aim);
			que();
		}else{
			v=t==1?1:-1;
			add();
		}
	}
}