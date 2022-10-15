#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
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
int n,m,T,sn,X,Y,maxi=-1,Maxi,k,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;sn=0;maxi=-1;Maxi=-1;
		F(i,1,n){
			cin>>X>>Y;
			if(X>=m){
				sn=2;
			}
			if(sn==2)continue;
			if(X>Y)sn=1;
			maxi=max(maxi,X);
			Maxi=max(Maxi,X-Y);
		}
		if(sn==2){
			cout<<"1"<<endl;
			continue;
		}
		if(!sn){
			cout<<"-1"<<endl;
			continue;
		}
		m-=maxi;
		if(m%Maxi==0)ans=(m/Maxi)+1;
		else {
			ans=(m/Maxi)+2;
		}
		cout<<ans<<endl;
	}
    return 0;
}