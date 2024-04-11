#include <iostream>

using namespace std;

long cnt[30];

int main(){
    long q;
    cin >> q;
    for(long i = 0; i < q; i++){
        long n;
        cin >> n;
        for(long j = 0; j < 30; j++) cnt[j] = 0;
        for(long j = 0; j < n; j++){
            long m;
            cin >> m;
            for(long k = 0; k < 30; k++){
                long p = 1<<k;
                if(p&m){
                    cnt[k]++;
                    break;
                }
            }
        }
        long tmp = 0;
        for(long j = 0; j < 11; j++){
            tmp += (1<<j)*cnt[j];
            tmp -= (tmp%(1<<(j+1)));
        }
        tmp += cnt[11]*2048;
        if(tmp > 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}