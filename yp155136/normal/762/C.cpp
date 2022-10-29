#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;
const int INF = 1e9 + 7;

int ft[MAX_N],bk[MAX_N];

int main () {
	string a,b;
	while (cin >>a >> b ){
		int sza=a.size();
		int szb=b.size();
		a=" "+a+" ";
		b=" "+b+" ";
		for (int i=0;MAX_N>i;i++) {
			ft[i] = bk[i] = INF;
		}
		ft[0] = 0;
		int id=1;
		for (int i=1;szb>=i;i++) {
			while (id<=sza && a[id]!=b[i]) id++;
			if (id>sza) break;
			ft[i]=id;
			//cout<<"ft["<<i<<"] = "<<ft[i]<<endl;
			id++;
		}
		int n=szb;
		bk[n+1]=0;
		id=sza;
		for (int i=szb;i>=1;i--) {
			while (id>0 && a[id]!=b[i]) id--;
			if (id<=0) break;
			bk[i]=id;
			//cout<<"bk["<<i<<"] = "<<bk[i]<<endl;
			id--;
		}
		int ans=0;
		int l=0,r=0;
		for (int i=0;n>=i;i++) {
			if (ft[i]==INF) break;
			int L=i,R=n+1; //R is the answer
			while (R-L!=1) {
				int mid=(L+R)>>1;
				if (bk[mid]==INF ||  bk[mid]<=ft[i]) L=mid;
				else R=mid;
			}
			//cout<<"i = "<<i<<" , R = "<<R<<endl;
			if (i+(n-R+1)>ans) {
				ans = max(ans,i+(n-R+1));
				l=i;
				r=R;
			}
		}
		if (ans==0) {
			printf("-\n");
			continue;
		}
		//cout<<"l = "<<l<<" , r = "<<r<<endl;
		//cout<<"ans = "<<ans<<endl;
		for (int i=1;l>=i;i++) cout<<b[i];
		for (int i=r;n>=i;i++) cout<<b[i];
		cout<<endl;
	}
}