#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
typedef pair<int,int> pii;
vector<pii> anses;
int n,a[maxn],pos[maxn];
int swp(int x,int y){
	anses.push_back(pii(x,y));
	swap(a[x],a[y]);
	swap(pos[a[x]],pos[a[y]]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;++i)if(pos[i]!=i){
		if(2*abs(i-pos[i])>=n){
			swp(i,pos[i]);
		} else {
			int x=i,y=pos[i];
			if(x>y)swap(x,y);
			if(x<=n/2&&y>n/2){
				swp(1,y);
				swp(1,n);
				swp(n,x);
				swp(1,n);
				swp(1,y);
			} else if(x<=n/2&&y<=n/2){
				swp(x,n);
				swp(n,y);
				swp(x,n);
			} else if(x>n/2&&y>n/2){
				swp(1,x);
				swp(1,y);
				swp(1,x);
			}
		}
	}
	printf("%d\n",anses.size());
	for(auto a:anses)printf("%d %d\n",a.first,a.second);
//	for(int i=1;i<=n;++i)printf("[%d]",a[i]);
}