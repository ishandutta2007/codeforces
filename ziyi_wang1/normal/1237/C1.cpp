#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
int n,m,x[50500],y[50500],z[50500],v[50500],l,r,R;
int main(){
	cin>>n;
	F(i,1,n){
		cin>>x[i]>>y[i]>>z[i];
	}
	l=1;
	F(i,1,n>>1){
		while(v[l])l++;
		r=l+1;
		while(v[r])r++;
		R=r;
		F(j,R+1,n){
			if(v[j])continue;
			if(x[j]>=min(x[l],x[r])&&x[j]<=max(x[l],x[r])&&y[j]>=min(y[l],y[r])&&y[j]<=max(y[l],y[r])&&z[j]>=min(z[l],z[r])&&z[j]<=max(z[l],z[r])){
				r=j;
			}
		}
		cout<<l<<" "<<r<<endl;
		v[l]=v[r]=1;
	}
	
    return 0;
}