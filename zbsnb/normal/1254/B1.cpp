#include<iostream>
using namespace std;
#define ll long long
#define int ll

int p[20],cnt;
int a[1000010];
int b[1000010];

ll s1[1000010];
ll s2[1000010];

ll ss1[1000010];
ll ss2[1000010];

ll calcu(int l,int  r){
	// for(int i=l;i<=r;i++)cout<<a[i]<<" ";cout<<"@"<<endl;

	s1[l-1]=0;
	for(int i=l;i<=r;i++){
		s1[i]=s1[i-1]+a[i];
	}

	s2[r+1]=0;
	for(int i=r;i>=l;i--){
		s2[i]=s2[i+1]+a[i];
	}
	
	ss1[l-1]=0;
	for(int i=l;i<=r;i++){
		ss1[i]=ss1[i-1]+(s1[i]-s1[l-1]);
	}

	ss2[r+1]=0;
	for(int i=r;i>=l;i--){
		ss2[i]=ss2[i+1]+(s2[i]-s2[r+1]);
	}

	// for(int i=l;i<=r;i++){
	// 	// cout<<s1[i]<<" "<<s2[i]<<" "<<ss1[i]<<" "<<ss2[i]<<endl;
	// }

	ll ret=1e18;
	for(int k=l;k<=r;k++){
		ret=min(ret,ss1[k-1]+ss2[k+1]);
	}
	// cout<<"ret"<<l<<" "<<r<<" "<<ret<<endl;
	return ret;
}

signed main(){
	int n;cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		sum+=a[i];
	}

	if(sum==1){
		cout<<-1<<endl;
		return 0;
	}

	for(int i=2;i<=1e6;i++){
		if(sum%i==0){
			p[cnt++]=i;
			while(sum%i==0)sum/=i;
		}
	}
	if(sum>1){
		p[cnt++]=sum;
	}

	int aa=1e18;

	for(int k=0;k<cnt;k++){
		for(int i=1;i<=n;i++){
			a[i]=b[i]%p[k];
		}
		//cout<<k<<"?"<<p[k]<<endl;

		ll sum1=0;
		ll ans=0;
		int pre=1;

		for(int i=1;i<=n;i++){
			
			sum1+=a[i];
			if(sum1>=p[k]){
				
				// cout<<"i"<<i<<sum1<<endl;

				int tmp=sum1-p[k];
				a[i]-=tmp;

				// cout<<tmp<<" "<<a[i]<<endl;
				ans+=calcu(pre,i);
				
				a[i]=tmp;
				pre=i;
				sum1=0;
			}
		}
		// cout<<k<<"?"<<p[k]<<"!"<<ans<<endl;
		aa=min(ans,aa);
	}
	cout<<aa<<endl;
}