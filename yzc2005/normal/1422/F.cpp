#include <bits/stdc++.h>
const int N=200005,M=N*200,P=1e9+7;
int n,q,x,tot,pre[N],inv[N],fac[N],rt[N],ls[M],rs[M],val[M];
void modify(int &p,int q,int x,int v,int l=1,int r=n){
  p=++tot;val[p]=!val[q]?v:1ll*val[q]*v%P; 
  if(l==r)return;int mid=l+r>>1;
  if(mid>=x)rs[p]=rs[q],modify(ls[p],ls[q],x,v,l,mid);
  else ls[p]=ls[q],modify(rs[p],rs[q],x,v,mid+1,r);
}
int query(int p,int L,int R,int l=1,int r=n){
  if(l>=L&&r<=R)return val[p];
  int mid=l+r>>1,ans=1;
  if(mid>=L&&ls[p])ans=1ll*ans*query(ls[p],L,R,l,mid)%P;
  if(mid<R&&rs[p])ans=1ll*ans*query(rs[p],L,R,mid+1,r)%P;
  return ans;
}
int main(){
  scanf("%d",&n);
  inv[0]=inv[1]=1;for(int i=2;i<N;++i)inv[i]=1ll*(P-P/i)*(inv[P%i])%P;
  for(int i=2;i<N;++i)if(!fac[i])for(int j=i;j<N;j+=i)fac[j]=i;
  for(int i=1;i<=n;++i){
    scanf("%d",&x);rt[i]=rt[i-1];
    while(fac[x]){
      int v=fac[x],c=1; 
      while(x%v==0){
        c*=v,x/=v;
        if(pre[c])modify(rt[i],rt[i],pre[c],inv[v]);    
        pre[c]=i;  
      }
      modify(rt[i],rt[i],i,c);
    }
  }
  scanf("%d",&q);
  for(int i=1,l,r,lst=0;i<=q;++i){
    scanf("%d%d",&l,&r);
    l=(l+lst)%n+1,r=(r+lst)%n+1;
    if(l>r)std::swap(l,r);
    printf("%d\n",lst=query(rt[r],l,r));
  }
  return 0; 
}