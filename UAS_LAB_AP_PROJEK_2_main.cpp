#include <iostream>
#include "TebakKata.h" 

using namespace std;

int main() {
    srand(time(0)); 

    PlayerScore leaderboard[5]; 
    int totalPemainPapanSkor = 0;
    char mainLagi;

    do {
        bersihkanLayar();
        KataGame gameSession;
        int pilihanKesulitan;

        cout << "++++++++++++++++++++++++++++++++++++++\n";
        cout << "   Irasshaimase Di Game Tebak  Kata, Desu  \n";
        cout << "--------------------------------------\n";
        cout << "Gomenasai, Sebelum Lanjut silahkan pilih Tingkat Kesulitan nya Koujojishama:\n";
        cout << "1. Easy   (8 Nyawa)\n";
        cout << "2. Medium (6 Nyawa)\n";
        cout << "3. Hard   (4 Nyawa)\n";
        cout << "Masukkan pilihan nya Koujojisama (1/2/3): ";
        cin >> pilihanKesulitan;

        while(pilihanKesulitan < 1 || pilihanKesulitan > 3) {
            cout << "Summimasen Koujojisama, Pilihan nya tidak valid! Masukkan ulang angka yang benar Koujojisama(1/2/3): ";
            cin >> pilihanKesulitan;
        }

        inisialisasiGame(&gameSession, pilihanKesulitan);

        bool sedangBermain = true;

        while (sedangBermain) {
            bersihkanLayar();
            tampilkanInfoLayar(&gameSession);

            cout << "Ketik ini: '?' untuk Hint nya ya Koujojisama (Biaya 1 nyawa)\n";
            cout << "Masukkan tebakan huruf, Koujojisama: ";
            string inputStr;
            cin >> inputStr;

            char tebakan = inputStr[0];

            if (tebakan == '?') {
                gunakanHint(&gameSession);
            } else {
                prosesTebakan(&gameSession, tebakan);
            }

            cout << "Tekan Enter untuk melanjutkan, Koujojisama...";
            cin.ignore();
            cin.get();

            if (gameSession.sisaNyawa == 0) {
                bersihkanLayar();
                cout << "\n------------------------------------\n";
                cout << "             ~K.O~ GAME OVER, Koujojisama!               \n";
                cout << "   Nyawa Anda habis, Koujojisama. Kata aslinya:    \n";
                cout << "             " << gameSession.kataAsli << "\n";
                cout << "+++++++++++++++++++++++++++++++++++++++\n";
                sedangBermain = false;
            } 
            else if (gameSession.statusTebakan == gameSession.kataAsli) {
                bersihkanLayar();
                cout << "\n======================================\n";
                cout << "     Omedeto! ANDA MENANG, Koujojisama!            \n";
                cout << "   Kata berhasil ditebak: " << gameSession.kataAsli << "\n";
                cout << "======================================\n";
                
                int pengaliSkor = (pilihanKesulitan == 3) ? 30 : (pilihanKesulitan == 2) ? 20 : 10;
                int skorAkhir = gameSession.sisaNyawa * pengaliSkor;
                cout << "Skor Anda: " << skorAkhir << "\n\n";

                string namaPemain;
                cout << "Masukkan Namae wa Koujojisama untuk Leaderboard: ";
                getline(cin >> ws, namaPemain); 

                updateLeaderboard(leaderboard, totalPemainPapanSkor, namaPemain, skorAkhir);
                sedangBermain = false;
            }
        }

        tampilkanLeaderboard(leaderboard, totalPemainPapanSkor);

        cout << "\nApakah Anda ingin bermain lagi, Koujojisama? (Y/N): ";
        cin >> mainLagi;

    } while (toupper(mainLagi) == 'Y');

    cout << "\nArigatou Gozaimashu, Koujojisama telah bermain!\n";

    return 0;
}
