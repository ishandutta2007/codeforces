#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
int n,m,a[101000],b[101000];
int main(){
	cin>>n;
	F(i,1,n){
		cin>>a[i];
		if(a[i]<0){
			b[i]=-1;
			a[i]=-a[i];
		}
		else b[i]=1;
		if(a[i]&1)m++;
	}
	m>>=1;
	F(i,1,n){
		if((a[i]&1)&&m){
			if(b[i]==1)a[i]++;
			else a[i]--;
			m--;
		}
		if(b[i]==1)a[i]>>=1;
		else a[i]=(a[i]+1)>>1;
		a[i]*=b[i];
	}
	F(i,1,n){
		cout<<a[i]<<endl;
	}
    return 0;
}