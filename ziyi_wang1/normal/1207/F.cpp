#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
int n,m,ans[710][710],a[505000],sit,x,y,sum;
int main(){
	cin>>n;
	F(i,1,n){
		cin>>sit>>x>>y;
		if(sit==1){
			a[x]+=y;
			F(i,1,707){
				ans[i][x%i]+=y;
			}
		}
		else {
			if(x>707){
				sum=0;
				for(re j=y;j<=500000;j+=x){
					sum+=a[j];
				}
				printf("%d\n",sum);
			}
			else printf("%d\n",ans[x][y]);
		}
	}
    return 0;
}