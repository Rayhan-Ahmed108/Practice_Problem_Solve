#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        if (N == 0) {
            if (M == 1) {
                cout << ">";
            } else {
                cout << ">";
                for (int i = 0; i < M - 2; i++) {
                    cout << "<>";
                }
                cout << "=>";
            }
        } else if (M == 0) {
            if (N == 1) {
                cout << "<";
            } else {
                for (int i = 0; i < 2 * N - 3; i++) {
                    cout << "<";
                }
                cout << "=";
                cout << "<";
            }
        } else {
            for (int i = 0; i < 2 * N; i++) {
                cout << "<";
            }
            cout << ">";
            for (int i = 0; i < M - 1; i++) {
                cout << "<>";
            }
        }
        cout << '\n';
    }
    return 0;
}