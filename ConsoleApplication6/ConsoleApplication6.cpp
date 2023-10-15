#include <iostream>
using namespace std;
int* enddiff(int mas2[], int end, int start, int diff, int sum1, int startmas[], int* n) {
    if (sum1+mas2[start] == diff && start <= end) { return &startmas[0]; }
    else if ((start == end) || (sum1+mas2[start] > diff) || (mas2[start] > diff)) { return 0; }
    else {
        int* donttake = enddiff(mas2, end, start + 1, diff, sum1, startmas, &(*n));
        startmas[start] = mas2[start];
        int* take = enddiff(mas2, end, ((start)+1), diff, sum1 + mas2[start], startmas, &(*(n + 1)));
        return take != 0 ? take : donttake;
    }
}
int* allcomb(int comb1[], int mas1[], int n, int sum, int startmas[]) {
    int teksum = 0;
    for (int i = 0; i < n; i++) { startmas[i] = 0; }
    for (int i = 0; i < n; i++) {
        teksum += mas1[i]; comb1[i] = mas1[i]; mas1[i] = 0;
        if (teksum == sum) return &comb1[0];
        else if (teksum > sum) {
            int diff = abs(teksum - sum);
            int* ptr = enddiff(comb1, i, 0, diff, 0, startmas, &(n));
            if ((*ptr != 0)) {
                while (*ptr != 0) { for (int i = 0; i < n; i++) { if (comb1[i] == *ptr) { comb1[i] = 0; break; } } for (int i = 0; i < n; i++) { if (mas1[i] = 0) { mas1[i] = *ptr; break; } } ptr += 1; }
                return &comb1[0];
            }
            else { continue; }
        }
    }
    cout << "NO";
    return NULL;
}
int main() {
    int sum, n; cin >> n; sum = (1 + n) * n / 2; const int N = 10000;
    if (sum % 2 == 0) {
        sum /= 2;
        int mas[N], comb[N], startmas[N]; for (int i = 0; i < n; i++) { mas[i] = i + 1; }
        int* first = allcomb(comb, mas, n, sum, startmas); while (*first >= 0) { cout << *(first) << " "; first++;  }
    }
    else { cout << "Error" << endl; }
    return 0;
}