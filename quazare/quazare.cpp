#include <iostream>
#include <random>
using namespace std;
void win(int a, double *dengi);
void br();
int main() {
	//установка русского языка
	setlocale(LC_ALL, "Russian");
	//переменные
	double stavka, vse, record;
	int x, ans, doing, avtomat, resh;
	do {
		//стоковые значения для переменных
		x = 0;
		stavka = 0;
		vse = 200;
		record = 0;
		//(недо)решение проблемы с рандомом
		rand(); rand();
		do {
			//ставка
			cout << "у вас всего денег: " << floor(vse) << endl;
			cout << "введите номер действия со ставкой:\n\n";
			cout << "1.поставить все деньги(если больше 200 то ставится 200);\n";
			cout << "2.поставить половину всех ваших денег(если больше 200 то поставится 100);\n";
			cout << "3.поставить минимум(20);\n";
			cout << "4.ввести свою ставку.\n";
			cin >> doing;
			while (doing > 4 || doing < 1) { cout << "можно ввести от 1 до 4!!\n"; cin >> doing; }
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
			//вычитание ставки из всех денег
			vse -= stavka;
			cout << endl << "ваши деньги: " << floor(vse) << endl;
			br();
			//случайное число из автомата
			avtomat = (rand() % 12) + 1;
			cout << "автомат: " << avtomat << endl;
			//решения
			while (avtomat <= 20) {
				//варианты ответа если больше автомат выдал больше 14
				if (avtomat > 14) {
					if (avtomat == 20) { cout << "ВЫ ПОБЕДИЛИ!\n"; win(avtomat, &stavka); break; }
					cout << "введите 1, 2 или 3\n1: добавить 1-8;\n2: добавить 4-7;\n3: забрать.\n";
					cin >> resh;
					while (resh > 3 || resh < 1) { cout << "введите 1, 2 или 3!!!\n"; cin >> resh; }
					if (resh == 1) { avtomat = avtomat + ((rand() % 8) + 1); cout << "автомат: " << avtomat << endl; }
					else if (resh == 2) { avtomat = avtomat + ((rand() & 3) + 4); cout << "автомат: " << avtomat << endl; }
					else if (resh == 3) { win(avtomat, &stavka); br(); break; }
				}
				//варианты ответа если больше автомат выдал меньше или ровно 14
				else {
					cout << "введите 1 или 2\n1: добавить 1-8;\n2: добавить 4-7.\n";
					cin >> resh;
					while (resh > 2 || resh < 1) { cout << "введите 1 или 2!!!\n"; cin >> resh; }
					if (resh == 1) { avtomat = avtomat + ((rand() % 8) + 1); cout << "автомат: " << avtomat << endl; }
					else if (resh == 2) { avtomat = avtomat + ((rand() & 3) + 4); cout << "автомат: " << avtomat << endl; }
				}
			}
			if (avtomat > 20) { cout << "вы проиграли\n"; win(avtomat, &stavka); br(); }
			//возвращение денег обратно на счёт
			vse += stavka;
			//вывод выигрыша
			cout << "ваш выигрыш: " << floor(stavka) << endl;
			cout << "ваши деньги: " << floor(vse) << endl;
			if (vse > record) {
				record = vse;
				cout << "\nрекордное количество ваших денег: " << floor(record);
			}
			br();
			//решение о продолжение игры
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
		//решение о начале игры заново
		if (vse == 0) {
			cout << "заново?\n1.да\n2.нет\n";
			cin >> x;
			br();
		}
		if (x != 1) { cout << "\nрекордное количество ваших денег: " << floor(record); br(); }

	} while (x == 1);
	return 0;
}
//функция для определения выигрыша
void win(int a, double *dengi) {
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
}
//отступ на несколько строк
void br() { cout << "\n\n\n"; }