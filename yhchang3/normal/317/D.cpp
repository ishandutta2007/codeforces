#include<bits/stdc++.h>
using namespace std;
int sg[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
bool visit[40000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   int res=0;
   int cnt=0;
   int limit=round(sqrt(n));
   for(long long int i=2;i<=limit;i++){
      if(!visit[i]){
         int ccnt=0;
         for(long long int tmp=i;tmp<=n;tmp*=i){
            ccnt++;
            if(tmp<=limit)
               visit[tmp]=true;
         }
         cnt+=ccnt;
         res^=sg[ccnt];
      }
   }
   if((n-cnt)&1)
      res^=1;
   if(res)
      cout<<"Vasya"<<endl;
   else
      cout<<"Petya"<<endl;
}