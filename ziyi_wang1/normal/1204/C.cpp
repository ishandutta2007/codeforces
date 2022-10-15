#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
char c;
int n,m,W,a[110][110],b[1010000],len,ans[1010000],sum;
int main(){
	cin>>n;
	memset(a,63,sizeof(a));
	F(i,1,n){
		F(j,1,n){
			cin>>c;
			if(c=='1')a[i][j]=1;
		}
	}
	F(i,1,n){
		a[i][i]=0;
	}
	F(k,1,n){
		F(i,1,n){
			F(j,1,n){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	cin>>m;
	F(i,1,m){
		cin>>b[i];
	}
	len=1;ans[1]=b[1];sum=0;
	F(i,2,m){
		sum++;
		if(i==2)continue;
		if(a[ans[len]][b[i]]<sum){
			ans[++len]=b[i-1];
			sum=1;
		}
	}
	ans[++len]=b[m];
	printf("%d\n",len);
	F(i,1,len){
		printf("%d ",ans[i]);
	}
    return 0;
}