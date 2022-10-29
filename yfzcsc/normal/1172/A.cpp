#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	int pos=n+1;
	int flg=0;
	for(int i=1;i<=n;++i)if(b[i])flg=1;
	if(flg==0){
		printf("%d\n",n);
		return 0;
	}
	for(int i=1;i<=n;++i)if(b[i]==1)pos=i;
	int ans=1e9;
	if(1){
		int flg=1;
		for(int i=pos;i<=n;++i)flg&=b[i]==i-pos+1;
		if(flg==1){
			set<int> st;
			for(int i=1;i<=n;++i)if(a[i])st.insert(a[i]);
			
			for(int i=1;i<pos&&flg;++i){
				if(!st.count(b[n]+i))flg=0;
				else st.erase(b[n]+i);
				if(b[i])st.insert(b[i]);
			}	
		}
		if(flg==1){
			printf("%d",pos-1);
			return 0; 
//			ans=min(ans,pos-1);
		}
	}
	int nans=0;
	for(int i=1;i<=n;++i)if(b[i])nans=max(nans,i+1-b[i]+n);
	ans=min(ans,nans);
	printf("%d",ans);
}