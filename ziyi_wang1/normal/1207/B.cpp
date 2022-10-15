#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
int n,m,a[60][60],b[60][60],ans[5000][2],tot,sn=0;
int main(){
	cin>>n>>m;
	F(i,1,n){
		F(j,1,m){
			cin>>a[i][j];
		}
	}
	tot=0;
	F(i,1,n-1){
		F(j,1,m-1){
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
				tot++;
				ans[tot][0]=i;ans[tot][1]=j;
			}
		}
	}
	F(i,1,n){
		F(j,1,m){
			if(a[i][j]!=b[i][j]){
				cout<<"-1";
				return 0;
			}
		}
	}
	cout<<tot<<endl;
	F(i,1,tot){
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
    return 0;
}