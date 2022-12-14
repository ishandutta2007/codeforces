#include<bits/stdc++.h>

using namespace std;

struct seg {
    int posbegin,posend;
} seg[300050];

bool cmpbegin(struct seg cmp1,struct seg cmp2){
    if(cmp1.posbegin<cmp2.posbegin)
        return true;
    else if(cmp1.posbegin==cmp2.posbegin)
        if(cmp1.posend<cmp2.posend)
            return true;
    
    return false;
}

bool cmpend(struct seg cmp1,struct seg cmp2){
    if(cmp1.posend>cmp2.posend)
        return true;
    else if(cmp1.posend==cmp2.posend)
        if(cmp1.posbegin>cmp2.posbegin)
            return true;
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,ansbegin,ansend,anslen1,anslen2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        seg[i].posbegin=a;
        seg[i].posend=b;
    }
    sort(seg,seg+n,cmpbegin);
    ansbegin=-1;
    ansend=1E9+7;
    for(int i=0;i<n-1;i++){
        if(ansbegin<seg[i].posbegin)
            ansbegin=seg[i].posbegin;
        if(ansend>seg[i].posend)
            ansend=seg[i].posend;
    }
    anslen1=ansend-ansbegin;
    
    ansbegin=-1;
    ansend=1E9+7;
    sort(seg,seg+n,cmpend);
    for(int i=0;i<n-1;i++){
        if(ansbegin<seg[i].posbegin)
            ansbegin=seg[i].posbegin;
        if(ansend>seg[i].posend)
            ansend=seg[i].posend;
    }
    anslen2=ansend-ansbegin;
    int ans=(anslen2>anslen1)? anslen2:anslen1;
    if(ans<0)   ans=0;
    cout<<ans<<endl;
}