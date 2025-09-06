#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], t[N*4];
int main() {
int t;
cin >> t;
while(t--) {    
int n, m;
cin >> n >> m;
vector<int>idx, pre(n+1);
for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(a[i] == m) {
        idx.push_back(i);
    }
}
pre[1] = a[1];
for(int i = 2; i <= n; i++) {
    pre[i] = pre[i-1] + a[i];
}
int sum = 0, mx = -1, count = 0, indx = 0;
for(int i = 1; i <= n; i++) {
    if(a[i] == m) {
        count++;
        if(count != 2) {
            sum += a[i];
            indx = i;
        }
        else {
            mx = max(mx, sum);
            sum = pre[i] - pre[indx];
            count = 1;
            indx = i;
        }
    }
    else {
        if(a[i] >= m) {
            sum += a[i];
        }
        else {
            if(count == 1) {
                mx = max(sum, mx);
                indx = i + 1;
                sum = 0;
                count = 0;
            }
            else {
                indx = i + 1;
                sum = 0;
                count = 0;
            }
            
        }
    }
}
mx = max(sum ,mx);
cout << mx << endl;
}
//built(1, 1, n);
}
