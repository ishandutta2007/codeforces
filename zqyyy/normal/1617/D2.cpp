#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
inline int query(int a,int b,int c){
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    return read();
}
const int N=10007;
int n,a[N];
inline void work(){
    n=read();
    for(int i=1;i<=n;i+=3)a[i]=query(i,i+1,i+2);
    int crew=0,imp=0;
    for(int i=1;i+3<=n;i+=3)
	if(a[i]^a[i+3]){
	    a[i+1]=query(i+1,i+2,i+3);
	    a[i+2]=query(i+2,i+3,i+4);
	    for(int j=i;j<i+3;j++)
		if(a[j]^a[j+1]){
		    imp=j,crew=j+3;
		    if(a[j])swap(imp,crew);
		    break;
		}
	    a[i]=a[i+3]=-1;
	    break;
	}
    vector<int>vec={imp};
    for(int i=1;i<=n;i+=3)
	if(~a[i]){
	    if(a[i]){
		if(query(i,i+1,imp)){
		    if(!query(i+2,crew,imp))vec.push_back(i+2);
		}else if(query(i,crew,imp))vec.push_back(i+1);
		else vec.push_back(i);
	    }else{
		if(!query(i,i+1,crew)){
		    vec.push_back(i),vec.push_back(i+1);
		    if(!query(i+2,crew,imp))vec.push_back(i+2);
		}else{
		    vec.push_back(i+2);
		    if(query(i,crew,imp))vec.push_back(i+1);
		    else vec.push_back(i);
		}
	    }
	}else{
	    for(int j=i;j<i+3;j++)
		if(j!=imp && j!=crew)
		    if(!query(j,crew,imp))
			vec.push_back(j);
	}
    printf("! %lu ",vec.size());
    for(int x:vec)printf("%d ",x);
    cout<<endl;
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}