#include<bits/stdc++.h>
#define LL long long

using namespace std;
const int M=2e5+100;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int n,m;
int a[M],s[M],cnt[M];
bool used[M];
priority_queue<pair<int,int> > q;
int main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++) a[i]=read(),s[a[i]]++;
	for (int i=1;i<=n;i++){
		if (!used[a[i]]){
			q.push({s[a[i]],a[i]});
			used[a[i]]=1;
		}
	}
	for (int i=1;i<=m;i++){
		pair<int,int> d=q.top(); q.pop();
		cnt[d.second]++;
		cout<<d.second<<" ";
		q.push({s[d.second]/(cnt[d.second]+1),d.second});
	}
	return 0;
}