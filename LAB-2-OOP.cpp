#include "my_queue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	que q;
	people p;
	string filename = "", name = "no_name";
	int priority = 1, l = 0, r = 0;

	int nfun = 1;
	while (nfun != 0)
	{
		cout << "0 = Записать данные в файл и выйти\n"
			<< "1 = Показать очередь\n"
			<< "2 = Добавить элемент в очередь\n"
			<< "3 = Удалить передний элемент из очереди\n"
			<< "4 = Ввести данные из файла в очередь\n"
			<< "5 = Реализация \"Псевдозминной\"\n"
			<< "6 = показать передний элемент очереди\n"
			<< "7 = Рассортировать по приоритету\n\n"
			<< "Введите номер функции ";
		cin >> nfun;
		switch (nfun)
		{
		case 0:
			system("cls");
			q.file(filename);
			system("pause");
			break;
		case 1:
			system("cls");
			q.show();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Введите имя и приоритет, которое добавим в очередь\nИмя: ";
			cin >> name;
			cin.clear();
			cin.ignore();
			cout << "Приритет: "; cin >> priority;
			p.name = name;
			p.priority = priority;
			q.enqueue(p);
			system("pause");
			break;
		case 3:
			cout << endl;
			q.dequeue();
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Введите имя файла ";
			cin.clear();
			cin.ignore();
			getline(cin, filename);
			q.getfromfile(filename);
			break;
		case 5:
			system("cls");
			cout << "Введите границы очереди для изменения\n"
				<< "Левая "; cin >> l;
			cin.clear();
			cout << "Правая "; cin >> r;
			cin.clear();
			cout << "Введите данные о человеке\n"
				<< "Имя ";  cin >> name;
			p.name = name;
			cin.clear();
			cout << "Приоритет "; cin >> priority;
			p.priority = priority;
			q(l, r, p);
			break;
		case 6:
			system("cls");
			cout << "Имя: " << q.peek().name << "\t\tПриоритет: " << q.peek().priority << endl;
			system("pause");
			break;
		case 7:
			q.setpriority();
			system("cls");
			cout << "Отсортированно\n";
			break;
		default:
			cout << "Неправильно введен номер" << endl;
			break;
		}
		cin.clear();
		system("cls");
	}

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	return 0;
}