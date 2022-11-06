#include"bits/stdc++.h"
using namespace std;
#pragma warning(disable:4996)
using pa=pair<int,int>;

const double pi = acos(-1);

typedef complex<double> Comp;

int size(int n) {
	int res = 1;
	while (res < n) res <<= 1;
	return res;
}

void fft(vector<Comp>& v) {
	int n = size(v.size());
	if (n > (int)v.size()) v.resize(n);
	for (int j = 1, i = 0; j < n - 1; j++) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(v[i], v[j]);
	}
	for (int m = 2; m <= n; m <<= 1) {
		double deg = (-1) * 2 * pi / m;
		Comp r(cos(deg), sin(deg));
		for (int i = 0; i < n; i += m) {
			Comp w(1, 0);
			for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
				Comp t1 = v[j], t2 = w * v[k];
				v[j] = t1 + t2, v[k] = t1 - t2;
				w *= r;
			}
		}
	}
}

void ifft(vector<Comp>& v) {
	int n = size(v.size());
	if (n > (int)v.size()) v.resize(n);
	for (int j = 1, i = 0; j < n - 1; j++) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(v[i], v[j]);
	}
	for (int m = 2; m <= n; m <<= 1) {
		double deg = 2 * pi / m;
		Comp r(cos(deg), sin(deg));
		for (int i = 0; i < n; i += m) {
			Comp w(1, 0);
			for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
				Comp t1 = v[j], t2 = w * v[k];
				v[j] = t1 + t2, v[k] = t1 - t2;
				w *= r;
			}
		}
	}
	for (int i = 0; i < n; ++i) v[i] *= 1.0 / n;
}

vector<int> convolution(const vector<int>& p, const vector<int>& q) {
	int n = size(p.size() + q.size());
	vector<Comp> P(n), Q(n);
	for (int i = 0; i < (int)p.size(); i++) P[i] = p[i];
	for (int i = 0; i < (int)q.size(); i++) Q[i] = q[i];
	fft(P); fft(Q);
    // for(int i=0;i<P.size();++i){
    //     cout<<P[i].real()<<' '<<P[i].imag()<<"    ";
    // }
    // cout<<endl;
    //  for(int i=0;i<Q.size();++i){
    //     cout<<Q[i].real()<<' '<<Q[i].imag()<<"    ";
    // }
    // cout<<endl;
	for (int i = 0; i < n; i++) P[i] /= Q[i];
	ifft(P);
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = round(P[i].real());
	}
	return res;
}
int main() {
	int N,Q;cin>>N>>Q;
    deque <int>que;
    for(int i=0;i<N;++i){
        int a;scanf("%d",&a);
        que.push_back(a);
    }
    vector<pair<int,int>>answers(3*N);
    for(int i=0;i<3*N;++i){
        int a=que.front();
        que.pop_front();
        int b=que.front();
        que.pop_front();
        answers[i]=make_pair(a,b);
        if(a>b)swap(a,b);
        que.push_front(b);
        que.push_back(a);
    }
    while(Q--){
        long long int  num;
        scanf("%lld",&num);
        num--;
        if(num>=3*N){
            num%=(N-1);
            num+=2*(N-1);
        }
        printf("%d %d\n",answers[num].first,answers[num].second);
    }
	return 0;
}