// #include<iostream>
// #include<vector>
// using namespace std;

//ADD
//
// vector<int> add(vector<int> &A,vector <int> &B){
//     if(A.size()<B.size())
//         return add(B,A);
//     vector<int> C;
//     int t=0;
//     for(int i=0;i<A.size();i++)
//     {
//         t+=A[i];
//         if(i<B.size())
//             t+=B[i];
//         C.push_back(t%10);
//         t/=10;
//     }
//     if(t)
//         C.push_back(t);
//     return C;
// }

// int main(void){
//     string a,b;
//     vector<int> A,B;
//     cin>>a>>b;
//     for(int i = a.size()-1;i>=0;i--)
//         A.push_back(a[i]-'0');
//     for (int i = b.size()-1;i>=0;i--)
//         B.push_back(b[i]-'0');
//     vector<int> C = add(A,B);
//     for (int i = C.size()-1;i>=0;i--)
//         cout<<C[i];
//     cout<<endl;
//     return 0;
// }

//Subtraction
// bool cmp(vector<int>&A, vector<int>&B){
//     if(A.size()!=B.size())
//         return A.size()>B.size();
//     for(int i = A.size()-1;i>=0;i--)
//         if(A[i]!=B[i])
//             return A[i]>B[i];
//     return true;
// }

// vector<int> sub(vector<int>&A,vector<int>&B){
//     vector<int> C;
//     int t=0;
//     for(int i=0;i<A.size();i++){
//         t=A[i]-t;
//         if(i<B.size())
//             t-=B[i];
//         C.push_back((t+10)%10);
//         if(t<0)
//             t=1;
//         else
//             t=0;
//     }
//     while(C.size()>1&&C.back()==0)
//         C.pop_back();
//     return C;
// }


// int main(void){
//     string a,b;
//     vector<int> A,B;
//     cin>>a>>b;
//     for(int i=a.size()-1;i>=0;i--)
//         A.push_back(a[i]-'0');
//     for(int i=b.size()-1;i>=0;i--)
//         B.push_back(b[i]-'0');
//     if(cmp(A,B)){
//         vector<int> C = sub(A,B);
//         for(int i=C.size()-1;i>=0;i--)
//             printf("%d",C[i]);
//         cout<<endl;
//     }else{
//         vector<int> C = sub(B,A);
//         printf("-");
//         for(int i=C.size()-1;i>=0;i--)
//             printf("%d",C[i]);
//         cout<<endl;
//     }
//     return 0;
// }

//Multiplication
// vector<int> mul(vector<int>&A,vector<int>&B){
//     vector<int>C(A.size()+B.size()+1,0);
//     for(int i = 0;i<A.size();i++)
//         for(int j=0;j<B.size();j++)
//             C[i+j]+=A[i]*B[j];//逐位乘
//     int t=0;
//     for(int i=0;i<C.size();i++){
//         t+=C[i];
//         C[i] = t%10;
//         t/=10;
//     }
//     while(C.size()>1&&C.back()==0)
//         C.pop_back();
//     return C;
// }

// int main() {
//     string a, b;
//     cin >> a >> b; 
//     vector<int> A, B;
//     for (int i = a.size() - 1; i >= 0; i--)
//         A.push_back(a[i] - '0');
//     for (int i = b.size() - 1; i >= 0; i--)
//         B.push_back(b[i] - '0');

//     auto C = mul(A, B);

//     for (int i = C.size() - 1; i >= 0; i--)
//         cout << C[i];
//     return 0;
// }

//Division

// vector<int> div(vector<int>&A, int B,int &r){
//     vector<int>C;
//     for(int i=0;i<A.size();i++){
//         r=r*10+A[i];
//         C.push_back(r/B);
//         r=r%B;
//     }
//     reverse(C.begin(),C.end());
//     while(C.size()>1&&C.back()==0)
//         C.pop_back();
//     return C;
// }

// int main(){
//     string a;
//     int B,r=0; //代表余数
//     cin>>a>>B;
//     vector<int> A;
//     for(int i=0;i<a.size();i++) A.push_back(a[i]-'0');//注意这次的A是由高为传输至低位，由于在除法的手算过程中，发现从高位进行处理
//     //for(int i=0;i<A.size();i++) cout<<A[i];
//     //cout<<B;
//     vecto C = div(A,B,r);
//     for(int i=C.size()-1;i>=0;i--) cout<<C[i];//将C从最高位传给最低位
//     cout<<endl<<r;//输出余数
//     cout<<endl;
//     return 0;
// }