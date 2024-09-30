#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[105][105] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (i == 0 && j > 0) {
                arr[i][j] += arr[i][j - 1];
            } else if (j == 0 && i > 0) {
                arr[i][j] += arr[i - 1][j];
            } else if (i != 0 && j != 0) {
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
    }
    int sum = arr[n - 1][m - 1];
    int minv = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (abs(sum - 2 * arr[i][m - 1]) < minv) minv = abs(sum - 2 * arr[i][m - 1]);
    }
    for (int i = 0; i < m - 1; i++) {
        if (abs(sum - 2 * arr[n - 1][i]) < minv) minv = abs(sum - 2 * arr[n - 1][i]);
    }
    cout << minv << endl;
    return 0;
}
