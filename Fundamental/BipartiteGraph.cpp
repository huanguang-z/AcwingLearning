// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;

//染色法判断二分图
// // const int N = 2e5+10;
// // int e[N],ne[N],idx;
// // int h[N];
// // int color[N];
// // int n,m;
// // void add(int a,int b){
// //     e[idx] = b;
// //     ne[idx]=h[a];
// //     h[a]=idx++;
// // }

// // bool dfs(int u,int c){
// //     color[u]=c;
// //     for(int i = h[u];i!=-1;i=ne[i]){
// //         int b = e[i];
// //         if(!color[b]){
// //             if(!dfs(b,3-c))
// //                 return false;
// //         }
// //         else if(color[b]&&color[b]!=3-c){
// //             return false;
// //         }
// //     }
// //     return true;
// // }
// // int main(){
// //     memset(h,-1,sizeof h);
// //     cin>>n>>m;
// //     for(int i=1;i<=m;i++){
// //         int a,b;
// //         cin>>a>>b;
// //         add(a,b);
// //         add(b,a);
// //     }
// //     for(int i=1;i<=n;i++){
// //         if(!color[i])
// //             if(!dfs(i,1)){
// //                 cout<<"No"<<endl;
// //                 return 0;
// //             }
// //     }
// //     cout<<"Yes"<<endl;
// //     return 0;
// // }


//匈牙利算法求二分图最大匹配
// const int N = 1e5+10;
// int n1,n2,m;
// int h[N],e[N],ne[N];
// int st[N],match[N];
// int idx=0;
// void add(int a,int b){
//     e[idx]=b;
//     ne[idx]=h[a];
//     h[a]=idx++;
// }

// bool find(int x){
//     for(int i = h[x];i!=-1;i=ne[i]){
//         int b = e[i];
//         if(!st[b]){
//             st[b]=1;
//             if(match[b]==0||find(match[b])){
//                 match[b]=x;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     memset(h,-1,sizeof h);
//     cin>>n1>>n2>>m;
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         add(a,b);
//     }
//     int res=0;
//     for(int i=1;i<=n1;i++){
//         memset(st,0,sizeof st);
//         if(find(i))
//             res++;
//     }
//     cout<<res;
//     return 0;
// }

