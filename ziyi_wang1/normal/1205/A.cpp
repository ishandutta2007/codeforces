#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
ll sn;
int n,m,ans[202000],p,las[2];
int main(){
	cin>>n;n<<=1;//cout<<n<<endl;
	sn=1ll*n*1ll*(n*1ll+1ll);
	sn>>=1;
	if(!(sn&1)){
		cout<<"NO";
		return 0;
	}
	n>>=1;
	
	ans[1]=1;p=1;m=0;las[0]=2;las[1]=1;
	F(i,2,n<<1){
		//cout<<i<<" "<<las[p]+p*n<<endl;
		ans[las[p]+p*n]=i;
		las[p]++;
		m++;
		if(m==2){
			m=0;
			p^=1;
		}	
	}
	//cout<<n<<endl;
	cout<<"YES"<<endl;
	F(i,1,n<<1){
		cout<<ans[i]<<" ";
	}
    return 0;
}