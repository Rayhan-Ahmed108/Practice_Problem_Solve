#include<iostream>
using namespace std;
int main(){
    int lo = 1, hi = 1000000, ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        cout << mid << '\n';
        cout << flush;
        string s;
        cin >> s;
        if(s == "<"){
            hi = mid-1;
        }
        else{
            ans = max(ans, mid);
            lo = mid + 1;
        }
    }
    cout << "! " << ans ;
    cout << flush;


}