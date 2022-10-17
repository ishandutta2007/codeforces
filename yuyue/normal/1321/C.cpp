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
const int M=1e5+10;
vector<int> a;
string s,ss;
bool t[110];
int n;
int main(){
	n=read(); cin>>s;
	
	int ans=0;
	DF(i,25,1){
		bool flag=1;
		while (flag){
//			cout<<"   uu\n";
			ss.clear();
			F(j,0,SZ(s)) 
			if (!t[j]) ss+=s[j];
			else ans++;
			s=ss;
			a.clear();
			F(j,0,SZ(s)){
				if (s[j]=='a'+i) a.pb(j);
			}
			ms(t,0);
			flag=0;
//			cout<<s<<"   uuuu\n";
			F(j,0,SZ(a)){
//				cout<<a[j]<<" ";
				int pos=a[j];
				if (pos && s[pos-1]=='a'+i-1) {
//					cout<<pos<<"\n";
					flag=1;
					t[pos]=1;
				}
				if (pos<SZ(s) && s[pos+1]=='a'+i-1){
//					cout<<pos<<"\n";
					flag=1;
					t[pos]=1;
				} 
			}
//			cout<<"\n";
		}
		
	}
	cout<<ans<<"\n";
	return 0;
}