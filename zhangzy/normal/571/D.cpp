#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,g=0,fa[1001000],sz[1001000],cnt,pos[1001000];
ll v[1001000]={0},ans[1001000]={0};
struct OPT{
	int who,opt,val,id;
}o[1001000];
bool cmp(OPT o1,OPT o2){
	return o1.opt>o2.opt;
}
int t1[1001000],t2[1001000],t3[1001000];
char s[233];

int MX(int x){
	if (fa[fa[x]]==fa[x]) return fa[x];
	int orgfa=fa[x];
	fa[x]=MX(fa[x]);
	v[x]=max(v[x],v[orgfa]);
	return fa[x];
}
int quemax(int x){
	if (fa[x]==x) return v[x];
	fa[x]=MX(x);
	return max(v[x],v[fa[x]]);
}

int TOT(int x){
	if (fa[fa[x]]==fa[x]) return fa[x];
	int orgfa=fa[x];
	fa[x]=TOT(fa[x]);
	v[x]+=v[orgfa];
	return fa[x];
}
ll quetot(int x){
	if (fa[x]==x) return v[x];
	fa[x]=TOT(x);
	return v[x]+v[fa[x]];
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%s",s);
		t1[i]=s[0];
		scanf("%d",&t2[i]);
		if (t1[i]=='U'||t1[i]=='M') scanf("%d",&t3[i]);
	}
	
	cnt=n;
	for (int i=1;i<=n;i++){
		fa[i]=i;
		pos[i]=i;
		v[i]=0;
	}
	for (int i=1;i<=m;i++){
		if (t1[i]=='M'){
			v[++cnt]=0;
			fa[MX(t2[i])]=cnt;
			fa[MX(t3[i])]=cnt;
			fa[cnt]=cnt;
			pos[t2[i]]=cnt;
		}else if (t1[i]=='Z'){
			v[MX(pos[t2[i]])]=i;
		}else if (t1[i]=='Q'){
			o[++g]=(OPT){t2[i],quemax(t2[i]),-1,i};
			o[++g]=(OPT){t2[i],i,1,i};
		}
	}
	
	sort(o+1,o+g+1,cmp);
	cnt=n;
	for (int i=1;i<=n;i++){
		fa[i]=i;
		v[i]=0;
		pos[i]=i;
		sz[i]=1;
	}
	for (int i=1;i<=m;i++){
		while (g>0&&o[g].opt<=i){
			//printf(" %d %d %d %d  %d\n",o[g].who,o[g].opt,o[g].val,o[g].id,quetot(o[g].who));
			ans[o[g].id]+=o[g].val*quetot(o[g].who);
			g--;
		}
		if (t1[i]=='U'){
			v[++cnt]=0;
			fa[cnt]=cnt;
			sz[cnt]=sz[TOT(t2[i])]+sz[TOT(t3[i])];
			fa[TOT(t2[i])]=cnt;
			fa[TOT(t3[i])]=cnt;
			pos[t2[i]]=cnt;
		}else if (t1[i]=='A'){
			v[TOT(pos[t2[i]])]+=sz[TOT(pos[t2[i]])];
			//printf("%d %d %d\n",pos[t2[i]],TOT(pos[t2[i]]),v[TOT(pos[t2[i]])]);
		}
	}
	
	for (int i=1;i<=m;i++){
		if (t1[i]=='Q'){
			printf("%I64d\n",ans[i]);
		}
	}
}