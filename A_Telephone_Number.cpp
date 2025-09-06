const int MOD = 1e9 + 7;
const int BASE = 31;

vector<int> hash1, power_base;

void build_hash(const string &s) {
    int n = s.size();
    hash1.assign(n + 1, 0);
    power_base.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        hash1[i] = (hash1[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD;
        power_base[i] = (power_base[i - 1] * BASE) % MOD;
    }
}

int get_hash(int l, int r) {
    int res = (hash1[r + 1] - (hash1[l] * power_base[r - l + 1]) % MOD + MOD) % MOD;
    return res;
}