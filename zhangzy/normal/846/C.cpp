#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[5555]={0},l[5555],r[5555],ans;

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	memset(l,-62,sizeof l);
	ans=l[0];l[0]=0;
	for (int i=1;i<=n;i++){
		l[i]=max(l[i-1],a[i]);
	}
	memset(r,-62,sizeof r);
	for (int i=n;i>=0;i--){
		r[i]=max(r[i+1],a[i]);
	}
	for (int i=0;i<=n;i++){
		ans=max(ans,2*l[i]-2*a[i]+2*r[i]-a[n]);
	}
	for (int i=0;i<=n;i++){
		if (ans==2*l[i]-2*a[i]+2*r[i]-a[n]){
			for (int j=0;j<=i;j++){
				if (a[j]==l[i]){
					printf("%d",j);
					break;
				}
			}
			printf(" %d ",i);
			for (int j=i;j<=n;j++){
				if (a[j]==r[i]){
					printf("%d",j);
					break;
				}
			}
			return 0;
		}
	}
}