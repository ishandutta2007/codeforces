#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define I inline void
int n,m,ans[110000],tot,sum,v[110000];
I D_1(int x,int w){
	if(x==15){
		if(tot<100)ans[++tot]=w+5461,v[w+5461]=1;
		return;
	}
	D_1(x+2,w+(1<<x));
	D_1(x+2,w);
}
I D_2(int x,int w){
	if(x==14){
		if(!v[w+10922])ans[++tot]=w+10922;
		return;
	}
	D_2(x+2,w+(1<<x));
	D_2(x+2,w);
}
int main(){
	tot=0;
	D_1(1,0);
	cout<<"? ";
	F(i,1,99){
		cout<<ans[i]<<" ";
	}
	cout<<ans[100]<<endl;
	fflush(stdout);
	cin>>n;
	tot=0;
	D_2(0,0);
	cout<<"? ";
	F(i,1,99){
		cout<<ans[i]<<" ";
	}
	cout<<ans[100]<<endl;
	fflush(stdout);
	cin>>m;
	F(i,0,13){
		if(i&1){
			if(!(m&(1<<i)))sum+=(1<<i);
		}
		else if(!(n&(1<<i)))sum+=(1<<i);
	}
	cout<<"! "<<sum<<endl;
	fflush(stdout);
    return 0;
}