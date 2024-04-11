#include <bits/stdc++.h>
using namespace std;
//b-a
struct aa{
    int id;
    int a;
    int p;
    int b;
};
int gettype(char c){
    if(isdigit(c))return 0;
    else if('a'<=c&&c<='z')return 1;
    else return 2;
}
int main(){
    int N,L,R;cin>>N>>L>>R;
    vector<aa>seq;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        seq.push_back(aa{i,a,0,-1});
    }
    for(int i=0;i<N;++i){
        int a;cin>>a;
        seq[i].p=a;
    }
    sort(seq.begin(),seq.end(),[](const aa&l,const aa&r){
        return l.p<r.p;;
    });
    int nowsum=-2e9;
    bool ok=true;
    for(int i=0;i<seq.size();++i){
        int next=nowsum+seq[i].a+1;
        if(next<L)next=L;
        else if(next>R)ok=false;
        seq[i].b=next;
        nowsum=seq[i].b-seq[i].a;
    }
    if(ok){
        vector<int>anss(N);
        for(int i=0;i<N;++i){
            anss[seq[i].id]=seq[i].b;
        }
        for(int i=0;i<N;++i){
            cout<<anss[i];
            if(i==N-1)cout<<endl;
            else cout<<" ";
        }
    }else{
        cout<<-1<<endl;
    }
    return 0;

}