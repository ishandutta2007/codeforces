#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
int n,m,w,cur,ans[107];
inline int ask(int i,int v){
    cout<<"? "<<i<<" "<<v<<endl;
    int x=read();swap(cur,x);
    return cur-x;
}
int main(){
    n=read(),m=read(),w=n*m,ask(0,1);
    vector<int>S(n-1);iota(S.begin(),S.end(),1);
    while(ask(0,1)<=0);while(ask(0,1)>0);ask(0,-1);int fl=1;
    for(int i=0;i<w;i++){
	if(ask(0,1)>0){fl=1;continue;}
	else if(!fl)continue;
	if(S.empty())continue;ask(0,-1);
	int l=0,r=S.size();bool out=0;
	while(l+1<r){
	    int mid=(l+r)>>1;
	    if(out)for(int j=l;j<mid;j++)ask(S[j],1);
	    else for(int j=mid;j<r;j++)ask(S[j],-1);
	    if(ask(0,-1)<0)r=mid,out=0;
	    else l=mid,out=1;
	    ask(0,1);
	}
	int p=S[l];
	for(int j=out-1;j<m;j++)ask(p,-1);
	ans[p]=(i-m-1+w)%w,S.erase(S.begin()+l);
	i--,ask(0,-1),fl=ask(0,1)>0;
    }
    cout<<"! ";
    for(int i=1;i<n;i++)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}