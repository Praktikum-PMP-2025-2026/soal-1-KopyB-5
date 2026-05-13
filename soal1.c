/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Luis Matthew Sembiring (13224053)
 *   Nama File           : soal.c
 *   Deskripsi           : Menerima input string sebanyak N dan menghitung banyaknya leksikografis yang dapat dibuat
 *
 */

#include <stdio.h>
#include <string.h>

void generatekurung(int n, int buka, int tutup, char s[], int idx) {
    if (idx == 2 * n) {
        s[idx] = '\0';
        printf("%s\n", s);
        return;   
    }
    if (buka < n) {
        s[idx] = '(';
        generatekurung(n, buka + 1, tutup, s, idx + 1);
    }
    if (tutup < buka) {
        s[idx] = ')';
        generatekurung(n, buka, tutup + 1, s, idx + 1);
    }
}

// Reference kode catalan: https://www.tutorialspoint.com/article/c-program-for-nth-catalan-number 
// Catalan itu buat menghitung number valid paranthesis expression (https://www.geeksforgeeks.org/dsa/find-number-valid-parentheses-expressions-given-length/)
int catalan(int n) {    
    if (n <= 1) 
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[50]; 
    generatekurung(n, 0, 0, s, 0);
    printf("TOTAL %d", catalan(n));
    return 0;
}
