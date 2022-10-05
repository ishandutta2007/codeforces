%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
struct edge{
	int from,to,waste,p;
}a[1001000];
struct vect{
	vector<int>vec;
	int bri;
}tem,nil;
map<long long,vect>mp;
map<int,int>has;
int n,m,fa[1001000],ans[1001000];
long long f1,f2,cg=1000000,t;
vector<int>r[1001000];
int b[1001000],used[1001000];
int low[1001000],cnt,dfn[1001000],dft;

int cmp(edge x,edge y){
	return x.waste<y.waste;
}

int father(int x){
	if (fa[x]==x) return x;
	fa[x]=father(fa[x]);
	return fa[x];
}

void hebin(int f1,int f2){
	if (father(f1)!=father(f2))
		fa[father(f1)]=father(f2);
}

void pri(){
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++){
		printf(" %d (%d) %d:",i,b[i],r[i].size());
		for (int j=0;j<r[i].size();j++)
			printf(" %d",r[i][j]);
		printf("\n");
	}
}
void addedge(int x,int y){
	r[x].push_back(y);
	r[y].push_back(x);
}
void dfs(int u,int fath)  {  
    dfn[u]=low[u]=++dft;  
    used[u]=1;  
    int v;
    for(int i=0;i<r[u].size();i++){  
        v=r[u][i];  
        if(!used[v]){  
            dfs(v,u);  
            low[u]=min(low[u],low[v]);  
            if(dfn[u]<low[v]) {
				mp[b[u]*cg+b[v]].bri=1;
				mp[b[v]*cg+b[u]].bri=1;
			}
        }  
        else if(fath!=v)
            low[u]=min(low[u],dfn[v]);  
    }  
} 

void newnode(int x){
	used[x]=0;
	dfn[x]=0;
	r[x].clear();
}

int main(){
	scanf("%d%d",&n,&m);
	nil.bri=0;
	nil.vec.clear();
	for (int i=1;i<=n;i++)
		fa[i]=i;
	int x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[i].from=x;
		a[i].to=y;
		a[i].waste=z;
		a[i].p=i;
	}
	sort(a+1,a+m+1,cmp);
	int l,r;
	l=1;r=1;
	a[m+1].waste=543823333;
	while (l<=m){
		while (a[r].waste==a[l].waste) r++;
		cnt=0;
		mp.clear();
		has.clear();
			for (int i=l;i<r;i++){
				f1=father(a[i].from);
				f2=father(a[i].to);
				if (f1==f2) continue;
				if (!has.count(f1)){
					has[f1]=++cnt;
					b[cnt]=f1;
					newnode(cnt);
				}
				if (!has.count(f2)){
					has[f2]=++cnt;
					b[cnt]=f2;
					newnode(cnt);
				}
				if (!mp.count(f1*cg+f2)){
					addedge(has[f1],has[f2]);
					mp[f1*cg+f2]=nil;
					mp[f2*cg+f1]=nil;
				}
				mp[f1*cg+f2].vec.push_back(a[i].p);
				mp[f1*cg+f2].bri=0;
				mp[f2*cg+f1].vec.push_back(a[i].p);
				mp[f2*cg+f1].bri=0;
			}
			//pri();
			for (int i=1;i<=cnt;i++){
				if (!used[i]){
					dft=0;
					dfs(i,0);
				}
			}
			for (map<long long,vect>::iterator j=mp.begin();j!=mp.end();j++){
				tem=j->second;
				if (tem.vec.size()==0) continue;
				if (tem.vec.size()==1)
					for (int i=0;i<tem.vec.size();i++)
						ans[tem.vec[i]]=tem.bri+1;
				else
					for (int i=0;i<tem.vec.size();i++)
						ans[tem.vec[i]]=1;
				t=j->first;
				f1=t/cg;
				f2=t%cg;
				mp[f2*cg+f1]=nil;
				hebin(f1,f2);
			}
		l=r;
	}
	
	for (int i=1;i<=m;i++){
		if (ans[i]==0) printf("none\n");
		if (ans[i]==1) printf("at least one\n");
		if (ans[i]==2) printf("any\n");
	}
}