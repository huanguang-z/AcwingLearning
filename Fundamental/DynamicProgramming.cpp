#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

// const int N = 2e4+10;
// const int M = 2e3+10;

//普通背包
// int n,m;
// int v[N],w[N];
// int f[N][N];
// int main(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//         cin>>v[i]>>w[i];
//     for(int i=0;i<=m;i++)
//         f[0][i]=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(v[i]<=j)
//                 f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
//             else
//                 f[i][j]=f[i-1][j];
//         }
//     }
//     cout<<f[n][m]<<endl;
//     return 0;
// }

//完全背包
// int f[N],v[N],w[N];
// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//         cin>>v[i]>>w[i];
//     for(int i=1;i<=n;i++)
//         for(int j =v[i];j<=m;j++)
//             f[j]=max(f[j],f[j-v[i]]+w[i]);
//     cout<<f[m]<<endl;
//     return 0;
// }

//多重背包普通
// int cnt,w[N],v[N],f[N];
// int main(){
//     cnt=0;
//     int n,m;
//     cin>>n>>m;
//     while(n--){
//         int x,y,z;
//         cin>>x>>y>>z;
//         while(z--){//多重拆01
//             v[++cnt]=x;
//             w[cnt]=y;
//         }
//     }
//     for(int i=1;i<=cnt;i++)
//         for(int j=m;j>=v[i];j--)
//             f[j]=max(f[j],f[j-v[i]]+w[i]);
//     cout<<f[m]<<endl;
//     return 0;
// }

//二进制优化多重背包
// int v[N],w[N],f[M];
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int cnt=1;
//     for(int i=1;i<=n;i++){
//         int a,b,s;
//         cin>>a>>b>>s;
//         int k=1;
//         while(k<=s){
//             v[cnt]=a*k;
//             w[cnt]=b*k;
//             s-=k;
//             k*=2;
//             cnt++;
//         }
//         if(s>0){
//             v[cnt]=s*a;
//             w[cnt]=s*b;
//             cnt++;
//         }
//     }
//     for(int i=1;i<=cnt;i++)
//         for(int j=m;j>=v[i];j--)
//             f[j]=max(f[j],f[j-v[i]]+w[i]);
//     cout<<f[m]<<endl;
//     return 0;
// }

//分组背包
// int f[N],v[N],w[N];
// int main(){
//     int n,V;
//     cin>>n>>V;
//     int s;
//     for(int i=1;i<=n;i++){
//         cin>>s;
//         for(int k=1;k<=s;k++)
//             cin>>v[k]>>w[k];
//         for(int j=V;j>=0;j--)
//             for(int k=1;k<=s;k++)
//                 if(j>=v[k])
//                     f[j]=max(f[j],f[j-v[k]]+w[k]);
//     }
//     cout<<f[V]<<endl;
//     return 0;
// }

//计数dp
// const int N = 1e3+7,mod = 1e9 + 7;
// int f[N];
// int main(){
//     int n;
//     cin>>n;
//     f[0]=1;
//     for(int i=1;i<=n;i++){
//         for(int j=i;j<=n;j++)
//             f[j]=(f[j]+f[j-i])%mod;
//     }
//     cout<<f[n]<<endl;
//     return 0;
// }

//区间合并
// const int N = 307;
// int s[N],f[N][N];
// int main(){
//      int n;
//      cin>>n;
//      for(int i=1;i<=n;i++){
//         cin>>s[i];
//         s[i]+=s[i-1];
//      }
//      for(int i=n;i>=1;i--)
//         for(int j=i;j<=n;j++){
//             if(j==i){
//                 f[i][j]=0;
//                 continue;
//             }
//             f[i][j]=1e9;
//             for(int k=i;k<j;k++)
//                 f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
//         }
//     cout<<f[1][n]<<endl;
//     return 0;
// }
//数位统计dp
// const int N = 1e2;
// int base[N],f[N][N],g[N][N];
// void init(){
//     base[0]=1;
//     for(int i =1;i<=N;i++){
//         base[i]=base[i-1]*10;
//     }
//     for(int i=0;i<=N;i++)
//         f[1][i]=1;
//     for(int i=2;i<=N;i++)
//         for(int j=0;j<=N;j++)
//             f[i][j]=f[i-1][j]*10+base[i-1];
//     for(int i=1;i<=N;i++)
//         g[1][i]=1;
//     for(int i=2;i<=N;i++){
//         g[i][0]=g[i-1][0]+f[i-1][0]*9;
//         for(int j=1;j<=N;j++)
//             g[i][j]=g[i-1][j]+f[i-1][j]*9+base[i-1];
//     }
// }
// vector<int>dp(int n){
//     vector<int> ans(N,0);
//     if(n<=0)
//         return ans;
//     vector<int>nums;
//     while(n){
//         nums.push_back(n%10);
//         n/=10;
//     }
//     vector<int>last(10,0);
//     for(int i=0;i<=N;i++)
//         ans[i]=g[nums.size()-1][i];
//     for(int i=nums.size()-1;i>=0;i--){
//         int x = nums[i];
//         for(int j=i==nums.size()-1;j<x;j++){
//             for(int k=0;k<=N;k++)
//                 ans[k]+=last[k]*base[i];
//             ans[j]+=base[i];
//             for(int k=0;k<=N;k++)
//                 ans[k]+=f[i][k];
//         }
//         last[x]++;
//         if(!i)
//             for(int k=0;k<=N;k++)
//                 ans[k]+=last[k];
//     }
//     return ans;
// }
// vector<int> ask(int a,int b){
//     auto x = dp(b);
//     auto y = dp(a-1);
//     vector<int> ans;
//     for(int i=0;i<=N;i++)
//         ans.push_back(x[i]-y[i]);
//     return ans;
// }
// void print(vector<int>ans){
//     for(int i=0;i<=9;i++)
//         printf("%d ",ans[i]);
//     puts("");
// }
// int main(){
//     init();
//     int a,b;
//     while(cin>>a>>b,a||b){
//         if(a>b)
//             swap(a,b);
//         auto t = ask(a,b);
//         print(t);
//     }
//     return 0;
// }

//最短Hamilton路径
// const int N = 2e1,M=1<<N;
// int f[M][N],w[N][N];
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             cin>>w[i][j];
//     memset(f,0x3f,sizeof f);
//     f[1][0]=0;
//     for(int i=0;i<1<<n;i++)
//         for(int j=0;j<n;j++)
//             if(i>>j&1)
//                 for(int k=0;k<n;k++)
//                     if(i>>k&1)
//                         f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
//     cout<<f[(1<<n)-1][n-1]<<endl;
//     return 0;
// }

//树形DP
// const int N = 6e3+10;
// int n,happy[N],f[N][2];
// int e[N],ne[N],h[N],idx;
// bool has_Father[N];
// void add(int a,int b){
//     e[idx]=b;
//     ne[idx]=h[a];
//     h[a]=idx++;
// }
// void dfs(int u){
//     f[u][1]=happy[u];
//     for(int i=h[u];~i;i=ne[i]){
//         int j=e[i];
//         dfs(j);
//         f[u][0]+=max(f[j][1],f[j][0]);
//         f[u][1]+=f[j][0];
//     }
// }
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>happy[i];
//     memset(h,-1,sizeof h);
//     for(int i=1;i<n;i++){
//         int a,b;
//         cin>>a>>b;
//         has_Father[a]=true;
//         add(b,a);
//     }
//     int root=1;
//     while(has_Father[root])
//         root++;
//     dfs(root);
//     cout<<max(f[root][0],f[root][1])<<endl;
//     return 0;
// }

//记忆化搜索
// const int N = 310;
// int n,m;
// int f[N][N],h[N][N];
// int dx[4]={-1,0,1,0};
// int dy[4]={0,1,0,-1};
// int dp(int x,int y){
//     int &v = f[x][y];
//     if(v!=-1)
//         return v;
//     v=1;
//     for(int i=0;i<4;i++){
//         int xx = x+dx[i];
//         int yy = y+dy[i];
//         if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&h[x][y]>h[xx][yy])
//             v = max(v,dp(xx,yy)+1);
//     }
//     return v;
// }
// int main(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             cin>>h[i][j];
//     memset(f,-1,sizeof f);
//     int res = 0;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             res = max(res,dp(i,j));
//     cout<<res<<endl;
//     return 0;
// }

//覆盖区块
// const int N = 12,M = 1<<N;
// long long f [N][M];
// bool st[M];
// int n,m;
// int main(){
//     while(cin>>n>>m,n||m){
//         for(int i = 0;i<1<<n;i++){
//             st[i]=true;
//             int cnt = 0;
//             for(int j=0;j<n;j++){
//                 if(i>>j&1){
//                     if(cnt&1){
//                         st[i]=false;
//                         break;
//                     }
//                 }else cnt++;
//             }
//             if(cnt&1)
//                 st[i] = false;
//         }
//         memset(f,0,sizeof f);
//         f[0][0]=1;
//         for(int i = 1;i<=m;i++)
//             for(int j=0;j<1<<n;j++)
//                 for(int k = 0; k<1<<n;k++)
//                     if((j&k)==0&&st[j|k])
//                         f[i][j]+=f[i-1][k];
//         cout<<f[m][0]<<endl;
//     }
//     return 0;
// }