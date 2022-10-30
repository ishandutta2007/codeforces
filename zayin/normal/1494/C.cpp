#include<bits/stdc++.h>
using namespace std;

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<class T>
ostream& operator << (ostream& os, const vector<T>& v)  {
    os<<"[";
    for (int i=0;i<v.size();++i)
        os<<v[i]<<",]"[i==v.size()-1];
    return os;
}

void printr(ostream& os){os<<endl;}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t<<" ";
	printr(os,args...);
}
#define print(args...) printr(cout,##args)

// INPUT
template<class T>
void read(T& x) {cin>>x;}
template<class T, class... Args>
void read(T& t, Args&... args){
    read(t),read(args...);
}


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
	os<<t; if (sizeof...(args)) os<<", ";
	dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed

typedef long long LL;

#define maxn 200050

int n,m;
int a[maxn],b[maxn];

int calc(vector<int>& A,vector<int>& B)    {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    vector<int> C(B.size());
    for (int i=B.size()-1,j=A.size()-1,t=0;i>=0;--i)    {
        // dbg(i,j);
        C[i]=t;
        while (j>=0&&A[j]>B[i]) --j;
        if (j>=0&&A[j]==B[i]) ++t;
    }

    int ans=0;
    for (int i=0,j=0;i<B.size();++i)    {
        while (j<A.size()&&A[j]<=B[i]) ++j;
        int l=lower_bound(B.begin(),B.end(),B[i]-j+1)-B.begin();
        ans=max(ans,C[i]+(i-l+1));
    }
    return ans;
}

int main()  {
    int T;
    read(T);
    while (T--) {
        read(n,m);
        for (int i=0;i<n;++i) read(a[i]);
        for (int i=0;i<m;++i) read(b[i]);

        vector<int> A,B;
        for (int i=0;i<n;++i) if (a[i]>0) A.push_back(a[i]);
        for (int i=0;i<m;++i) if (b[i]>0) B.push_back(b[i]);

        int ans=calc(A,B);
        A.clear(),B.clear();
        for (int i=0;i<n;++i) if (a[i]<0) A.push_back(-a[i]);
        for (int i=0;i<m;++i) if (b[i]<0) B.push_back(-b[i]);
        ans+=calc(A,B);

        print(ans);
    }
    return 0;
}