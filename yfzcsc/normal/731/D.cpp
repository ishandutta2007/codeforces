#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int seg[1000111],c,n;
vector<int>a[500111];
int main(){
//	freopen("d.txt","r",stdin);
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i){
		int x;scanf("%d",&x);
		for(int j=1;j<=x;++j){
			int t;scanf("%d",&t);
			a[i].push_back(t);
		}
	}
	for(int i=1;i<n;++i){
		int pos=0;
		for(;pos<a[i].size()&&pos<a[i+1].size();pos++)
			if(a[i][pos]!=a[i+1][pos])break;
		if(pos==min(a[i].size(),a[i+1].size())){
			if(a[i].size()>a[i+1].size()){
				printf("-1");return 0;
			} else seg[0]++,seg[c]--;
			continue;
		}
		int x=a[i][pos],y=a[i+1][pos];
//		if(x<y)printf("[%d,%d]\n",0,c-y+1);
//		else printf("[%d,%d]\n",c-x+1,c-y+1);
		if(x<y){
			seg[0]++,seg[c-y+1]--;
			seg[c-x+1]++,seg[c]--;
			continue;
		} seg[c-x+1]++,seg[c-y+1]--;
	}
	int ans=-1;
	for(int i=0,t=0;i<c;++i){
		t+=seg[i];
		if(t==n-1){
			ans=i;
			break;
		}
	}
	printf("%d",ans);
}