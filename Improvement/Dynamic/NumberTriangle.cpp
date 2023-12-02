#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//基础三角形、记忆化搜索
// const int N = 1e2+10,INF = 0x3f3f3f3f;
// int T,n,m,w[N][N],f[N][N];
// int DP(int x, int y){
//     if(f[x][y]>=0)
//         return f[x][y];
//     if(x<1||x>n||y<1||y>m)
//         return f[x][y] = - INF;
//     if(x==1&&y==1)
//         return f[x][y] = w[x][y];
//     int t = 0;
//     t = max(t, max(DP(x-1,y),DP(x,y-1))+w[x][y]);
//     return f[x][y]=t;
// }
// int main(){
//     cin>>T;
//     while(T--){
//         memset(w,0,sizeof w);
//         memset(f,-1,sizeof f);
//         cin>>n>>m;
//         for(int i=1;i<=n;i++)
//             for(int j =1;j<=m;j++)
//                 cin>>w[i][j];
//         cout<<DP(n,m)<<endl;
//     }
//     return 0;
// }

//不可向回的数字三角形，记忆化搜索
// const int N = 1e2+10,INF = 0x3f3f3f3f;
// int n,w[N][N],f[N][N];
// int DP(int x, int y){
//     if(f[x][y]>=0)
//         return f[x][y];
//     if(x==1&&y==1)
//         return w[x][y];
//     if(x<1||y<1)
//         return INF;
//     int t = INF;
//     t = min(t,DP(x-1,y)+w[x][y]);
//     t = min(t,DP(x,y-1)+w[x][y]);
//     return f[x][y] = t;
// }
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=n;j++)
//             cin>>w[i][j];
//     memset(f,-1,sizeof f);
//     cout<<DP(n,n)<<endl;
//     return 0;
// }

//多次三角形复合，记忆化搜索
// const int N = 15, M = 2*N, INF = 0x3f3f3f3f;
// int n,a,b,c,w[N][N],f[M][N][N];
// int DP(int k, int i, int j){
//     if(f[k][i][j]>=0)
//         return f[k][i][j];
//     if(k==2&&i==1&&j==1)
//         return f[k][i][j]=w[1][1];
//     if(i<=0||j<=0||i>=k||j>=k)
//         return -INF;
//     int v = w[i][k-i];
//     if(i!=j)
//         v+=w[j][k-j];
//     int &t = f[k][i][j];
//     t = max(t,DP(k-1,i,j)+v);
//     t = max(t,DP(k-1,i-1,j)+v);
//     t = max(t,DP(k-1,i,j-1)+v);
//     t = max(t,DP(k-1,i-1,j-1)+v);
//     return f[k][i][j] = t;
// }
// int main(){
//     memset(f,-1,sizeof f);
//     cin>>n;
//     while(cin>>a>>b>>c,a||b||c)
//         w[a][b]=c;
//     cout<<DP(2*n,n,n)<<endl;
//     return 0;
// }

//不可重叠的多次三角形复合，记忆化搜索
// const int N = 55,M = 2*N,INF = 0x3f3f3f3f;
// int n,m,w[N][N],f[M][N][N];
// int DP(int k,int i,int j){
//     if(f[k][i][j]>=0)
//         return f[k][i][j];
//     if(k==2&&i==1&&j==1)
//         return f[k][i][j]=w[1][1];
//     if(i<=0||i>=k||j<=0||j>=k)
//         return -INF;
//     int v = w[i][k-j];
//     if(i!=j)
//         v+=w[j][k-j];
//     int t = 0;
//     t = max(t,DP(k-1,i,j)+v);
//     t = max(t,DP(k-1,i-1,j)+v);
//     t = max(t,DP(k-1,i,j-1)+v);
//     t = max(t,DP(k-1,i-1,j-1)+v);
//     return f[k][i][j]=t;
// }
// int main(){
//     memset(f,-1,sizeof f);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             cin>>w[i][j];
//     cout<<DP(n+m,n,n)<<endl;//f[k][i][j]的i，j均是横坐标
//     return 0;
// }