#include <iostream>
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,ans;cin>>n;ans=n-1;
		for(int i=1;i*i<=n;i++)ans=min(ans,n/i+i+(n%i!=0)-2);
		cout<<ans<<endl;
	}return 0;
}