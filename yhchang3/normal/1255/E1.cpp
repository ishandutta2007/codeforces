#include<bits/stdc++.h>
using namespace std;

int a[1000001];
int b[1000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long int sum=0;
	vector<long long int> p;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	if(sum==1){
		cout<<-1<<endl;
		return 0;
	}
	long long int ans=0;
	for(int i=2;i<=1000000;i++)
		if(sum%i==0){
			while(sum%i==0)
				sum/=i;
			p.emplace_back(i);
		}
	if(sum!=1)
		p.emplace_back(sum);
	bool odd=false;
	int pre=0;
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(odd)
				ans+=i-pre;
			odd^=(a[i]&1);
			pre=i;
		}
	}
	if(odd)
		ans=1e18;
	for(long long int it:p){
		if(it==2)	continue;
		long long int h=it/2,l=0,r=0,tans=0,lcnt=0,mcnt=0,rcnt=0;
		int now=1;
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		while(now!=n+1){
			if(lcnt==0)
				b[now]%=it;
			if(b[now]==0){
				now++;
				continue;
			}
			if(lcnt==h){
				if(mcnt==0){
					b[now]--;
					mcnt=1;
					continue;
				}
				else {
					long long int cnt=min(h-rcnt,(long long int) b[now]);
					r+=cnt*now;
					b[now]-=cnt;
					rcnt+=cnt;
					if(rcnt==h){
						tans+=r-l;
						l=r=lcnt=rcnt=mcnt=0;
					}
				}
			}
			else{
				long long int cnt=min(h-lcnt,(long long int) b[now]);
				l+=cnt*now;
				b[now]-=cnt;
				lcnt+=cnt;
			}
		}
		ans=min(ans,tans);
	}
	cout<<ans<<endl;
}