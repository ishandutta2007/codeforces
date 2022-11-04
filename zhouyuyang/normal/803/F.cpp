#include<cstdio>
const int N=100010,P=1000000007;
int n,m,i,j,t,a[N],f[N],pow[N],ans;
int main(){
  scanf("%d",&n);
  for(pow[0]=i=1;i<=n;i++)
    pow[i]=pow[i-1]*2%P;
  while(n--)scanf("%d",&i),a[i]++,m=i>m?i:m;
  for(i=1;i<=m;i++){
    for(t=0,j=i;j<=m;j+=i)t+=a[j];
    f[i]=pow[t]-1;
  }
  for(i=m;i;i--)for(j=i+i;j<=m;j+=i)f[i]=(f[i]-f[j]+P)%P;
  printf("%d",f[1]);
}