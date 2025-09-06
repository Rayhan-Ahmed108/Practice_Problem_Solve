#include <bits/stdc++.h>
 
using namespace std;
const int N = 2e5 + 10, LOG_A = 31;
int basis[LOG_A];
void insertVector(int mask) {
	for (int i = LOG_A - 1; i >= 0; i--) {
		if ((mask & 1 << i) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			return;
		}
		mask ^= basis[i];
	}
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		scanf("%d", &a);
		insertVector(a);
	}
	int ans = 0;
	for (int i = LOG_A - 1; i >= 0; i--) {
		if (!basis[i]) continue;
		if (ans & 1 << i) continue;
		ans ^= basis[i];
	}
	cout << ans << endl;

	return 0;
}
