#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 // Mendefinisikan maksimal karakternya

// Definisi stack
typedef struct {
    char data[MAX_SIZE]; // Mendefinisikan char data dengan maks 100 karakter 
    int top; // Membuat int top untuk batas atas pada struct
} Stack; // Mendefinisikan struct nya sebagai Stack

// Inisialisasi stack
void BuatStack(Stack *stack) {
    stack->top = -1; // Top memiliki nilai awal -1, menandakan bahwa stack kosong
}

// Menambahkan elemen pada stack
void push(Stack *stack, char c) {
    // Jika stack belum penuh, elemen ditambahkan pada posisi top+1, dan top diperbarui
    if (stack->top < MAX_SIZE-1) {
        stack->top++;
        stack->data[stack->top] = c;
    }
    // Jika stack penuh, pesan "Stack Penuh" dicetak
    else {
        printf("Stack Penuh\n");
    }
}

// Menghapus elemen pada stack
char pop(Stack *stack) {
    char c = '\0';
    // Jika stack tidak kosong, elemen pada posisi top diambil
    // Kemudian top dikurangi, dan elemen tersebut dikembalikan
    if (stack->top >= 0) {
        c = stack->data[stack->top];
        stack->top--;
    }
    // Jika stack kosong, pesan "Stack Kosong" dicetak
    else {
        printf("Stack Kosong\n");
    }
    return c; // Kembalikan nilai c
}

// Membaca kalimat dari pengguna dan mengubah menjadi lowercase
void bacaKalimat(char *kalimat) {
    printf("Masukkan kalimat: ");
    fgets(kalimat, MAX_SIZE, stdin); // Kalimat yang dibaca disimpan dalam array
    kalimat[strcspn(kalimat, "\n")] = '\0'; // Menghilangkan karakter newline (\n) yang ditambahkan oleh fgets
    for (int i = 0; i < strlen(kalimat); i++) {
        kalimat[i] = tolower(kalimat[i]); // Mengubah semua karakter menjadi huruf kecil
    }
}

// Memeriksa apakah kalimat merupakan palindrom atau tidak
int JikaPalindrome(char *kalimat) {
    Stack value;
    BuatStack(&value);
    // Menambahkan karakter pada stack
    for (int i = 0; i < strlen(kalimat); i++) {
        push(&value, kalimat[i]); // Setiap karakter dalam kalimat ditambahkan ke dalam stack
    }
    // Membalikkan kalimat
    for (int i = 0; i < strlen(kalimat); i++) {
        if (pop(&value) != kalimat[i]) { // Kalimat dibalik dengan mengambil karakter dari stack
            return 0;
        }
    }
    return 1; // Mengembalikan nilai 1
}

// Program Utama
int main() {
    char kalimat[MAX_SIZE]; // Mendefinisikan char kalimat dengan batasan 100 karakter
    bacaKalimat(kalimat); // Untuk membaca kalimat 
    if (JikaPalindrome(kalimat)) { // Memeriksa apakah kalimat merupakan palindrom atau tidak
        // Jika Benar, cetak ini
        printf("Kata %s merupakan kata palindrom\n", kalimat);
    }
    else {
        // Jika Salah, cetak ini
        printf("Kata %s bukan kata palindrom\n", kalimat);
    }
    return 0; // Program Selesai
}
