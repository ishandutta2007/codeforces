#include<stdio.h>
#include<algorithm>
#include<deque>
int ans[500002][2],a[500002];
int n,m,k,aa,ab;
struct node{
	int id;
	long long num;
	bool operator<(const node &p)const{return num<p.num;}
}p[500002];
std::deque<int>Q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&aa);
		Q.push_back(aa);
	}
	for(int i=1;i<=m;i++)scanf("%lld",&p[i].num),p[i].id=i;
	std::sort(p+1,p+m+1);
	int p0=1;
	for(int i=1;i<=n;i++){
		aa=Q.front();Q.pop_front();
		ab=Q.front();Q.pop_front();
		while(p0<=m&&p[p0].num<=i){
			ans[p[p0].id][0]=aa;
			ans[p[p0].id][1]=ab;
			p0++;
		}
		if(aa<ab)aa^=ab^=aa^=ab;
		Q.push_front(aa);Q.push_back(ab);
	}
	for(int i=1;i<=n;i++){
		a[i]=Q.front();
		Q.pop_front();
	}
	for(int i=p0;i<=m;i++){
		ans[p[i].id][0]=a[1];
		ans[p[i].id][1]=a[(p[i].num-2)%(n-1)+2];
	}
	for(int i=1;i<=m;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
}