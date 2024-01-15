#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6+10;
int primes[N],cnt;
bool st[N];
int Phi[N];

void get_euler(int n){
    Phi[1] = 1;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++] = i;
            Phi[i] = i-1;
        }
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0){
                Phi[i*primes[j]]=Phi[i]*primes[j];
                break;
            }
            Phi[i*primes[j]]=Phi[i]*(primes[j]-1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    get_euler(n);

    LL res = 0;
    for(int i=1;i<=n;i++) res += Phi[i];
    cout<<res<<endl;
    return 0;
}