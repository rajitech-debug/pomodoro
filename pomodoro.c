#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Gunakan unistd.h untuk Linux/macOS dan windows.h untuk Windows
#ifdef _WIN32
#include <windows.h>
#else
#endif

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk menampilkan waktu dalam format MM:SS
void tampilkanWaktu(int totalDetik) {
    int menit = totalDetik / 60;
    int detik = totalDetik % 60;
    printf("%02d:%02d\n", menit, detik);
}

// Fungsi jeda (sleep) yang kompatibel lintas platform
void jeda(int detik) {
#ifdef _WIN32
    Sleep(detik * 1000); // Sleep dalam milidetik
#else
    sleep(detik);        // sleep dalam detik
#endif
}

int main() {
    int sesiKerja = 25 * 60;   // 25 menit dalam detik
    int sesiIstirahat = 5 * 60; // 5 menit dalam detik

    printf("Tekan Ctrl+C untuk berhenti.\n");
    jeda(2); // Jeda sejenak sebelum memulai

    while (1) {
        // --- SESI KERJA ---
        printf("--- WAKTU KERJA ---\n");
        for (int i = sesiKerja; i > 0; i--) {
            clearScreen();
            printf("FOKUS! Sisa waktu kerja:\n");
            tampilkanWaktu(i);
            jeda(1);
        }
        clearScreen();
        printf("🎉 Waktu kerja selesai! Saatnya istirahat.\n");
        jeda(3);

        // --- SESI ISTIRAHAT ---
        printf("--- WAKTU ISTIRAHAT ---\n");
        for (int i = sesiIstirahat; i > 0; i--) {
            clearScreen();
            printf("SANTAI! Sisa waktu istirahat:\n");
            tampilkanWaktu(i);
            jeda(1);
        }
        clearScreen();
        printf("🧘 Waktu istirahat selesai! Siap-siap untuk sesi berikutnya.\n");
        jeda(3);
    }

    return 0;
}