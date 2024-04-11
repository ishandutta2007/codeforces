#include<bits/stdc++.h>
using namespace std;
int n,m,lcp,la,lala,c; 
long long ans;
int main(){
    cin>>n>>m;ans=n*(m-1);
    for(;!isalpha(la=getchar()););
    for(int i=1;i<n;i++){
    	c=getchar();
    	if(c==lala)lcp++;else lcp=0;
    	if(c!=la)ans+=(m-1)*n-lcp-1;
    	lala=la;la=c;
    }
    cout<<ans;
}