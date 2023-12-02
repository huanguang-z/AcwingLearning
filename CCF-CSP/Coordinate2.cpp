// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// const int N = 100010;
// int flag[N];
// double k[N];
// double q[N];

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++ ){
//         //scanf("%d%lf", &flag[i], &conf[i][0]);
//         double w;
//         scanf("%d%lf", &flag[i], &w);
//         k[0] = 1;
//         q[0] = 0;
//         if(flag[i] == 1) {
//             k[i] = k[i - 1] * w;
//             q[i] = q[i - 1];
//         }
//         else {
//             k[i] = k[i - 1];
//             q[i] = q[i - 1] + w;
//         }
//     }
//     for (int i = 1; i <= m; i ++ ){
//         int a, b;
//         double x, y;
//         scanf("%d%d%lf%lf", &a, &b, &x, &y);


//                 x *= k[b]/k[a - 1];
//                 y *= k[b]/k[a - 1];
//                 double dx = x*cos(q[b] - q[a - 1]) -y*sin(q[b] - q[a - 1]);
//                 double dy = x*sin(q[b] - q[a - 1]) +y*cos(q[b] - q[a - 1]);
//             x = dx;
//             y = dy;


//         printf("%lf %lf\n", x, y);
//     }

//     return 0;
// }