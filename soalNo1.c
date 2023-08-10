#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan ukuran stact dengan max nilai 100
#define MAX_SIZE 100 

int disk[MAX_SIZE]; // Mendeklarasikan array disk yang akan digunakan untuk menyimpan nomor disk
int top = -1; // Mendeklarasikan variabel top sebagai indeks teratas dari stack dengan nilai -1 (stact awalnya kosong)

// Fungsi untuk memasukkan data ke dalam stack
void push(int data) {
    if (top == MAX_SIZE - 1) { // Jika stack penuh
        printf("Stact Penuh\n"); // Maka akan ditampilkan pesan "Stack Penuh"
    }
    else {
        top++; // Jika tidak
        disk[top] = data; // top akan diinkremen dan "data" akan dimasukkan ke dalam disk[top]
    }
}

// Fungsi untuk mengambil data dari stack
int pop() {
    if (top == 1) { // jika stack kosong 
        printf("Stact Kosong"); // Maka akan ditampilkan pesan "Stack Kosong" 
        return -1; // Fungsi akan mengembalikan nilai -1
    }
    else { // Jika tidak,
        int data = disk[top]; // nilai yang ada di "disk[top]" akan disimpan dalam variabel "data"
        top--; // "top" akan dikurangi
        return data; // dan "data" akan dikembalikan
    } 
}

// Fungsi untuk mencetak pesan pemindahan disk dari tiang x ke tiang y
void pindahDisk(char x, char y, int disk) {
    printf("Pindah disk %d dari '%c' ke '%c'\n", disk, x, y); 
}

// Fungsi rekursif untuk menyelesaikan permasalahan Tower of Hanoi
void Tower(int n, char x, char y, char z) {
    if (n == 1){ // Jika "n" sama dengan 1
        pindahDisk(x, y, 1); // Maka fungsi akan dipanggil untuk memindahkan satu disk dari tiang "x" ke tiang "y"
        return;
    }
    // Jika tidak
    // Fungsi Tower akan dipanggil secara rekursif dengan menggantikan tujuan tiang "y" menjadi tiang "z" 
    // dan bantuan tiang "z" menjadi tiang "y"
    Tower(n-1, x, z, y);
    pindahDisk(x, y, n);
    Tower(n-1, z, y, x);
}

// Program Utama
int main() {
    int n, i;

    printf("Masukkan Jumlah Disk: ");
    scanf("%d", &n); // Untuk Menginput jumlah disk
    for (i = n; i >= 1; i--) { // Loop digunakan untuk memasukkan nomor disk ke dalam stack dengan menggunakan fungsi push
        push(i);
    }

    // Pemanggilan fungsi Tower() dengan argumen n sebagai jumlah disk
    // S sebagai tiang awal, D sebagai tujuan, dan A sebagai tiang bantuan
    Tower(n, 'S', 'D', 'A');
    return 0; // Program selesai
}
