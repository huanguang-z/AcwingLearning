#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
typedef pair<int,int> PI;
//基础LIS
// const int N = 1e2+10;
// int k,n,w[N],Up[N],Down[N];
// int main(){
//     cin>>k;
//     while(k--){
//         memset(Up,0,sizeof Up);
//         memset(Down,0,sizeof Down);
//         cin>>n;
//         for(int i=1;i<=n;i++)
//             cin>>w[i];
//         w[0]=0;
//         for(int i=1;i<=n;i++)
//             for(int j=0;j<i;j++)
//                 if(w[i]>w[j])
//                     Up[i]=max(Up[i],Up[j]+1);
//         w[n+1]=0;
//         for(int i=n;i;i--)
//             for(int j=n+1;j>i;j--)
//                 if(w[i]>w[j])
//                     Down[i]=max(Down[i],Down[j]+1);
//         int res=0;
//         for(int i=1;i<=n;i++)
//             res = max(res,max(Up[i],Down[i]));
//         cout<<res<<endl;
//     }
//     return 0;
// }

//先增后减LIS+状态机
// const int N = 1e3+10;
// int n,High[N],f[N][2];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>High[i];
//     for(int i=1;i<=n;i++){
//         f[i][0]=f[i][1]=1;
//         for(int k = 1;k<i;k++){
//             if(High[k]<High[i])
//                 f[i][0]=max(f[i][0],f[k][0]+1);
//             if(High[k]>High[i])
//                 f[i][1]=max(f[i][1],max(f[k][0],f[k][1])+1);
//         }
//     }
//     int res = 0;
//     for(int i=1;i<=n;i++)
//         res = max(res,max(f[i][0],f[i][1]));
//     cout<<res<<endl;
//     return 0;
// }

//先增后减LIS+DP
// const int N = 1e2+10;
// int n,High[N],Up[N],Down[N];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>High[i];
//     High[0]=0;
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<i;j++)
//             if(High[i]>High[j])
//                 Up[i]=max(Up[i],Up[j]+1);
//     High[n+1]=0;
//     for(int i=n;i;i--)
//         for(int j=n+1;j>i;j--)
//             if(High[i]>High[j])
//                 Down[i]=max(Down[i],Down[j]+1);
//     int res=0;
//     for(int i=1;i<=n;i++)
//         res = max(res,Up[i]+Down[i]-1);
//     cout<<n-res<<endl;
//     return 0;
// }

//LIS求和
// const int N = 1e3+10;
// int n,w[N],f[N];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>w[i];
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<=n;j++)
//             if(w[i]>w[j])
//                 f[i]=max(f[i],f[j]+w[i]);
//     int res = 0;
//     for(int i=1;i<=n;i++)
//         res = max(res,f[i]);
//     cout<<res<<endl;
//     return 0;
// }

//最大同行不相交线段
// const int N = 5e4+10;
// int n,f[N];
// PI p[N];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>p[i].first>>p[i].second;
//     sort(p+1,p+n+1);
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<i;j++)
//             if(p[j].second<p[i].second)
//                 f[i] = max(f[i],f[j]+1);
//     int res = 0;
//     for(int i=1;i<=n;i++)
//         res  =max(res,f[i]);
//     cout<<res<<endl;
//     return 0;
// }

//多个LIS覆盖数组
// const int N = 1e3+10,INF = 0x3f3f3f3f;
// int n,x,w[N],f[N],q[N],cnt;
// int main(){
//     n=0;
//     while(cin>>x)
//         w[++n]=x;
//     int res = 0;
//     w[0]=INF;
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<i;j++)
//             if(w[j]>=w[i])
//                 f[i]=max(f[i],f[j]+1);
//         res = max(res,f[i]);
//     }
//     for(int i=1;i<=n;i++){
//         int l=0,r=cnt;
//         while(l<r){
//             int mid = l+r >>1;
//             if(q[mid]>=w[i])
//                 r = mid;
//             else
//                 l = mid + 1;
//         }
//         if(q[r]<w[i])
//             r++;
//         cnt = max(cnt,r);
//         q[r]=w[i];
//     }
//     cout<<res<<endl<<cnt<<endl;
//     return 0;
// }

//多个增和减LIS覆盖数组
// const int N = 55;
// int n,w[N],Up[N],Down[N];
// bool dfs(int u, int Usum, int Dsum, int Maxdepth){
//     if(Usum+Dsum>Maxdepth)
//         return false;
//     if(u==n)
//         return true;
//     int k=0;
//     while(k<Usum&&Up[k]>=w[u])
//         k++;
//     int t = Up[k];
//     Up[k]=w[u];
//     if(k==Usum&&dfs(u+1,Usum+1,Dsum,Maxdepth))
//         return true;
//     else if(k<Usum&&dfs(u+1,Usum,Dsum,Maxdepth))
//         return true;
//     Up[k]=t;
//     k=0;
//     while(k<Dsum&&Down[k]<=w[u])
//         k++;
//     t = Down[k];
//     Down[k]=w[u];
//     if(k==Dsum&&dfs(u+1,Usum,Dsum+1,Maxdepth))
//         return true;
//     else if(k<Dsum&&dfs(u+1,Usum,Dsum,Maxdepth))
//         return true;
//     Down[k]=t;
//     return false;
// }
// int main(){
//     while(cin>>n,n){
//         for(int i=0;i<n;i++)
//             cin>>w[i];
//         int depth = 0;
//         while(!dfs(0,0,0,depth))
//             depth++;
//         cout<<depth<<endl;
//     }
//     return 0;
// }

//LICS，最长公共上升子序列
// const int N = 3e3+10;
// int n,S1[N],S2[N],f[N][N];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>S1[i];
//     for(int i=1;i<=n;i++)
//         cin>>S2[i];
//     for(int i=1;i<=n;i++){
//         int maxv = 1;
//         for(int j = 1;j<=n;j++){
//             f[i][j] = f[i-1][j];
//             if(S2[j]==S1[i])
//                 f[i][j]=max(f[i][j],maxv);
//             if(S2[j]<S1[i])
//                 maxv = max(maxv,f[i-1][j]+1);
//         }
//     }
//     int res = 0;
//     for(int i=0;i<=n;i++)
//         res = max(res,f[n][i]);
//     cout<<res<<endl;
//     return 0;
// }