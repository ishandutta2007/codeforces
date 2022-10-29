#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
typedef pair<int,int> par;
struct data{
	int x,val,id;
	int operator<(const data& d)const{
		return val<d.val;
	}
}p[maxn];
int n,T;
bool chk(int len){
	int ans=0,cnt=1;
	for(int i=1;i<=n&&ans<=T&&cnt<=len;++i)if(p[i].x>=len)
		ans+=p[i].val,cnt++;
	return cnt==len+1&&ans<=T;
} 
void print(int len){
	printf("%d\n%d\n",len,len);
	int cnt=1;
	for(int i=1;i<=n&&cnt<=len;++i)if(p[i].x>=len)
		cnt++,printf("%d ",p[i].id);
}
int main(){
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].x,&p[i].val),p[i].id=i;
	int l=1,r=n,ans=0;
	sort(p+1,p+n+1);
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	print(ans);
}