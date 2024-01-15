#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL Phi(LL n){
    LL res = n;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            res = res/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        res = res/n*(n-1);
        return res;
}

int main(){
    LL n;
    cin>>n;
    while(n--){
        LL x;
        cin>>x;
        cout<<Phi(x)<<endl;
    }
    return 0;
}

