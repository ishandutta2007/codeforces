#include<bits/stdc++.h>
using namespace std;
int n,st,aim;
struct AA{
	int val,nex;
}a[100100];
int p[1111],clo=0,used[100100];

AA que(int x){
	if (used[x]) return a[x];
	used[x]=1;
	printf("? %d\n",x);
	fflush(stdout);
	AA t;
	scanf("%d%d",&t.val,&t.nex);
	return t;
}

void out(int ans){
	printf("! %d\n",ans);
	fflush(stdout);
	exit(0);
}

int main(){
	scanf("%d%d%d",&n,&st,&aim);
	a[p[0]=st]=que(st);
	if (a[st].val>=aim){
		out(que(st).val);
	}
	for (int i=1;i<=200;i++){
		p[i]=(rand()*2333ll+rand())%n+1;
		a[p[i]]=que(p[i]);
		if (a[p[i]].val<aim){
			if (a[p[i]].val>a[p[clo]].val){
				clo=i;
			}
		}
	}
	int now=p[clo];
	for (;a[now].val<aim;now=a[now].nex){
		a[now]=que(now);
		if (a[now].val>=aim) out(a[now].val);
		if (a[now].nex==-1) out(-1);
	}
	out(a[now].val);
}