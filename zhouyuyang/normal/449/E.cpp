#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   1000005
#define P   1000000007

int     T,N,M,A[n],B[n],C[n],Phi[n];
bool    V[n];

inline  void    Add(int&x,const int&y){
        x+=y;
        if  (x>=P)  x-=P;   else
        if  (x<=-P) x+=P;
}

int     main(){
        for (int i=1,x=0,y=0;i<n;i++)
            Add(x,2*i+2),Add(y,2ll*i*i%P),Add(A[i],(1ll*i*i*i-1ll*x*i+y)%P);
        for (int i=1;i<n;i++)   Phi[i]=i;

        for (int i=2;i<n;i++)   if  (!V[i])
        for (int j=i;j<n;j+=i)  V[j]=1,Phi[j]=Phi[j]/i*(i-1);

        for (int i=1;i<n;i++)
        for (int j=i;j<n;j+=i)  Add(A[j],2ll*i*Phi[j/i]%P);

        for (int i=1;i<n;i++)   
            B[i]=(1ll*A[i]*i+B[i-1])%P,C[i]=(1ll*A[i]*i%P*i+C[i-1])%P,Add(A[i],A[i-1]);
        for (scanf("%d",&T);T--;){
            scanf("%d%d",&N,&M);    int t=min(++N,++M);
            printf("%d\n",((1ll*N*M%P*A[t]-1ll*(N+M)*B[t]+C[t])%P+P)%P);
        }
}