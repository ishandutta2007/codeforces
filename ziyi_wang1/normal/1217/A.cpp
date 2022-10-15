#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,m,T,w,k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>w;
		k=(w+m-n)>>1;
		k++;
		k=max(k,0);
		cout<<max(w-k+1,0)<<endl;
	}
    return 0;
}