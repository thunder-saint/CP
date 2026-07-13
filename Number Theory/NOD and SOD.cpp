const int N = 1e7 + 1;
int32_t nod[N + 1], cnt[N + 1], spf[N + 1];
int32_t sod[N + 1], pw[N + 1], sumPow[N + 1];
int8_t omega[N + 1], bigOmega[N + 1];
vector <int> primes;
void nod_sod() {
    nod[1] = sod[1] = 1;
    pw[1] = sumPow[1] = 1;
    omega[1] = bigOmega[1] = 0;
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
            cnt[i] = 1, nod[i] = 2;
            pw[i] = i, sumPow[i] = 1 + i;
            sod[i] = 1 + i;
            omega[i] = bigOmega[i] = 1;
        }
        for (int p : primes) {
            int x = i * p;
            if (x >= N || p > spf[i]) break;
            spf[x] = p;
            if (i % p == 0) {
                cnt[x] = cnt[i] + 1;
                nod[x] = nod[i] / (cnt[i] + 1) * (cnt[x] + 1);
                pw[x] = pw[i] * p;
                sumPow[x] = sumPow[i] + pw[x];
                sod[x] = sod[i] / sumPow[i] * sumPow[x];
                omega[x] = omega[i];
                bigOmega[x] = bigOmega[i] + 1;
                break;
            } else {
                cnt[x] = 1;
                nod[x] = nod[i] * 2;
                pw[x] = p;
                sumPow[x] = 1 + p;
                sod[x] = sod[i] * sumPow[x];
                omega[x] = omega[i] + 1;
                bigOmega[x] = bigOmega[i] + 1;
            }
        }
    }
}
