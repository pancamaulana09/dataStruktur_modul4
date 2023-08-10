#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definisi stack
typedef struct {
    int top; // Membuat int top untuk batas atas pada struct
    char data[100]; // Mendefinisikan char data dengan maks 100 karakter 
} Stack; // Mendefinisikan struct nya sebagai Stack

// Menambahkan elemen pada stack
void push(Stack* stack, char item) {
    stack->data[++stack->top] = item; // Elemen ditambahkan ke posisi top+1 dalam array data
}

// Menghapus elemen pada stack
char pop(Stack* stack) {
    if (stack->top == -1) // Jika stack kosong
        return '\0'; // Akan mengembalikan karakter null 
    return stack->data[stack->top--];
}

// Digunakan untuk memeriksa apakah karakter merupakan operator
int Operator(char karakter) {
    // Jika iya, fungsi mengembalikan nilai 1
    return (karakter == '+' || karakter == '-' || karakter == '*' || 
            karakter == '/' || karakter == '^');
}

// Untuk mendapatkan tingkat prioritas suatu operator
int Prioritas(char karakter) {
    // Operator dengan prioritas yang lebih tinggi akan memiliki nilai yang lebih besar
    switch (karakter) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return 0;
}

// Fungsi utama yang melakukan konversi dari notasi infix ke notasi postfix
void infixKePostfix(char* infix, char* postfix) {
    // Fungsi menggunakan stack untuk memproses notasi infix
    Stack stack;
    stack.top = -1; // menandakan bahwa stack kosong
    int i, j; // Deklarasi variabel untuk looping
    char karakter; // Untuk variabel karakternya

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        karakter = infix[i];

        // Jika karakter adalah huruf atau angka
        if (isalpha(karakter) || isdigit(karakter)) {
            postfix[j++] = karakter; // Maka karakter tersebut langsung ditambahkan ke postfix
        } else if (karakter == '(') { // Jika karakter adalah kurung buka
            push(&stack, karakter); // Maka karakter tersebut ditambahkan ke stack
        } else if (karakter == ')') { // Jika karakter adalah kurung tutup
            while (stack.top != -1 && stack.data[stack.top] != '(')
                postfix[j++] = pop(&stack); 
                // Maka karakter di-pop dan ditambahkan ke postfix hingga ditemukan kurung buka yang sesuai
            if (stack.top != -1 && stack.data[stack.top] != '(') { // Jika tidak ditemukan kurung buka
                // Maka notasi infix tidak valid dan program keluar dengan pesan kesalahan
                printf("Invalid infix expression!\n");
                exit(1);
            } else {
                pop(&stack); // Jika tidak, akan ditambahkan ke stack
            }
        } else if (Operator(karakter)) { // Jika karakter adalah operator
            // Maka karakter dalam stack yang memiliki prioritas lebih tinggi atau sama dengan karakter saat ini, 
            while (stack.top != -1 && Prioritas(karakter) <= Prioritas(stack.data[stack.top]))
                postfix[j++] = pop(&stack);  // // Maka akan di-pop dan ditambahkan ke string postfix
            push(&stack, karakter); // Kemudian, karakter saat ini ditambahkan ke stack
        }
    }

    // Setelah selesai memproses semua karakter dalam infix
    while (stack.top != -1)
        // Karakter-karakter yang tersisa dalam stack di-pop dan ditambahkan ke string postfix
        postfix[j++] = pop(&stack);

    postfix[j] = '\0';
}

int main() {
    // Mendefinisikan infinix dan postfix nya
    char infix[100], postfix[100];
    printf("Masukkan notasi infix: "); // Cetak kalimat perintah
    scanf("%[^\n]s", infix); // Simpan, dan tampilkan karakter

    infixKePostfix(infix, postfix); // Program memanggil fungsi infinix ke postfix

    // Program mencetak hasil konversi notasi postfix ke layar
    printf("Notasi postfix: %s\n", postfix);

    return 0; // Program selesai
}
