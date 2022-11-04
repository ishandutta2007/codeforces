#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   200015
#define INF (1ll<<40)
#define I64 long long
#define Rep(i,a,b)  for(int i=a;i>=b;i--)
#define For(i,a,b)  for(int i=a;i<=b;i++)

int     N,A[n],X[n],Y[n],F[n];
I64     B[n],D[n];

void    Add(int x,int k){
        for (x=*B-x+1;x<=*B;x+=x&-x)    F[x]=max(F[x],k);
}
int     Ask(int x){
        int ret=0;  for (x=*B-x+1;x;x-=x&-x)    ret=max(ret,F[x]);
        return  ret;
}

int     main(){
        scanf("%d",&N); N+=2;
        For(i,1,N)  scanf("%d",&A[i]);
        For(i,2,N-1)scanf("%I64d",&D[i]);  D[1]=D[N]=INF;

        X[1]=X[2]=1;Y[N-1]=Y[N]=N;
        For(i,3,N)  {
			int j=i-1;
			for (;j>1&&A[i]-A[X[j]]>D[j]*2;)	j=X[j];	X[i]=j;
		}
        Rep(i,N-2,1){
			int j=i+1;
			for (;j<N&&A[Y[j]]-A[i]>D[j]*2;)	j=Y[j];	Y[i]=j;
		}

        For(i,2,N-1)if  (Y[X[i]]==i&&X[Y[i]]==i)    return  puts("0"),0;
        For(i,1,N)  X[i]=A[i]-A[X[i]],Y[i]=A[Y[i]]-A[i];

        For(i,1,N)  B[++*B]=D[i]*2+A[i]-X[i],B[++*B]=-D[i]*2+A[i]+Y[i];
        sort(B+1,B+*B+1);   *B=unique(B+1,B+*B+1)-B-1;
        For(i,0,*B) F[i]=-(1<<30);  int Ans=1<<30;

        For(i,2,N){
            if  (2*D[i-1]>X[i-1])  {
                int t=lower_bound(B+1,B+*B+1,D[i-1]*2+A[i-1]-X[i-1])-B; Add(t,A[i-1]);
            }
            if  (2*D[i]>Y[i])   {
                int t=lower_bound(B+1,B+*B+1,-D[i]*2+A[i]+Y[i])-B;
                Ans=min(1ll*Ans,1ll*A[i]-Ask(t));
            }
        }   printf("%.6lf\n",Ans*.5);
}