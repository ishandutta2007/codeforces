//dev-c++ 4.9.9.2  +  win XP
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define int long long
typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 100000 + 6;
const int MAX_A = 1000000000 + 7;

int n;
LL m;
LL A;
LL pre[MAX_N];
vector<pii> a;
LL cf,cm;
LL b[MAX_N];

bool check(LL id,LL ret,int i) { //number id is final min
//     
//
//cout<<"id = "<<id<<" , ret = "<<ret<<" , i="<<i;
     pii tmp=make_pair(id,-1);
//     i=n;
     int pos = lower_bound( a.begin(),a.end(),tmp ) - a.begin() -1;
     if (pos + i > n) pos = n-i;
//     cout << "id = " <<id<<" , pos = " <<pos<<endl;
//
//
//     cout<<" pos = "<<pos;
//
//
//     cout<<" pre = "<<pre[pos]<<endl;
// 
//
//    cout << "val = " <<id*pos - pre[pos]<<endl;
//
//
//     cout<<"ret = " <<ret<<endl;
//     cout <<((id*pos - pre[pos]) <= ret) <<endl;
//     cout << "pos = " << pos<< " , pre = " << pre[pos] << " , id = " << id << " , ret = " << ret<<endl;
	 if  ((id*pos - pre[pos]) <= ret ) return true;
     else return false;
}

main () {
    while (scanf("%I64d %I64d %I64d %I64d %I64d",&n,&A,&cf,&cm,&m) != EOF) {
          a.resize(n+1);
          a[0] = make_pair(-1,-1);
          for (int x=1;n>=x;x++) {
              int i;
              scanf("%I64d",&i);
              a[x] = make_pair(i,x);
          }
          sort(a.begin(),a.end());
          pre[0] = 0;
          for (int x=1;n>=x;x++) {
              pre[x] = pre[x-1] + a[x].first;
          }
          LL mx1,mx2,mx = -1;
          for (int i=0;n>=i;i++) {  //how many to A
              LL ret = m - (A*i - (pre[n] - pre[n-i]) );
              if (ret < 0) break;
//              cout<<"i = " << i << endl;
              //min point
              int L=0,R=A+1;
              while (R-L != 1) {
//
//
//
//                    cout<<"L = " << L<<" , R = " << R<<endl;
                    int mid=(L+R) >> 1;
                    if (check(mid,ret,i) == true) L=mid;
                    else R=mid;
              }
              //L is okay
              if (L*cm + i*cf > mx) {
//                       cout<<"i = "<<i<<" , L = " << L<<endl;
                       mx = L*cm + i*cf;
                       mx1=i;
                       mx2=L;
              }
          }
          printf("%I64d\n",mx);
          for (int i=1;n>=i;i++) {
//              cout<<"A = "<<A<<endl;
//              cout <<"mx2 = " << mx2<<endl;
              if (a[i].first<mx2) a[i].first = mx2;
//
              if (i >= n-mx1+1) a[i].first=A;
//              cout<<"a[i] . fisrt = " << a[i].first<<endl;
              
              b[a[i].second] = a[i].first;
          }
          for (int x=1;n>=x;x++) {
              if (x!=1) printf(" ");
              printf("%I64d",b[x]);
          }
          puts("");
    }
}