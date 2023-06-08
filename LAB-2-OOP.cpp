#include <D:\Projects\Static_library\My_queue_library\My_queue.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	que* qarr = new que[10];
	people p;
	string filename = "", name = "no_name";
	int priority = 1, l = 0, r = 0, i = 0, l1 = 0, r1 = 0;

	int nfun = 0, nq = 0;
	while (nfun != -1)
	{
		cout << "0 = Записать данные в файл\n"
			<< "1 = Показать очередь\n"
			<< "2 = Добавить элемент в очередь\n"
			<< "3 = Удалить передний элемент из очереди\n"
			<< "4 = Ввести данные из файла в очередь\n"
			<< "5 = Реализация \"Псевдозминной\" с очередью\n"
			<< "6 = Реализация \"Псевдозминной\" с человеком\n"
			<< "7 = Показать передний элемент очереди\n"
			<< "8 = Рассортировать по приоритету\n"
			<< "9 = Перейти в управление к новой очереди\n"
			<< "10 = Слияние очередей\n"
			<< "-1 = Завершить и выйти\n\n"
			<< "Введите номер функции ";
		cin >> nfun;
		system("cls");
		switch (nfun)
		{
		case 0:
			cout << "Введите путь к файлу куда записать очередь\n";
			cin.ignore();
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, filename);
			qarr[nq].file(filename);
			cout << "Успешно записано\n";
			system("pause");
			break;
		case 1:
			qarr[nq].show();
			system("pause");
			break;
		case 2:
			cout << "Введите имя и приоритет, которое добавим в очередь\nИмя: ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			cin >> name;
			cin.clear();
			cin.ignore();
			cout << "Приритет: "; cin >> priority;
			p.name = name;
			p.priority = priority;
			qarr[nq].push(p);
			system("pause");
			break;
		case 3:
			cout << endl;
			qarr[nq].pop();
			system("pause");
			break;
		case 4:
			cout << "Введите имя файла ";
			cin.clear();
			cin.ignore();
			getline(cin, filename);
			qarr[nq].getfromfile(filename);
			break;
		case 5:
			cout << "Введите границы очереди для изменения\n"
				<< "Левая "; cin >> l; cin.clear();
			cout << "Правая "; cin >> r; cin.clear();
			cout << "Введите номер очереди которую вставить в данную ";
			cin >> i; cin.clear();
			cout << "Введите границы из добавляемой очереди\n"
				<< "Левая "; cin >> l1; cin.clear();
			cout << "Правая "; cin >> r1; cin.clear();
			qarr[nq](l, r) = qarr[i](l1, r1);
			break;
		case 6:
			cout << "Введите границы очереди для изменения\n"
				<< "Левая "; cin >> l;
			cin.clear();
			cout << "Правая "; cin >> r;
			cin.clear();
			cout << "Введите данные о человеке\n"
				<< "Имя ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			cin >> name;
			p.name = name;
			cin.clear();
			cout << "Приоритет "; cin >> priority;
			p.priority = priority;
			qarr[nq](l, r) = p;
			break;
		case 7:
			cout << "Имя: " << qarr[nq].peek().name << "\t\tПриоритет: " << qarr[nq].peek().priority << endl;
			system("pause");
			break;
		case 8:
			qarr[nq].setpriority();
			cout << "Отсортированно\n";
			break;
		case 9:
			cout << "Введите номер нужной очереди ";
			cin >> nq;
			cout << "Управление передано\n";
			system("pause");
			break;
		case 10:
			cout << "Введите номер очереди для сливания ";
			cin >> i;
			qarr[nq] + qarr[i];
			cout << "Слияние произошло\n";
			system("pause");
			break;
		default:
			break;
		}
		cin.clear();
		filename.clear();
		system("cls");
	}

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	return 0;
}
