#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 1000005
int i,j,k,l,s,n,m,test;
#define pb push_back
int tot,X,a[N],b[N],B[N],aa[N],bb[N];
vector<int>A;
mt19937 Rand(time(0));
inline int ask(int x) {
	printf("? %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
inline void up() {
    for (int i=1;i<=n;i++) b[i]=0;
    for (int i=2;i<=n;i++)  {
        int l=i-1,r=i+1;
        if (r>n) r=1;
        b[l]+=a[i]/2; 
		b[r]+=a[i]/2+(a[i]&1);
    } 
    b[2]+=a[1];
    for(int i=1;i<=n;i++) a[i]=b[i];
}
inline void check(int x,int y) {
    vector<int> B; 
	B.clear();
    for(auto p:A) {
        int s=(x-p+n)%n+1;
        if(a[s]==y) B.push_back(p);
    }
	A.clear();
    swap(B,A);
}
inline void work() {
	if (A.size()==1) return ;
	int x=Rand()%A.size(),y=Rand()%A.size();
	while (x==y) {
		x=Rand()%A.size(),y=Rand()%A.size();
	}
	int id=0;
    x=A[x]; y=A[y];
    if(x>y) swap(x,y); 
    for(int i=1;i<=n;i++) {
        int r=(i+y-x-1)%n+1;
        if(a[i]!=a[r]) {
            id=i;
            break;
        }
    }
    if (id) {
        id=(id+x-2+n)%n+1;
    }
    else id=Rand()%n+1;
	
	check(id,ask(id));
	up();
}
int main() {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) a[i]=m,aa[i]=m;
		for (int i=1;i<=n;i++) A.pb(i);
		for (int i=1;i<=1000;i++) {
			work();
		}
		printf("! %d\n",A[0]);
}