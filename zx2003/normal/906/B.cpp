#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>a[N],ans[N];
int n,m,i,j,x,y,x1,x2,k,ss,bb[N],rev;
pair<int,int> b[N],c[N];
set<pair<int,int> >s;
set<pair<int,int> >::iterator it;
inline int abs(int x){return x>0?x:-x;}
inline bool check(int a,int b){
	int xa=(a-1)/m+1,ya=(a-1)%m+1,xb=(b-1)/m+1,yb=(b-1)%m+1;
	return abs(xa-xb)+abs(ya-yb)>1;
}
int main(){
	scanf("%d%d",&n,&m);if(n>m)swap(n,m),rev^=1;
	if(n==1 && m==1)return puts("YES\n1"),0;
	if((n==1 && m<4) || (n==2 && m<=3))return puts("NO"),0;
	if(n==1){
		puts("YES");
		for(i=3;i<=m;i+=2)printf("%d%c",i,rev?'\n':' ');printf("%d%c",1,rev?'\n':' ');
		for(i=4;i<=m;i+=2)printf("%d%c",i,rev?'\n':' ');printf("%d%c",2,rev?'\n':' ');
		return 0;
	}
	if(rev)swap(n,m),rev^=1;
	for(i=1;i<=n;++i){
		a[i].resize(m+2);ans[i].resize(m+2);
		for(j=1;j<=m;++j)a[i][j]=++x,bb[x]=(i+j)&1;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			int s=4-(i==1 || i==n)-(j==1 || j==m);
			if((i+j)&1)c[++x2]=make_pair(s,a[i][j]);
				else b[++x1]=make_pair(s,a[i][j]);
		}
	sort(b+1,b+x1+1),sort(c+1,c+x2+1);
	for(x=y=i=1;i<=x1;++i){
		ans[x][y]=b[x1-i+1].second;
		if(++y>m)++x,y=1;
	}ss=x2;
	if(n&1){
		for(i=1;i<=x2;++i)
			if(check(c[i].second,ans[x-1][y]) && check(c[i].second,ans[x][y-1]))
				break;
		ans[x][y]=c[i].second;c[i].second=0;
		if(++y>m)++x,y=1;--ss;
	}
	srand(time(0));
	for(i=1;i<=x2;++i)if(c[i].second)s.insert(c[i]);
	while(1){
		int tx=x,ty=y;
		for(i=1;i<=ss;++i){
			if(!bb[ans[x-1][y]]){
				for(it=s.begin();it!=s.end();++it)if(check(ans[x-1][y],it->second))break;
				if(it==s.end())break;
				ans[x][y]=it->second,s.erase(it);
			}else ans[x][y]=s.begin()->second,s.erase(s.begin());
			if(++y>m)++x,y=1;
		}
		if(i>ss)break;s.clear();
		for(i=1;i<=x2;++i)if(c[i].second)c[i].first=rand(),s.insert(c[i]);
		x=tx,y=ty;
	}
	puts("YES");
	if(!rev)for(i=1;i<=n;++i,putchar('\n'))for(j=1;j<=m;++j)printf("%d ",ans[i][j]);
		else for(i=1;i<=m;++i,putchar('\n'))for(j=1;j<=n;++j)printf("%d ",ans[j][i]);
	return 0;
}