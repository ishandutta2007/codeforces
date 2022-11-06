#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
std::unordered_map<long long,int>M;
std::stack<std::vector<int> >S;
std::vector<int>V[100002],e;
int n,m,cnt[100002],cnt0[100002],top=0;
int Last[100002],Next[200002],End[200002],diss[200002],maxs[100002],s[100002],ans[100002],tot=0;
inline void addedge(int s,int t){
	End[++tot]=t;Next[tot]=Last[s];Last[s]=tot;
	End[++tot]=s;Next[tot]=Last[t];Last[t]=tot;
}
void getsiz(int p,int f){s[p]=1;for(int i=Last[p];i;i=Next[i])if(!diss[End[i]]&&End[i]!=f)getsiz(End[i],p),s[p]+=s[End[i]];}
int getg(int p,int f,int ts){
	int g=0,h;maxs[p]=ts-s[p];
	for(int i=Last[p];i;i=Next[i])if(!diss[End[i]]&&End[i]!=f){
		h=getg(End[i],p,ts);
		if(maxs[g]>maxs[h])g=h;
		if(s[End[i]]>maxs[p])maxs[p]=s[End[i]];
	}return maxs[p]>maxs[g]?g:p;
}
void work(int p,int d){
	getsiz(p,0);p=getg(p,0,s[p]);ans[p]=d;diss[p]=1;
	for(int i=Last[p];i;i=Next[i])if(!diss[End[i]])work(End[i],d+1);
}
int main(){
	scanf("%d%d",&n,&m);maxs[0]=1e9;
	for(int i=1;i<=m;i++){
		int hdhd,akioi;scanf("%d%d",&hdhd,&akioi);
		if(hdhd>akioi)hdhd^=akioi^=hdhd^=akioi;
		cnt[hdhd]++;cnt0[akioi]++;
	}S.push(e);
	for(int i=1;i<=n;i++){
		while(cnt0[i]--)S.top().push_back(i),V[++top]=S.top(),S.pop();
		S.top().push_back(i);
		while(cnt[i]--)S.push(e),S.top().push_back(i);
	}V[++top]=S.top();
	std::sort(V+1,V+top+1,[](std::vector<int>a,std::vector<int>b){
		if(a.back()!=b.back())return a.back()<b.back();
		if(*(a.end()-2)!=*(b.end()-2))return *(a.end()-2)<*(b.end()-2);
		return *(a.end()-3)<*(b.end()-3);});
	for(int i=1;i<=top;i++){
		for(int j=V[i].size()-1;j;j--)if(V[i][j]-V[i][j-1]!=1){
			auto p=1000000ll*V[i][j-1]+V[i][j];
			auto pt=M.find(p);
			if(pt!=M.end())addedge(pt->second,i);
			else M[p]=i;
		}if(!(V[i].front()==1&&V[i].back()==n)){
			auto p=1000000ll*V[i].front()+V[i].back();
			auto pt=M.find(p);
			if(pt!=M.end())addedge(pt->second,i);
			else M[p]=i;
		}
	}work(1,1);for(int i=1;i<=top;i++)printf("%d ",ans[i]);
}