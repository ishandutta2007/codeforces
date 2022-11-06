#include <bits/stdc++.h>
using namespace std;


int main(){
    string st;cin>>st;
    bool ans=false;
    for(int i=0;i<st.size();++i){
        for(int j=0;j<26;++j){
            string next(st);
            if(j+'a'==next[i])continue;
            next[i]=j+'a';

            bool ok=true;
            for(int k=0;k<st.size();++k){
                if(next[k]!=next[st.size()-1-k])ok=false;
            }
            if(ok)ans=true;
        }
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  
  return 0;
//    int N;cin>>N;
//    bool issame=true;
//    vector<string>sts;
//    for(int i=0;i<N;++i){
//        string st;cin>>st;
//        sts.emplace_back(st);
//    }
//    for(int i=0;i<N-1;++i){
//        bool ok=false;
//        for(int j=0;j<sts[i+1].size();++i){
//            string a=sts[i];
//            string b=sts[i+1];
//            b=b.substr(j)+b.substr(0,j);
//            if(a==b)ok=true;
//        }
//        if(!ok)issame=false;
//    }
//    if(!issame)cout<<-1<<endl;
//    else{
//        int ans=10000000;
//        for(int to=0;to<N;++to){
//            int nans=0;
//            for(int i=0;i<N;++i){
//             string ori(sts[i]);
//             int plus=1000;
//             for(int j=0;j<N;++j){
//                 if(sts[0]==(ori.substr(j)+ori.substr(0,j)))plus=min(plus,min(j,int(sts[0].size())-j));

//             }
//             nans+=plus;
//            }
//        ans=min(ans,nans);
//        }

//        cout<<ans<<endl;
//    }
}