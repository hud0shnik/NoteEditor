#include "Functions.h"

int main() {

	// Локализация консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Инициализация компонентов
	VectorANote a;
	Init(a);

	VectorVNote v;
	Init(v);

	VectorGNote g;
	Init(g);

	VectorTNote t;
	Init(t);

	int act = 0;

	// Главный цикл программы
	do {
		// Выбор действия
		Menu(act);

		// Проверка выбора 
		switch (act)
		{
		case 0:
			break;

		case 1:
			Print(a, v, g, t);
			break;

		case 2:
			Add(a, v, g, t);
			break;

		case 3:
			Edit(a, v, g, t);
			break;

		case 4:
			Del(a, v, g, t);
			break;

		case 5:
			Load(a, v, g, t);
			break;

		case 6:
			Save(a, v, g, t);
			break;

		case 7:
			Search(a, v, g, t);
			break;

		case 8:
			Filtration(a, v, g, t);
			break;

		default:
			cout << "Неверный выбор!" << endl;
			break;
		}

		system("pause"); // задержка консоли 
		system("cls"); // очистка консоли
	} while (act != 0);

	Clear(a);
	Clear(v);
	Clear(g);
	Clear(t);

	system("cls"); // очистка консоли
	cout << "Работа завершена . . ." << endl;
	system("pause"); // задержка консоли 

	return 0;
}