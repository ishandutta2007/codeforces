#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7,mod=1e9+7;
const int P[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n,cnt,s[19];
inline void insert(int x){
	for(int i=18;~i;i--)
		if(x>>i&1){
			if(s[i])x^=s[i];
			else{cnt++,s[i]=x;break;}
		}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=0;
		for(int j=18;~j;j--)
			while(x%P[j]==0)y^=1<<j,x/=P[j];
		insert(y);
	}
	int ans=1;
	for(int i=1;i<=n-cnt;i++)ans=ans*2%mod;
	return cout<<ans-1,0;
}