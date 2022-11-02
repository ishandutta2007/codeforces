#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=10015;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;  
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s[N];
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>::iterator it;
long long ans;
int t1,t2,n,k;
pair<int,pair<int,int> > a[N*10];
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++){
		a[i].second.first=read(); a[i].first=read(); a[i].second.second=read();
	}
	sort(&a[1],&a[n+1]);
	for(int i=n;i;i--){
		for(int j=max(a[i].second.second-k,0);j<=a[i].second.second+k;j++){
			it=s[j].lower_bound(a[i].second.first-a[i].first);
			t1=it==s[j].end()?s[j].size():s[j].order_of_key(*it);
			it=s[j].upper_bound(a[i].second.first+a[i].first);
			t2=it==s[j].end()?s[j].size():s[j].order_of_key(*it);
			//cout<<i<<" "<<j<<" "<<t1<<" "<<t2<<endl;
			ans+=t2-t1;
		}
		s[a[i].second.second].insert(a[i].second.first);
	}
	cout<<ans<<endl;
}