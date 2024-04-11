#include<bits/stdc++.h>
using namespace std;

int a[300010],l[300010],r[300010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			l[i]=n+1;r[i]=0;
		}
		for(int i=1;i<=n;i++)
			l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
		for(int i=1;i<=n;i++)
			ans+=r[i]!=0;
		int cnt=0,m=0,pre=0;
		for(int i=1;i<=n;i++)
			if(r[i]!=0){
				if(l[i]>r[pre])
					cnt++;
				else
					cnt=1;
				pre=i;
				m=max(cnt,m);
			}
		 cout<<ans-m<<'\n';
	}
}