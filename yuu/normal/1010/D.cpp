#include <bits/stdc++.h>
using namespace std;
int n;
int type[1000001];
int in0[1000001];
int in1[1000001];
bool res[1000001];
bool ans[1000001];
void dfs(int u, bool res0, bool res1){
	if(type[u]==0){
		if(in0[u]) ans[u]=res0;
		else ans[u]=res1;
	}
	else if(type[u]==1){
		dfs(in0[u], res1, res0);
	}
	else if(type[u]==2){//and
		if(res[in1[u]]==0) dfs(in0[u], res0, res0);
		else							 dfs(in0[u], res0, res1);
		if(res[in0[u]]==0) dfs(in1[u], res0, res0);
		else               dfs(in1[u], res0, res1);
	}
	else if(type[u]==3){
		if(res[in1[u]]==1) dfs(in0[u], res1, res1);
		else							 dfs(in0[u], res0, res1);
		if(res[in0[u]]==1) dfs(in1[u], res1, res1);
		else               dfs(in1[u], res0, res1);
	}
	else if(type[u]==4){
		if(res[in1[u]]==1) dfs(in0[u], res1, res0);
		else							 dfs(in0[u], res0, res1);
		if(res[in0[u]]==1) dfs(in1[u], res1, res0);
		else							 dfs(in1[u], res0, res1);
	}
	else{
		exit(-1);
	}
}
void cal(int u){
	if(type[u]==0){
		res[u]=in0[u];
	}
	else if(type[u]==1){
		cal(in0[u]);
		res[u]=!res[in0[u]];
	}
	else{
		cal(in0[u]);
		cal(in1[u]);
		if(type[u]==2){
			res[u]=res[in0[u]]&&res[in1[u]];
		}
		else if(type[u]==3){
			res[u]=res[in0[u]]||res[in1[u]];
		}
		else{
			res[u]=res[in0[u]]^res[in1[u]];
		}
	}
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		string s;
		cin>>s>>in0[i];
		if(s=="IN")	type[i]=0;
		else if(s=="NOT") type[i]=1;
		else{
			cin>>in1[i];
			if(s=="AND") type[i]=2;
			else if(s=="OR") type[i]=3;
			else type[i]=4;
		}
	}
	cal(1);
	dfs(1, 0, 1);
	for(int i=1; i<=n; i++) if(type[i]==0) cout<<ans[i];
}