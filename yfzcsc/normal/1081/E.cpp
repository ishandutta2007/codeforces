#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>G[201000];
int n;
ll xi[101000];
int main(){
	scanf("%d",&n);
	int M=2e5+10;
	for(int i=1;i<=M;i++)
		for(int j=i;j<=M;j+=i)
			G[j].push_back(i);
	for(int i=2;i<=n;i+=2)
		scanf("%lld",&xi[i]);
	ll mn=0;
	for(int i=2;i<=n;i+=2){
		ll can=1e18,flg=0,t1;
		for(auto c:G[xi[i]]){
			ll A=c,B=xi[i]/c;
			if(B<A)continue;
			if((B-A)%2!=0)continue;
			ll T1=(B-A)/2,T2=(B+A)/2;
			if(T1>mn&&can>T2){
				can=min(can,T2);
				t1=T1;
				flg=1;
			}
		}
		
		if(!flg){
			puts("No");
			return 0;
		} else {
			xi[i-1]=t1*t1-mn*mn,mn=can;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%lld ",xi[i]);
}