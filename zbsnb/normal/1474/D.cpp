#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int pre[1000010];
int suf[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(pre[i-1]==-1) pre[i]=-1;
			else{
				pre[i]=a[i]-pre[i-1];
				if(pre[i]<0) pre[i]=-1;
			}
		}
		suf[n+1]=a[n+1]=0;
		for(int i=n;i>=1;i--){
			if(suf[i+1]==-1) suf[i]=-1;
			else{
				suf[i]=a[i]-suf[i+1];
				if(suf[i]<0) suf[i]=-1;
			}
		}
		int flg=0;
		for(int i=1;i<=n-1;i++){
			int j=i+1;
			if(pre[i-1]==-1||suf[j+1]==-1) continue;
			if(a[i]>=pre[i-1]&&a[j]>=suf[j+1]&&a[i]-pre[i-1]==a[j]-suf[j+1]
			|| a[j]>=pre[i-1]&&a[i]>=suf[j+1]&&a[j]-pre[i-1]==a[i]-suf[j+1]){
				flg=1;
				break;
			}
		}
		cout<<(flg?"YES":"NO")<<"\n";
	}
}