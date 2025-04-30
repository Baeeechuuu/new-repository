#include <stdio.h>

int findK(int arr[], int n) {
    int k = 1;
    // Mencari k yang memenuhi syarat
    while (k < n) {
        int valid = 1;
        // Cek Ai > Ai+1 untuk i < k
        for (int i = 0; i < k; i++) {
            if (i + 1 < n && arr[i] <= arr[i + 1]) {
                valid = 0;
                break;
            }
        }
        // Cek Ai < Ai+1 untuk i >= k
        for (int i = k; i < n; i++) {
            if (i + 1 < n && arr[i] >= arr[i + 1]) {
                valid = 0;
                break;
            }
        }
        if (valid) return k;
        k++;
    }
    return -1;
}

int countSwaps(int arr[], int n) {
    int swaps = 0;
    int temp[300001];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    
    // Sort descending sampai k
    int k = findK(arr, n);
    if (k == -1) return 0;  // Sudah memenuhi syarat
    
    // Counting swaps dengan bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((j < k-1 && temp[j] < temp[j+1]) || 
                (j >= k-1 && temp[j] > temp[j+1])) {
                // Swap
                int t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
                swaps++;
            }
        }
    }
    
    return swaps;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[300001];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d\n", countSwaps(arr, N));
    
    return 0;
}