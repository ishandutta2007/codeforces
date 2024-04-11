#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
int T,n,m,a,b,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>n;
		ans=0;
		F(i,0,30){
			if(a&(1<<i)){
				if(b&(1<<i)){
					if(n%3!=2)ans+=(1<<i);						
				}
				else if(n%3!=1)ans+=(1<<i);
			}
			else if((b&(1<<i))&&n%3!=0)ans+=(1<<i);
		}
		cout<<ans<<endl;
	}
    return 0;
}