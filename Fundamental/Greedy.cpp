#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

//不相交区间个数
// typedef pair<int,int> PII;
// const int N = 1e5+5;
// PII s[N];
// int main(){
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>s[i].first>>s[i].second;
//     sort(s+1,s+1+n);
//     int ans =1,maxR = s[1].second;
//     for(int i=2;i<=n;i++){
//         if(s[i].first<=maxR)
//             maxR = min(maxR,s[i].second);
//         else{
//             ans++;
//             maxR = s[i].second;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

//区间覆盖
// const int N = 1e5+10;
// int n;
// struct Range
// {
//     int l,r;
//     bool operator < (const Range &W) const{
//         return l < W.l;
//     }
// }range[N];
// int main(){
//     int st,ed;
//     cin>>st>>ed>>n;
//     for(int i=0;i<n;i++){
//         int l,r;
//         cin>>l>>r;
//         range[i] = {l,r};
//     }
//     sort(range,range+n);
//     int res = 0;
//     bool success = false;
//     for(int i=0;i<n;i++){
//         int j = i;
//         int r = -2e9;
//         while(j<n&&range[j].l<=st){
//             r = max(r,range[j].r);
//             j++;
//         }
//         if(r<st){
//             res = -1;
//             break;
//         }
//         res++;
//         if(r>=ed){
//             success = true;
//             break;
//         }
//         st = r;
//         i = j - 1;
//     }
//     if (!success)
//         res = -1;
//     cout<<res<<endl;
//     return 0;
// }




