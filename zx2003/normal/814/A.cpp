#include<iostream> 
#include<cstdio>
using namespace std;
int x,n,i,a[210],b[210],k,l;
int main(){
	cin>>n>>k;
	if(k>1)return puts("Yes"),0;
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]){
			if(a[i]<=l)return puts("Yes"),0;
			l=a[i];
		}else x=i;
	}
	for(i=1;i<=k;++i)cin>>b[i];
	a[n+1]=300;
	if(a[x-1]<b[1] && b[1]<a[x+1])puts("No");
		else puts("Yes");
	return 0;
}