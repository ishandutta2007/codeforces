#include<iostream>
using namespace std;
#define int long long
int p[20],cnt,a[1000010], b[1000010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i],sum+=a[i];
	if(sum==1){cout<<-1<<endl;return 0;}
	for(int i=2;i<=1e6;i++){
		if(sum%i==0){
			p[cnt++]=i;
			while(sum%i==0)sum/=i;
		}
	}if(sum>1)p[cnt++]=sum;
	int ans=1e18;
	for(int k=0;k<cnt;k++){
		for(int i=1;i<=n;i++)a[i]=b[i]%p[k];
		int tmp=0,sum=0;;
		for(int i=1;i<=n;i++)sum=(sum+a[i])%p[k],tmp+=min(sum,p[k]-sum);
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
}