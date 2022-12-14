#include<bits/stdc++.h>
using namespace std;

int a[200001];
int b[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			b[i]=0;
		int m;
		cin>>m;
		for(int i=1,p,s;i<=m;i++){
			cin>>p>>s;
			b[s]=max(b[s],p);
		}
		for(int i=n-1;i>=0;i--)
			b[i]=max(b[i],b[i+1]);
		int ans=0;
		int d=1,now=0,pre=0;
		while(true){
			if(d==n+1){
				ans++;
				break;
			}
			now=max(now,a[d]);
			if(now<=b[d-pre]){
				d++;
			}
			else{
				if(d==pre+1){
					ans=-1;
					break;
				}
				else{
					ans++;
					pre=d-1;
					now=a[d];
				}
			}

		}
		cout<<ans<<'\n';
	}
}