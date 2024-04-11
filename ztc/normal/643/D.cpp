#include<stdio.h>
#include<set>
std::multiset<long long>M[100002],M1;
long long c[100002],v[100002];
int f[100002],d[100002],n,m;
void ins(int i){
	if(!M[i].empty())M1.insert(*M[i].begin()+c[i]/(d[i]+1));
	if(M[i].size()>=2){
		auto pt=M[i].end();pt--;
		M1.insert(*pt+c[i]/(d[i]+1));
	}
}
void del(int i,long long v){
	auto pt=M[i].find(v);M[i].erase(pt);
}
void del(int i){
	if(!M[i].empty()){
		auto pt=M1.find(*M[i].begin()+c[i]/(d[i]+1));
		M1.erase(pt);
	}if(M[i].size()>=2){
		auto pt=M[i].end();pt--;
		pt=M1.find(*pt+c[i]/(d[i]+1));M1.erase(pt);
	}
}
int calc(int p[],int n){
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--)if(p[j]<p[j-1])p[j]^=p[j-1]^=p[j]^=p[j-1];
	}int cnt=0;
	for(int i=1;i<n;i++)if(p[i]!=p[cnt])p[++cnt]=p[i];
	return ++cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%d",&f[i]),d[i]++,d[f[i]]++;
	for(int i=1;i<=n;i++)v[i]+=c[i]-(c[i]/(d[i]+1))*d[i],v[f[i]]+=c[i]/(d[i]+1);
	for(int i=1;i<=n;i++)M[f[i]].insert(v[i]);
	for(int i=1;i<=n;i++)ins(i);
	while(m--){
		int id,x,y;
		scanf("%d",&id);
		if(id==3){
			auto pt=M1.end();pt--;
			printf("%lld %lld\n",*M1.begin(),*pt);
		}else if(id==2){
			scanf("%d",&x);
			printf("%lld\n",v[x]+c[f[x]]/(d[f[x]]+1));
		}else{
			scanf("%d%d",&x,&y);
			int p[6]={f[x],f[f[x]],f[f[f[x]]],y,f[y],f[f[y]]},cnt=calc(p,6);
			int q[5]={x,f[x],f[f[x]],y,f[y]},cnt2=calc(q,5);
			for(int i=0;i<cnt;i++)del(p[i]);
			for(int i=0;i<cnt2;i++)del(f[q[i]],v[q[i]]);
			v[f[f[x]]]-=c[f[x]]/(d[f[x]]+1);v[f[y]]-=c[y]/(d[y]+1);v[f[x]]-=c[x]/(d[x]+1);
			v[f[x]]-=c[f[x]]-(c[f[x]]/(d[f[x]]+1))*d[f[x]];v[y]-=c[y]-(c[y]/(d[y]+1))*d[y];
			d[f[x]]--;d[y]++;
			v[f[x]]+=c[f[x]]-(c[f[x]]/(d[f[x]]+1))*d[f[x]];v[y]+=c[y]-(c[y]/(d[y]+1))*d[y];
			v[f[f[x]]]+=c[f[x]]/(d[f[x]]+1);v[f[y]]+=c[y]/(d[y]+1);f[x]=y;v[f[x]]+=c[x]/(d[x]+1);
			for(int i=0;i<cnt2;i++)M[f[q[i]]].insert(v[q[i]]);
			for(int i=0;i<cnt;i++)ins(p[i]);
		}
	}
}