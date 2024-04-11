#include <bits/stdc++.h>
#define y1 __y1
using namespace std;
const int N=200005;
int n,q;
set <int> U,L;
map <int,int> u,l;
int main(){
	scanf("%d%d",&n,&q);
	U.clear(),L.clear(),u.clear(),l.clear();
	U.insert(0),L.insert(0);
	U.insert(n+1),L.insert(n+1);
	u[0]=l[0]=n+1,u[n+1]=l[n+1]=0;
	for (int i=1;i<=q;i++){
		int x,y;
		char ch[2];
		scanf("%d%d%s",&y,&x,ch);
		if (ch[0]=='L'){
			if (u[y]||l[x]){
				puts("0");
				continue;
			}
			int x1=*L.upper_bound(x),y1=n+1-x1;
			int y2=*--U.upper_bound(y),x2=n+1-y2;
			if (y1<y2)
				l[x]=x2-x;
			else
				l[x]=l[x1]+x1-x;
			printf("%d\n",l[x]);
			L.insert(x);
		}
		else {
			if (l[x]||u[y]){
				puts("0");
				continue;
			}
			int x1=*--L.upper_bound(x),y1=n+1-x1;
			int y2=*U.upper_bound(y),x2=n+1-y2;
			if (x1>x2)
				u[y]=y1-y;
			else
				u[y]=u[y2]+y2-y;
			printf("%d\n",u[y]);
			U.insert(y);
		}
	}
	return 0;
}