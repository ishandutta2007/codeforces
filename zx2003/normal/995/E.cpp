#include<bits/stdc++.h>
using namespace std;
int u,v,mo;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
vector<int>ans;
struct aaa{
unordered_map<int,unsigned>S;
void dfs(int x,int d,int pre,int o){
	if(pre==-1)S[x]=-1;else S[x]=pre*3u+o;
	if(d==45 || S.size()>2000000)return;
	int y;
	y=(x+1)%mo;if(!S.count(y))dfs(y,d+1,x,0);
	y=(x+mo-1)%mo;if(!S.count(y))dfs(y,d+1,x,1);
	y=poww(x,mo-2);if(!S.count(y))dfs(y,d+1,x,2);
}
void doo(int x){
	dfs(x,0,-1,0);
//	cout<<S.size()<<endl;
}
void out(int x,int tp){
	vector<int>ve;
	for(;S[x]!=-1;x=S[x]/3)ve.push_back(S[x]%3);
	if(!tp)reverse(ve.begin(),ve.end());else for(int&x:ve)if(x==0)x=1;else if(x==1)x=0;
	ans.insert(ans.end(),ve.begin(),ve.end());
}
}a1,a2;
int main(){
	scanf("%d%d%d",&u,&v,&mo);
	a1.doo(u);a2.doo(v);
	//for(int x:a2.S)if(a1.S.count(x)){printf("%d\n",x);return 0;}
	for(auto u:a2.S)if(a1.S.count(u.first)){a1.out(u.first,0),a2.out(u.first,1);break;}
	printf("%d\n",int(ans.size()));for(int x:ans)printf("%d ",x+1);puts("");
}