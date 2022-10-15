#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#define gg() {for(register int q=0;q<n;++q)printf("%d ",ans.np[q]+1);return 0;}
const int prd=19260817;
int harry=1e9+7;
int n,m,b,res,now,c[10],d[10],nx[10],a[10][200010],bpr[40]={100001087,100001107,100001119,100001131,100001147,100001159,100001177,100001183,100001203,100001207,100001219,100001227,100001303,100001329,100001333,100001347,100001357,100001399,100001431,100001449,100001467,100001507,100001533,100001537,100001569,100001581,100001591,100001611,100001623,100001651};
struct state{
	int sum,np[10];
	state():sum(0){};
	state(int arr[10]){sum=0,memcpy(np,arr,sizeof(np));for(register int i=0;i<n;++i)sum+=a[i][np[i]];};
	inline bool operator<(const state nxt)const{
		return sum<nxt.sum;
	}
	inline bool operator>(const state nxt)const{
		return sum>nxt.sum;
	}
	inline int convert(){
		res=0;
		for(register int i=0;i<n;++i)res=(long long)res*prd%harry+np[i]+1,res%=harry;
		return res;
	}
}ans,nstate,xstate;
std::map<int,bool> map,vis;
std::queue<state> p;
int main(){
	srand(time(NULL));
	harry=bpr[rand()%25];
	scanf("%d",&n);
	for(register int i=0;i<n;++i){
		scanf("%d",&c[i]),d[i]=c[i]-1;
		for(register int j=0;j<c[i];++j)scanf("%d",&a[i][j]);
	}
	scanf("%d",&m);
	for(register int i=0;i<m;++i){
		now=0;
		for(register int j=0;j<n;++j){
			scanf("%d",&b);
			now=(long long)now*prd%harry+b,now%=harry;
		}
		map[now]=true;
	}
	p.push(state(d));
	while(p.size()){
		nstate=p.front(),p.pop();
		if(!map[nstate.convert()]){if(ans<nstate)ans=nstate;continue;};
		memcpy(nx,nstate.np,sizeof(nx));
		for(register int i=0;i<n;++i){
			if(nx[i]){
				--nx[i];
				xstate=state(nx);
				if(!vis[xstate.convert()])p.push(state(nx)),vis[xstate.convert()]=true;
				++nx[i];
			}
		}
	}
	gg();
	return 0;
}