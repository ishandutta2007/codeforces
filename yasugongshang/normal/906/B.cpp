#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

int g[20][20],A[20],P1[N],P2[N];
int n,m;

int main(){
	n=IN(),m=IN();
	if (n<=3&&m<=3){
		For(i,1,n*m+1) A[i]=i;
		For(i,1,n) For(j,1,m+1) g[(i-1)*m+j][i*m+j]=1;
		For(i,1,n+1) For(j,1,m) g[(i-1)*m+j][(i-1)*m+j+1]=1;
		do{
			bool chk=1;
			For(i,1,n*m+1) For(j,1,n*m+1) if (g[i][j]&&(g[A[i]][A[j]]||g[A[j]][A[i]])) chk=0;
			if (!chk) continue;
			puts("YES");
			For(i,1,n+1){
				For(j,1,m+1) printf("%d ",A[(i-1)*m+j]);
				puts("");
			}
			return 0;
		} while (next_permutation(A+1,A+n*m+1));
		puts("NO");
	} lf (n>3){
		puts("YES");
		for (int i=n;i;i--) if (i&1) P1[++*P1]=i;
		for (int i=n;i;i--) if (!(i&1)) P1[++*P1]=i;
		for (int i=n;i;i--) if (!(i&1)) P2[++*P2]=i;
		for (int i=n;i;i--) if (i&1) P2[++*P2]=i;
		if (n%2==0){
			memcpy(P2,P1,sizeof(P1));
			reverse(P2+1,P2+n+1);
		}
		For(i,1,n+1){
			For(j,1,m+1){
				printf("%d ",((j&1?P1[i]:P2[i])-1)*m+(j%m+1));
			}
			puts("");
		}
	} else{
		puts("YES");
		for (int i=m;i;i--) if (i&1) P1[++*P1]=i;
		for (int i=m;i;i--) if (!(i&1)) P1[++*P1]=i;
		for (int i=m;i;i--) if (!(i&1)) P2[++*P2]=i;
		for (int i=m;i;i--) if (i&1) P2[++*P2]=i;
		if (m%2==0){
			memcpy(P2,P1,sizeof(P1));
			reverse(P2+1,P2+m+1);
		}
		For(i,1,n+1){
			For(j,1,m+1){
				printf("%d ",((i%n+1)-1)*m+(i&1?P1[j]:P2[j]));
			}
			puts("");
		}
	}
}