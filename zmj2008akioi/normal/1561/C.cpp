#include <cstdio>
#include <algorithm>
int t,n,l,r,num;
struct lev{
	int k,l;
	lev(){};
	lev(int k,int l):k(k),l(l){};
}arr[100010];
inline int max(int x,int y){
	return x>y?x:y;
}
inline bool cmp(lev a,lev b){
	return a.l<b.l;
}
inline bool check(int start){
	int level=start;
	for(register int i=0;i<n;++i){
		if(level<arr[i].l)return false;
		level+=arr[i].k;
	}
	return true;
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		for(register int j=0;j<n;++j){
			scanf("%d",&arr[j].k);
			arr[j].l=0;
			for(register int p=0;p<arr[j].k;++p){
				scanf("%d",&num);
				arr[j].l=max(arr[j].l,num-p+1);
			}
		}
		std::sort(arr,arr+n,cmp);
		l=1,r=1e9+1;
		while(r-l>1){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid;
		}
		if(check(l))printf("%d\n",l);
		else printf("%d\n",r);
	}
	return 0;
}