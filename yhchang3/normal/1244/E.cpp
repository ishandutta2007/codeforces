#include<bits/stdc++.h>
using namespace std;


int a[100010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	long long int ans=a[n]-a[1];
	while(true){
		if((l>k&&(n-r+1)>k)||l==r)	break;
		if(l<(n-r+1)){
			int cnt=a[l+1]-a[l];
			if((long long int) l*cnt<=k){
				ans-=cnt;
				k-=(long long int) l*cnt;
				l++;
			}
			else{
				ans-=k/l;
				break;
			}
		}
		else{
			int cnt=a[r]-a[r-1];
			if((long long int) (n-r+1)*cnt<=k){
				ans-=cnt;
				k-=(long long int) (n-r+1)*cnt;
				r--;
			}
			else{
				ans-=k/(n-r+1);
				break;
			}
		}
	}
	cout<<ans<<endl;
}