#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fr first
#define sc second

int n,k;
ll a[2][100010];
int l,r;
int t,t_;

bool ok[100010];

int main(){
	cin>>n>>k;
	/*for(int i=0;i<n;i++){
		a[0][i]=k;
	}
	l=n; r=0;
	for(int i=0;i<n;i++)ok[i]=false;*/
	
	int ph=0;
	int can=0;
	int l,r;
	for(int loop=0;loop<1000;loop++){
		if(loop==0){
			cout<<"? 1"<<endl;
			fflush(stdout);
			int ret;
			cin>>ret;
			continue;
		}
		if(ph==0){
			int x=min(loop,n/2-1);
			if(can==0)cout<<"? "<<n<<endl;
			else cout<<"? "<<can<<endl;
			fflush(stdout);
			int ret;
			cin>>ret;
			if(ret<k){
				ph=1;
				l=can+1; r=min(n,can+x);
			}
			else {
				can+=x;
			}
		}
		else {
			cout<<"? "<<l<<endl;
			fflush(stdout);
			int ret;
			cin>>ret;
			if(ret==k){
				cout<<"! "<<l<<endl;
				fflush(stdout);
				return 0;
			}
			else l++;
		}
		/*for(int i=0;i<n;i++){
			cout<<a[0][i]<<" ";
		}
		cout<<endl;
		if(loop==10)break;*/
		/*a[1][0]=a[0][1]-a[0][1]/2+a[0][n-1]/2;
		a[1][1]=a[0][2]-a[0][2]/2+a[0][0];
		a[1][n-1]=a[0][n-2]/2;
		for(int i=2;i<=min(r+1,n-2);i++){
			a[1][i]=a[0][i-1]-a[0][i-1]/2+a[0][i+1]/2;
		}
		for(int i=max(l-1,2);i<=n-2;i++){
			a[1][i]=a[0][i-1]-a[0][i-1]/2+a[0][i+1]/2;
		}
		a[0][0]=a[1][0];
		a[0][1]=a[1][1];
		a[0][n-1]=a[1][n-1];
		for(int i=2;i<=min(r+1,n-2);i++)a[0][i]=a[1][i];
		for(int i=max(l-1,2);i<=n-2;i++)a[0][i]=a[1][i];
		if(r+1<n&&a[1][r+1]!=k)r++;
		if(l-1>=0&&a[1][l-1]!=k)l--;
		cout<<n-l<<" "<<r<<endl;*/
	}
}