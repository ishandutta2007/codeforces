#include<iostream>
using namespace std;
typedef long long ll;
ll m,b,i,s,ans,j,x,y;
int main(){
	cin>>m>>b;
	for(i=b;i>=0;--i){
		x=(i+j*2ll)*(i+1)>>1ll;
		y=(i+1)*i>>1ll;
		s=(x+y)*(j+1)>>1ll;
		if(s>ans)ans=s;
		j+=m;
	}
	cout<<ans<<endl;
	return 0;
}