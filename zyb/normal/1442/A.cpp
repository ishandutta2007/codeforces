#include<bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int a[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int nowmin=1e7;
		for(int i=1;i<=n;i++){
			if(i>1&&a[i]-min(nowmin,a[i])<a[i-1]){
				nowmin=min(nowmin,a[i]-a[i-1]);
				if(nowmin<=0)break;
				a[i]-=nowmin;
			}
			else {
				nowmin=min(nowmin,a[i]);
				a[i]-=nowmin;
			}
		}
		nowmin=1e7;
		for(int i=n;i;i--){
			nowmin=min(nowmin,a[i]);
			a[i]-=nowmin;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
			if(a[i]>0){
				flag=0;
			}
		if(flag)puts("YES");
		else puts("NO");
	}
}