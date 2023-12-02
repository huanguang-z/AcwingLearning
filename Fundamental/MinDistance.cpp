#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// const int N=510,M=1e4+10;
// struct Edge{
//     int a;
//     int b;
//     int w;
// }e[M];
// int dist[N];
// int back[N];
// int n,m,k;
// void BellmanFord(){
//     memset(dist,0x3f,sizeof dist);
//     dist[1]=0;
//     for(int i=0;i<k;i++){
//         memcpy(back,dist,sizeof dist);
//         for(int j=0;j<m;j++){
//             int a = e[j].a;
//             int b = e[j].b;
//             int w = e[j].w;
//             dist[b] = min(dist[b],back[a]+w);
//         }
//     }
// }

// int main(void){
//     cin>>n>>m>>k;
//     for(int i=0;i<m;i++){
//         int a,b,w;
//         cin>>a>>b>>w;
//         e[i].a=a;
//         e[i].b=b;
//         e[i].w=w;
//     }
//     BellmanFord();
//     if(dist[n]>0x3f3f3f3f/2)
//         cout<<"impossible";
//     else   
//         cout<<dist[n];
//     return 0;
// }

// const int INF = 0x3f3f3f3f;
// int n,m;
// const int N = 1e5+10;
// int h[N],e[N],w[N],ne[N],idx;
// int dist[N],cnt[N];
// bool st[N];

// void add(int a,int b, int c){
//     e[idx]=b;
//     w[idx]=c;
//     ne[idx]=h[a];
//     h[a]=idx++;
// }

// int spfa(){
//     queue<int>q;
//     for(int i=1;i<=n;i++){
//         q.push(i);
//         st[i]=true;
//     }
//     while(q.size()){
//         auto t = q.front();
//         q.pop();
//         st[t]=false;

//         for(int i= h[t];i!=-1;i=ne[i]){
//             int j = e[i];
//             if(dist[j]>dist[t]+w[i]){
//                 dist[j] = dist[t]+w[i];
//                 cnt[j] = cnt[t]+1;
//                 if(cnt[j]>=n)
//                     return true;
//                 if(!st[j]){
//                     q.push(j);
//                     st[j]=true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     cin>>n>>m;
//     memset(h,-1,sizeof h);
//     for(int i = 0;i<m;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         add(a,b,c);
//     }
//     if(spfa())
//         cout<<"Yes";
//     else
//         cout<<"No";
//     return 0;
// }
