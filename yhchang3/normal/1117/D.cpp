#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long int n;
int m;
template<int maxn>
struct Matrix{
   long long int entry[maxn][maxn];
   Matrix(){memset(entry,0,sizeof entry);}
   Matrix<maxn> operator*(const Matrix<maxn> &rhs) const{
      Matrix<maxn> res;
      for(int i=0;i<maxn;i++)
         for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
               res.entry[i][j]=(res.entry[i][j]+entry[i][k]*rhs.entry[k][j])%mod;
      return res;
   }
};
Matrix<100> tmp;
Matrix<100> exp(Matrix<100> M,long long int x){
   for(int i=0;i<m;i++)
      tmp.entry[i][i]=1;
   Matrix<100> z=M;
   while(x){
      if(x%2)
         tmp=tmp*z;
      z=z*z;
      x/=2;
   }
   return tmp;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m;
   Matrix<100> trans;
   for(int i=1;i<m;i++)
      trans.entry[i][i-1]=1;
   trans.entry[0][0]=trans.entry[0][m-1]=1;
   tmp=exp(trans,n);
   long long int ans=0;
   for(int i=0;i<m;i++)
      ans=(ans+tmp.entry[m-1][i])%mod;
   cout<<ans<<endl;
}