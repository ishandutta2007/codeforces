#include<vector>
#include<cstdio>
#include<ctime>
using std::vector;
int ans,i,n,q,j,y;
unsigned int t,w,l,x;
char c[1505],d;
vector<int> a[200],aa[200];
inline void up(int&a,int b){
	if(a<b)a=b;
}
int main(){
	scanf("%d%s%d",&n,c+1,&q);
	for(i=1;i<=n;++i){
		if(a[c[i]].size()==0)aa[c[i]].push_back(i);
			else aa[c[i]].push_back(i-a[c[i]].back());
		a[c[i]].push_back(i);
	}
	for(i=1;i<=q;++i){
		scanf("%d %c",&j,&d);l=j;
		x=0;
		vector<int>&b=aa[d];
		for(t=ans=w=0;t<b.size();++t){
			while(t>w)++w;
			while(w<b.size() && x<=l)++w,x+=b[w]-1;
			x-=b[w]-1;
			--w;
			up(ans,l+1+w-t);
			if(w>t)x-=b[t+1]-1;
		}
		if(b.size()==0)ans=l;
		if(ans>n)ans=n;
		printf("%d\n",ans);
	}
	//printf("%d",(int)clock());
	return 0;
}