#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n;
    m=1;
    while(1){
		if(m==n||m+1==n){
			cout<<"1";
			return 0;
		}
		if(!(m&1))m=(m<<1)|1;
		else m=(m+1)<<1;
		if(m>n)break;
    }
    cout<<"0";
    return 0;
}