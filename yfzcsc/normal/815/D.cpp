#include<bits/stdc++.h>
#define maxn 500100
using namespace std;
typedef pair<int,int> par;
long long ans=0,cur=0;
int n,p,q,r,x,y,A[maxn],B[maxn],C[maxn];
vector<par>v[maxn];
set<par>st;
int main(){
	scanf("%d%d%d%d",&n,&p,&q,&r);
	ans=1ll*p*q*r,cur=0;
	st.insert(par(0,1<<30));
	st.insert(par(1<<30,0));
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
	for(int i=1;i<=n;++i)
		v[r].push_back(par(A[i],B[i])),
		v[C[i]].push_back(par(A[i],q)),
		v[C[i]].push_back(par(p,B[i]));
	for(int i=r;i>=1;ans-=cur,i--){
		for(int j=0;j<v[i].size();++j){
			par wxh=v[i][j],xxt;
			set<par>::iterator it=st.lower_bound(wxh);
			if(it!=st.end()&&it->second>=wxh.second)continue;
			xxt.second=(it==st.end()?0:it->second);
			xxt.first=wxh.first;
			set<par>::iterator xt=it;xt--;
			while(true){
				cur+=1ll*(xxt.first-xt->first)*(wxh.second-xxt.second);
				if(xt->second>wxh.second)break;
				if(xt==st.begin()){xxt=*xt,st.erase(xxt);break;}
				else xxt=*xt,xt--,st.erase(xxt);
			}
			st.insert(wxh);
		}
	//	for(auto s:st)printf("{%d,%d}",s.first,s.second);
	//	printf("[%lld,%d,%d]\n",cur,i,p*q);
	}
	printf("%lld\n",ans);
}