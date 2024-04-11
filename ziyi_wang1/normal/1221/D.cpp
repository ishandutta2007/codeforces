#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
I read(ll &res){
    re g=1;register char ch=getchar();res=0;
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
const ll INF=1e18+7;
ll n,m,T,a[303000],b[303000],c[303000],f[303000][3];
IN Min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	cin>>T;
	while(T--)
	{
		cin>>n;
		a[0]=0;
		F(i,1,n)
		{
			read(a[i]);read(b[i]);
		}
		F(i,1,n)
		{
			c[i]=a[i]-a[i-1];
		}
		f[1][0]=0ll;f[1][1]=b[1];f[1][2]=b[1]+b[1];
		F(i,2,n)
		{
			f[i][0]=f[i][1]=f[i][2]=INF;
			if(c[i])f[i][0]=Min(f[i][0],f[i-1][0]);
			if(c[i]!=1)f[i][0]=Min(f[i][0],f[i-1][1]);
			if(c[i]!=2)f[i][0]=Min(f[i][0],f[i-1][2]);
			if(c[i]!=-1)f[i][1]=Min(f[i][1],f[i-1][0]+b[i]);
			if(c[i])f[i][1]=Min(f[i][1],f[i-1][1]+b[i]);
			if(c[i]!=1)f[i][1]=Min(f[i][1],f[i-1][2]+b[i]);
			if(c[i]!=-2)f[i][2]=Min(f[i][2],f[i-1][0]+b[i]+b[i]);
			if(c[i]!=-1)f[i][2]=Min(f[i][2],f[i-1][1]+b[i]+b[i]);
			if(c[i])f[i][2]=Min(f[i][2],f[i-1][2]+b[i]+b[i]);
			//cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<endl;
		}
		cout<<Min(Min(f[n][0],f[n][1]),f[n][2])<<endl;
	}
    return 0;
}