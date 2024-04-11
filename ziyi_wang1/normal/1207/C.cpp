#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define IN inline ll
typedef long long ll;
char c[202000];
ll n,m,T,a,b,f[202000][2][2];
IN min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>a>>b;
		scanf("%s",c+1);
		memset(f,127,sizeof(f));
		f[1][0][0]=a+b+b;
		f[1][0][1]=a+a+b+b+b;
		F(i,2,n){
			if(c[i]=='1')f[i][1][1]=min(f[i-1][0][1],f[i-1][1][1])+a+b+b;
			else{
				f[i][1][1]=min(f[i-1][0][1],f[i-1][1][1])+a+b+b;
				f[i][1][0]=min(f[i-1][0][1],f[i-1][1][1])+a+a+b;
				f[i][0][1]=min(f[i-1][0][0],f[i-1][1][0])+a+a+b+b;
				f[i][0][0]=min(f[i-1][0][0],f[i-1][1][0])+a+b;
			}
		}
		cout<<min(f[n][0][0],f[n][1][0])<<endl;
	}
    return 0;
}