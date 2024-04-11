#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10,MAXLOG=18;
int sa[MAXN],rk[MAXN],cnt[MAXN],tmp[MAXN],height[MAXN];
int len,n,k,s[MAXN],pps[MAXN];
void suffix_array(){
   int A=100500,stp=0;
   for(int i=0;i<len;i++)
      sa[rk[i]=i]=i;
   if(len==1)  return;
   for(int i=0;i<len;i++)   rk[i]=s[i];
   for(int j=1;stp<len-1;j<<=1){
      int k=(j>>1);stp=0;
      for(int i=len-k;i<len;i++) tmp[stp++]=i;
      for(int i=0;i<len;i++)  if(sa[i]>=k)   tmp[stp++]=sa[i]-k;
      for(int i=0;i<=A;i++)         cnt[i]=0;
      for(int i=0;i<len;i++)   cnt[rk[i]]++;
      for(int i=1;i<=A;i++)         cnt[i]+=cnt[i-1];
      for(int i=len-1;i>=0;i--)
         sa[--cnt[rk[tmp[i]]]]=tmp[i];
      swap(rk,tmp);
      rk[sa[0]]=stp=0;
      for(int i=1;i<len;i++){
         stp+=(tmp[sa[i]]!=tmp[sa[i-1]]||sa[i-1]+k>=len||tmp[sa[i-1]+k]!=tmp[sa[i]+k]);
         rk[sa[i]]=stp;
      }
      A=stp;
   }
}
void getheight(){
   int k=0;height[0]=0;
   for(int i=0;i<len;i++){
      if(rk[i]==0)   continue;
      if(k) k--;
      while(s[i+k]==s[sa[rk[i]-1]+k])  k++;
      height[rk[i]]=k;
   }
}
string ss;
int sp[MAXLOG+1][MAXN],st[MAXN],ed[MAXN];
int lg[MAXN],num[MAXN],pos[MAXN];
void Sparsetable(){
   for(int i=0;i<len;i++)
      sp[0][i]=height[i];
   for(int j=1;(1<<j)<=len;j++)
      for(int i=0;i+(1<<j)<=len;i++)
         sp[j][i]=min(sp[j-1][i],sp[j-1][i+(1<<(j-1))]);
}
int lcp(int x,int y){
   int zz=lg[y-x+1];
   return min(sp[zz][x],sp[zz][y-(1<<zz)+1]);
}

bool check(int x,int y){
   int p,q,l,r;
   l=x;r=len-1;
   while(l<r){
      int mid=(l+r+1)/2;
      if(lcp(x+1,mid)>=y)
         l=mid;
      else
         r=mid-1;
   }
   q=l;
   l=0;r=x;
   while(l<r){
      int mid=(l+r)/2;
      if(lcp(mid+1,x)>=y)
         r=mid;
      else
         l=mid+1;
   }
   p=l;
   return pos[q]>=p;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   len=0;
   for(int i=2;i<MAXN;i++)
      lg[i]=lg[i/2]+1;
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>ss;st[i]=len;
      for(int j=0;j<ss.size();j++){
         num[len]=i;
         s[len++]=(int) ss[j]+1e5;
      }
      ed[i]=len-1;s[len++]=i;
   }
   suffix_array();
   getheight();
   Sparsetable();
   int kk=0,kkk=0;
   for(int i=0;i<len;i++){
      if(!num[sa[i]])   continue;
      if(!pps[num[sa[i]]]) kk++;
      pps[num[sa[i]]]++;
      if(kk>=k){
         while(kk-(pps[num[sa[kkk]]]==1)>=k){
            pps[num[sa[kkk]]]--;
            kk-=(!pps[num[sa[kkk]]]);
            kkk++;
         }
         pos[i]=kkk;
      }
   }
   for(int i=1;i<=n;i++){
      long long int ans=0;
      int zz=0;
      for(int j=st[i];j<=ed[i];j++){
         if(zz) zz--;
         while(zz+j<=ed[i]&&check(rk[j],zz+1)) zz++;
         ans+=zz;
      }
      if(i!=1) cout<<' ';
      cout<<ans;
   }
   cout<<endl;
}