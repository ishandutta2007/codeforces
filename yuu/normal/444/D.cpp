#include <bits/stdc++.h>
using namespace std;
map <string, vector <int>> pre;
const int mahou=400;
map <pair<string, string>, int> ans;
string s;
int q;
pair <int, int> get(vector <int> &a, int i){
  if(i>=a.back()) return make_pair(a.back(), 1e9);
  if(i<=a[0]) return make_pair(-1e9, a[0]);
  int pos=upper_bound(a.begin(), a.end(), i)-a.begin();
  return make_pair(a[pos-1], a[pos]);
}
int main(){
  cin>>s>>q;
  for(int i=0; i<s.size(); i++){
    string t;
    for(int j=0; (j<=3)&&(i+j<s.size()); j++){
      t+=s[i+j];
      pre[t].push_back(i);
    }
  }
  for(int i=0; i<q; i++){
    string a, b;
    cin>>a>>b;
    auto res=ans.find(make_pair(a, b));
    if(res!=ans.end()) cout<<res->second<<'\n';
    else{
      if(a.size()>b.size()) swap(a, b);
      if(b.find(a)!=-1){
        auto res2=pre.find(b);
        if(res2!=pre.end()){
          cout<<b.size()<<'\n';
          ans[make_pair(a, b)]=ans[make_pair(b, a)]=b.size();
        }
        else{
          cout<<"-1\n";
          ans[make_pair(a, b)]=ans[make_pair(b, a)]=-1;
        }
      }
      else{
        auto resa=pre.find(a);
        if(resa!=pre.end()){
          auto resb=pre.find(b);
          if(resb!=pre.end()){
            if(resa->second.size()>resb->second.size()){
              swap(resa, resb);
              swap(a, b);
            }
            int res=s.size();
            if(resa->second.size()<=mahou){//smoll
              for(auto &i: resa->second){
                auto p=get(resb->second, i);
                res=min(res, (int)(i-p.first+a.size()));
                res=min(res, (int)(p.second-i+b.size()));
              }
            }
            else{//both big
              int j=0;
              for(auto i: resa->second){
                while((j+1<resb->second.size())&&(resb->second[j+1]<=i)) j++;
                if(i>=resb->second[j]){
                  res=min(res, (int)(i-resb->second[j]+a.size()));
                  if(j+1<resb->second.size()) res=min(res, (int)(resb->second[j+1]-i+b.size()));
                }
                else res=min(res, (int)(resb->second[j]-i+b.size()));
              }
            }
            cout<<(ans[make_pair(a, b)]=ans[make_pair(b, a)]=res)<<'\n';
          }
          else cout<<(ans[make_pair(a, b)]=ans[make_pair(b, a)]=-1)<<'\n';
        }
        else cout<<(ans[make_pair(a, b)]=ans[make_pair(b, a)]=-1)<<'\n';
      }
    }
  }
}