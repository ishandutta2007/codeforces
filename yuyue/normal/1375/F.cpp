#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
LL rk[10],a[10],p[10];
bool cmp(int x,int y){
	return a[x]<a[y];
}
void getorder(){
	F(i,1,3) p[i]=i;
	sort(p+1,p+4,cmp);
	F(i,1,3) rk[i]=p[i];
}
int main(){
	F(i,1,3) a[i]=read();
	cout<<"First\n";
	getorder();
	while (1){
		int del1=a[rk[3]]-a[rk[2]],del2=a[rk[2]]-a[rk[1]];
//		cout<<del1<<" "<<del2<<"   cmp\n";
		int id;
		if (del1>del2){
			cout<<del1<<endl;
			cin>>id;
			a[id]+=del1;
		}
		else{
			cout<<del2<<endl;
			cin>>id;
			a[id]+=del2;
		}
		getorder();
//		cout<<a[rk[1]]<<" "<<a[rk[2]]<<" "<<a[rk[3]]<<"  rank\n";
		if (rk[3]==id){
			break;
		}
	}
	LL tmp=a[rk[3]]*2-a[rk[2]]-a[rk[1]];
	cout<<tmp<<endl;
	int id;
	cin>>id;
	a[id]+=tmp;
	getorder();
//	cout<<a[rk[1]]<<" "<<a[rk[2]]<<" "<<a[rk[3]]<<"  rank\n";
	cout<<a[rk[3]]-a[rk[2]]<<endl;
	return 0; 
}