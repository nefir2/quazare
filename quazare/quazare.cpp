#include <iostream>
#include <random>
using namespace std;
void vyvod(int a, double* dengi);
void br();
int main() {
    int x;
    do {
        x = 0;
        rand(); rand(); rand();
        setlocale(LC_ALL, "Russian");
        double stavka = 0, vse = 200, record = 0;
        int ans, doing;
        do {
            //ставка
            cout << "у вас всего денег: " << floor(vse) << endl;
            cout << "введите номер действия со ставкой:\n\n1.поставить все деньги (если больше 200 то ставится 200);\n2.поставить половину всех ваших денег (если больше 200 то поставится 100);\n3.поставить минимум (20);\n4.ввести свою ставку.\n";
            cin >> doing;
            while (doing > 4 || doing < 1) { cout << "можно ввести от 1 до 4!!\nдействие: "; cin >> doing; }
            if (doing == 1) { if (vse > 200) stavka = 200; else stavka = vse; }
            else if (doing == 2) {
                if (vse > 200) stavka = 100;
                else if (vse < 40) { cout << "меньше 20 ставить нельзя. ставка = 20\n"; stavka = 20; }
                else stavka = vse / 2;
            }
            else if (doing == 3) stavka = 20;
            else if (doing == 4) {
                cout << "ставка (20-200): ";
                cin >> stavka;
                while (stavka < 20 || stavka > 200 || stavka > vse) {
                    if (stavka > 200 || stavka < 20) cout << "введите от 20 до 200!!\n";
                    if (stavka > vse && stavka <= 200 && stavka >= 20) cout << "ставка не может быть больше чем количество ваших денег.\nу вас денег: " << vse << endl;
                    cout << "ставка (20-200): ";
                    cin >> stavka;
                }
            }
            vse -= stavka;
            cout << endl << "ваши деньги: " << floor(vse) << endl;
            br();
            //случайное число из автомата
            int avtomat;
            avtomat = (rand() % 12) + 1;
            cout << "автомат: " << avtomat << endl;
            //решения
            while (avtomat <= 20) {
                //варианты ответа если больше автомат выдал больше 14
                if (avtomat > 14) {
                    if (avtomat == 20) { cout << "ВЫ ПОБЕДИЛИ!\n"; vyvod(avtomat, &stavka); break; }
                    cout << "введите 1, 2 или 3\n1: добавить 1-8;\n2: добавить 4-7;\n3: забрать.\n";
                    int resh;
                    cin >> resh;
                    while (resh > 3 || resh < 1) { cout << "введите 1, 2 или 3!!!\n"; cin >> resh; }
                    if (resh == 1) { avtomat = avtomat + ((rand() % 8) + 1); cout << "автомат: " << avtomat << endl; }
                    else if (resh == 2) { avtomat = avtomat + ((rand() & 3) + 4); cout << "автомат: " << avtomat << endl; }
                    else if (resh == 3) { vyvod(avtomat, &stavka); br(); break; }
                }
                //варианты ответа если больше автомат выдал меньше 14
                else {
                    cout << "введите 1 или 2\n1: добавить 1-8;\n2: добавить 4-7.\n";
                    int resh;
                    cin >> resh;
                    while (resh > 2 || resh < 1) { cout << "введите 1 или 2!!!\n"; cin >> resh; }
                    if (resh == 1) { avtomat = avtomat + ((rand() % 8) + 1); cout << "автомат: " << avtomat << endl; }
                    else if (resh == 2) { avtomat = avtomat + ((rand() & 3) + 4); cout << "автомат: " << avtomat << endl; }
                }
            }
            if (avtomat > 20) { cout << "вы проиграли\n"; vyvod(avtomat, &stavka); br(); }
            vse += stavka;
            cout << "ваш выигрыш: " << floor(stavka) << endl;
            cout << "ваши деньги: " << floor(vse) << endl;
            if (vse > record) {
                record = vse;
                cout << "\nрекордное количество ваших денег: " << floor(record);
            }
            br();
            if (vse >= 20) {
                cout << "продолжить?\n1.да\n2.нет\n";
                cin >> ans;
                br();
            }
            else {
                cout << "у вас не осталось денег,\nвы проиграли.";
                ans = 2;
                br();
            }
        } while (ans == 1);
        if (vse == 0) {
            cout << "заново?\n1.да\n2.нет\n";
            cin >> x;
            cout << "\nрекордное количество ваших денег: " << floor(record);
            br();
        }
    } while (x == 1);
    return 0;
}
void vyvod(int a, double* dengi) {
    switch (a) {
    case 15:
        *dengi = *dengi * 0.25;
        break;
    case 16:
        *dengi = *dengi * 0.5;
        break;
    case 17:
        *dengi = *dengi;
        break;
    case 18:
        *dengi = *dengi * 1.25;
        break;
    case 19:
        *dengi = *dengi * 1.5;
        break;
    case 20:
        *dengi = *dengi * 2;
        break;
    default:
        *dengi = 0;
    }
    //cout << "ваши деньги: " << *dengi << endl;
}
void br() { cout << "\n\n\n"; }