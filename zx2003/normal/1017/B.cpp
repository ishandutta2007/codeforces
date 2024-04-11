#include<bits/stdc++.h>
const int N=100005;
long long ans;
int cnt[2][2],n,i;
char a[N],b[N];
int main(){
	scanf("%d%s%s",&n,a+1,b+1);cnt[a[1]-'0'][b[1]-'0']=1;
	for(i=2;i<=n;++i){
		if(b[i]=='0'){
			if(a[i]=='0'){
				ans+=cnt[1][1]+cnt[1][0];
			}else{
				ans+=cnt[0][0]+cnt[0][1];
			}
		}else{
			if(a[i]=='0'){
				ans+=cnt[1][0];
			}else{
				ans+=cnt[0][0];
			}
		}
		++cnt[a[i]-48][b[i]-48];
	}
	std::cout<<ans<<'\n';
	return 0;
}