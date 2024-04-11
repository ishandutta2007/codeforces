#include<bits/stdc++.h>
using namespace std;
#define LL long long
template<typename T> void read(T &x) {
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-') f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x=x*f;
}
const int N=300020;
vector<int>g[N];
int T;
int n,m,u,v,l;
bool b;
int c[N],q[3000020],ans[N],tp=0;
void Coloring_Vertices(){
	tp++;q[tp]=1;
	while(tp>0){
		int cur=q[tp];tp--;
		if(c[cur]==T) continue;
		c[cur]=T;l++;ans[l]=cur;
		for(int i=0;i<g[cur].size();i++){
			int x=g[cur][i];	
			if(c[x]!=T)
				for(int j=0;j<g[x].size();j++){
					tp++;	
					q[tp]=g[x][j];
				}
			c[x]=T;
		}
	}
}
int main(){
	cin>>T;
	while(T){
		
		read(n),read(m);
		b=1,l=0;
		for(int i=1;i<=m;i++){
			read(u),read(v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
        
		Coloring_Vertices();
        
		for(int i=1;i<=n;i++){
			if(c[i]!=T){	
				b=0;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(b){
			cout<<"YES"<<endl<<l<<endl;
           		sort(ans+1,ans+1+l);
			for(int i=1;i<=l;i++)  
				cout<<ans[i]<<' ';
			cout<<endl;
		}
		for(int i=1;i<=n;i++) g[i].clear();
		T--;
	}
	return 0;
}