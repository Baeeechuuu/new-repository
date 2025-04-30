#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung hasil operasi AND pada interval
long long calculateIntervalScore(long long arr[], int l, int r) {
    long long result = arr[l];
    for(int i = l + 1; i <= r; i++) {
        result &= arr[i];
    }
    return result;
}

// Fungsi untuk menggabungkan potion dan mengatur ulang array
void fusePotions(long long arr[], int l, int r, int n) {
    long long newPotency = calculateIntervalScore(arr, l, r);
    int shift = r - l;
    
    // Menyimpan potion baru di posisi l
    arr[l] = newPotency;
    
    // Menggeser potion yang tersisa
    for(int i = r + 1; i < n; i++) {
        arr[i - shift] = arr[i];
    }
}

// Fungsi rekursif untuk mencari skor maksimum
long long findMaxScore(long long arr[], int n, long long currentScore) {
    if(n == 1) return currentScore;
    
    long long maxScore = 0;
    
    // Mencoba semua kemungkinan interval
    for(int l = 0; l < n-1; l++) {
        for(int r = l+1; r < n; r++) {
            // Membuat salinan array untuk percobaan
            long long tempArr[100001];
            for(int i = 0; i < n; i++) {
                tempArr[i] = arr[i];
            }
            
            // Menghitung skor interval
            long long intervalScore = calculateIntervalScore(tempArr, l, r);
            
            // Menggabungkan potion
            fusePotions(tempArr, l, r, n);
            
            // Rekursi dengan array yang baru
            long long score = findMaxScore(tempArr, n-(r-l), currentScore + intervalScore);
            if(score > maxScore) {
                maxScore = score;
            }
        }
    }
    
    return maxScore;
}

int main() {
    int N;
    scanf("%d", &N);
    
    long long potions[100001];
    for(int i = 0; i < N; i++) {
        scanf("%lld", &potions[i]);
    }
    
    long long result = findMaxScore(potions, N, 0);
    printf("%lld\n", result);
    
    return 0;
}