#include<bits/stdc++.h>
using namespace std;
long long n,l,c[35],i,j,ans=1ll<<62,s,ss;
int main(){
	cin>>n>>l;
	for(i=1;i<=n;++i)cin>>c[i];for(;i<=30;++i)c[i]=1ll<<62;
	for(i=1;i<30;++i)
		for(j=i+1;j<=30;++j)c[j]=std::min(c[j],c[i]<<(j-i));
	for(i=29;i>=0;--i){
		if(ss+(1<<i)>=l)for(j=i;j<30;++j)ans=min(ans,s+c[j+1]);
		if(ss+(1<<i+1)>=l)for(j=i;j<30;++j)ans=min(ans,s+c[j+1]*2);
		if(l>>i&1)s+=c[i+1],ss+=1<<i;
	}
	ans=min(ans,s);cout<<ans<<endl;
	return 0;
}