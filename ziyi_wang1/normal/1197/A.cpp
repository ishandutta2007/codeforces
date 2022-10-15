#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
ll n,m,T,a[101000];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		F(i,1,n){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		printf("%d\n",min(n-2,a[n-1]-1));
	}
    return 0;
}