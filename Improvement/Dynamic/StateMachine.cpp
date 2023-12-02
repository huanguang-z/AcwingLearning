#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
typedef pair<int,int> PI;

//状态机+滚动数组优化线性dp
// const int N = 1e5+10;
// int n,w[N],f[2][2];
// void solve(){
//     memset(f, -0x3f, sizeof f);
//     f[0][0] = 0;
//     cin >> n;
//     for (int i = 1; i <= n; ++ i) cin >> w[i];
//     for (int i = 1; i <= n; ++ i)
//     {
//         f[i & 1][0] = max(f[(i - 1) & 1][1], f[(i - 1) & 1][0]);
//         f[i & 1][1] = f[(i - 1) & 1][0] + w[i];
//     }
//     cout << max(f[n & 1][0], f[n & 1][1]) << endl;
// }
// int main(){
//     int T = 1;
//     cin>>T;
//     while(T--)
//         solve();
//     return 0;
// }

//状态机+有限转移
// const int N = 1e5+10,M=110;
// int n,k;
// int w[N];
// int f[N][M][2];
// int main(){
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)
//         cin>>w[i];
//     memset(f,-0x3f,sizeof f);
//     f[0][0][0]=0;
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<=k;j++){
//             f[i][j][0]=f[i-1][j][0];
//             if(j)
//                 f[i][j][0]=max(f[i][j][0],f[i-1][j-1][1]+w[i]);
//             f[i][j][1]=max(f[i-1][j][1],f[i-1][j][0]-w[i]);
//         }
//     int res = 0;
//     for(int j=0;j<=k;j++)
//         res=max(res,f[n][j][0]);
//     cout<<res<<endl;
//     return 0;
// }

//三状态机
// const int N = 1e5+10;
// int n,w[N],f[2][3];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>w[i];
//     memset(f,-0x3f,sizeof f);
//     f[0][0]=0;
//     for(int i=1;i<=n;i++){
//         f[i&1][0]=max(f[(i-1)&1][0],f[(i-1)&1][2]);
//         f[i&1][1]=max(f[(i-1)&1][1],f[(i-1)&1][0]-w[i]);
//         f[i&1][2]=f[(i-1)&1][1]+w[i];
//     }
//     cout<<max(f[n&1][0],f[n&1][2])<<endl;
//     return 0;
// }

