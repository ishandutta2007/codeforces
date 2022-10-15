#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
int n,m;
int main(){
	cin>>n;
	F(i,1,n){
		F(j,1,n){
			if((i&1)^(j&1)){
				cout<<"B";
			}
			else cout<<"W";
		}
		cout<<endl;
	}
    return 0;
}