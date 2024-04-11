#include<bits/stdc++.h>
const int N=2e5+5;
int n,i,j,a,x,y;
std::vector<int>ve[N];
bool b[N];
int main(){
	scanf("%d",&n);
	for(int nn=n;nn--;){
		scanf("%d",&a);
		for(i=2;i*i<=a;++i)if(a%i==0){
			y=1;
			for(;a%i==0;a/=i,y*=i);
			ve[i].push_back(y);
		}
		if(a>1)ve[a].push_back(a);
	}
	for(i=2;i<N;++i)if(!b[i])for(j=2;i*j<N;++j)b[i*j]=1;
	long long ans=1;
	for(i=2;i<N;++i)if(!b[i] && ve[i].size()>=n-1){
		sort(ve[i].begin(),ve[i].end());
		ans*=ve[i].size()==n?ve[i][1]:ve[i][0];
	}
	printf("%lld\n",ans);
}