#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
int n,m,ans[1010][1010];
int main(){
	cin>>n;m=0;
	F(i,1,n>>1){
		F(j,1,n>>1){
			ans[i][j]=(m<<2)+1;
			ans[i][j+(n>>1)]=(m<<2)+2;
			ans[i+(n>>1)][j]=(m<<2)+3;
			ans[i+(n>>1)][j+(n>>1)]=m<<2;
			m++;
		}	
	}
	F(i,1,n){
		F(j,1,n){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}