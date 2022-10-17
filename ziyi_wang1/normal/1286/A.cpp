#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define C(x,y) memset(x,y,sizeof(x))
int n,m,a[110],v[110],s[110],f[110][110][2],A,B;
int main(){
	cin>>n;
	F(i,1,n){
		cin>>a[i];s[i]=s[i-1];
		if(!a[i])a[i]=-1,s[i]++;
		else v[a[i]]=1,a[i]&=1;
	}
	F(i,1,n){
		if(!v[i]){
			if(i&1)B++;else A++;
		}
	}
//	F(i,1,n)cout<<a[i]<<" ";
	//cout<<endl;
	C(f,63);
	f[0][0][0]=0;f[0][0][1]=0;
	if(a[1]!=-1){
		F(j,0,min(s[1],A))if(s[1]-j<=B)f[1][j][a[1]]=min(f[0][j][0],f[0][j][1]);
	}
	else{
		F(j,0,min(s[1],A)){
			if(s[1]-j>B)continue;
			if(j)f[1][j][0]=min(f[0][j-1][0],f[0][j-1][1]);
			f[1][j][1]=min(f[0][j][0],f[0][j][1]);
		}
	}
	F(i,2,n){
		if(a[i]!=-1){
			F(j,0,min(s[i],A))if(s[i]-j<=B)f[i][j][a[i]]=min(f[i-1][j][0]+a[i],f[i-1][j][1]+(a[i]^1));
			continue;
		}
		F(j,0,min(s[i],A)){
			if(s[i]-j>B)continue;
			if(j)f[i][j][0]=min(f[i-1][j-1][0],f[i-1][j-1][1]+1);
			f[i][j][1]=min(f[i-1][j][0]+1,f[i-1][j][1]);
		}
	}
	//F(i,1,n)F(j,0,min(s[i],A))cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<endl;
	cout<<min(f[n][A][0],f[n][A][1]);
	return 0;
}