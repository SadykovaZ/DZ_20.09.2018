#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int buf_size = 0, cur_size = 0;
int p_number = 0;
int p_buffer = 0;
ifstream my_file;
//Телефон состоит из нескольких частей (код города и три двузначных числа). Разработайте структуру, описывающую номер телефона. Используйте битовые поля. Реализуйте функции для работы с этой структурой (заполнение, печать)

struct telephone
{
	int city_code;
	int a : 10;
	int b : 10;
	int c : 10;


	void enter()
	{
		int tmp;
		cout << "Введите код города: " << endl;
		cin >> city_code;
		cout << "Введите три двузначных номера: " << endl;
		cin >> tmp;
		a = tmp;
		cin >> tmp;
		b = tmp;
		cin >> tmp;
		c = tmp;
	}

	void print()
	{
		cout << "Код города: " << city_code << endl;
		cout << "Номера: " << a << " " << b << " " << c << endl;
	}

};
void add(telephone* &tt, telephone t)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		tt = new telephone[buf_size];
	}
	else
	{
		if (cur_size >= buf_size)
		{
			telephone* tmp = new telephone[buf_size * 2];
			for (int i = 0; i < buf_size; i++)
			{
				tmp[i] = tt[i];
			}
			delete[] tt;
			tt = tmp;
			buf_size *= 2;
		}
	}
	tt[cur_size++] = t;
}

//2.	Разработайте программу «Телефонный справочник». Создайте структуру «Запись» (номер телефона, ФИО). Номер телефона представлен битовыми полями (код города и три двузначных числа). 
//А)**Создайте массив из 10 экземпляров структуры «Запись» и реализуйте для него следующие функции :
//-	Отредактировать запись
//-	Печать всех телефонов
//-	Сортировка по ФИО

struct record
{
	string name;
	int city_code;
	int a : 10;
	int b : 10;
	int c : 10;
	void enter()
	{
		int tmp;
		my_file >> name;
		my_file >> city_code;
		my_file >> tmp;
		a = tmp;
		my_file >> tmp;
		b = tmp;
		my_file >> tmp;
		c = tmp;
	}

	void enter1()
	{
		int tmp;
		cout << "Введите новое имя: " << endl;
		cin >> name;
		cout << "Введите новый код: " << endl;
		cin >> city_code;
		cout << "Введите новые три двузначных номера : " << endl;
		cin >> tmp;
		a = tmp;
		cin >> tmp;
		b = tmp;
		cin >> tmp;
		c = tmp;
	}

	void enter2()
	{
		int tmp;
		cout << "Введите  имя: " << endl;
		cin >> name;
		cout << "Введите код: " << endl;
		cin >> city_code;
		cout << "Введите три двузначных номера : " << endl;
		cin >> tmp;
		a = tmp;
		cin >> tmp;
		b = tmp;
		cin >> tmp;
		c = tmp;
	}
	void print()
	{
		cout << "Имя: " << name << "  Код города: " << city_code << "  Номера: " << a << " " << b << " " << c << endl;
	}
};
void add1(record* &pp, record p1)
{
	if (p_buffer == 0)
	{
		p_buffer = 2;
		pp = new record[p_buffer];
	}
	else
	{
		if (p_number >= p_buffer)
		{
			record* tmp = new record[p_buffer * 2];
			for (int i = 0; i < p_buffer; i++)
			{
				tmp[i] = pp[i];
			}

			delete[] pp;
			pp = tmp;
			p_buffer *= 2;
		}
	}
	pp[p_number++] = p1;
}
void edit(record* pp)
{
	string poisk;
	cout << "Введите имя для поиска и редактирования: " << endl;
	cin >> poisk;
	for (int i = 0; i < 10; i++)
	{
		if (pp[i].name == poisk)
		{
			cout << "Введите новые данные: " << endl;
			pp[i].enter1();
			break;
		}
	}
}
void sort_by_name(record* pp)
{
	int n = p_number;
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (pp[i].name > pp[i + 1].name)
			{
				swap(pp[i], pp[i + 1]);
			}
		}
	}
}
void sort_by_number(record* pp)
{
	int n = p_number;
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (pp[i].a > pp[i + 1].a)
			{
				swap(pp[i], pp[i + 1]);
			}
		}
	}
}
void erase(record* &pp)
{
	int k = 0;
	string poisk;
	record* tmp;
	cout << "Введите имя для удаления: ";
	cin >> poisk;
	for (int i = 0; i < p_number; i++)
	{
		if (pp[i].name == poisk)
		{
			k = i;
			tmp = new record[p_number - 1];
			for (int j = 0, z = 0; j < p_number - 1; j++, z++)
			{
				if (j < k)
					tmp[j] = pp[j];
				else
				{
					z++;
					tmp[j] = pp[z];
				}
			}
			delete[] pp;
			pp = tmp;
			p_number--;
			break;
		}
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");

	int n = 0;
	cout << "Введите номер задания: ";
	cin >> n;
	if (n == 1)
	{
		cout << "Телефон состоит из нескольких частей (код города и три двузначных числа). Разработайте структуру, описывающую номер телефона. Используйте битовые поля. Реализуйте функции для работы с этой структурой (заполнение, печать)." << endl;
		telephone t1;
		telephone* tt = new telephone;
		int c;
		cout << "Введите количество: ";
		cin >> c;
		for (int i = 0; i < c; i++)
		{
			t1.enter();
			add(tt, t1);
		}
		for (int i = 0; i < c; i++)
		{
			t1.print();
		}
	}
	else if (n == 2)
	{
		cout << "А)**Создайте массив из 10 экземпляров структуры «Запись» и реализуйте для него следующие функции: \n -Отредактировать запись, \n -Печать всех телефонов,\n -Сортировка по ФИО. " << endl;
		my_file.open("in.txt", ios::in);
		record p1;
		record* pp = new record;
		int t;
		my_file >> t;
		for (int i = 0; i < t; i++)
		{
			p1.enter();
			add1(pp, p1);
		}
		for (int i = 0; i < p_number; i++)
		{
			pp[i].print();
		}
		int choice = 0;
		cout << "Меню: \n 1. Отредактировать запись, \n 2. Печать всех телефонов, \n 3. Сортировка по ФИО. " << endl;
		cin >> choice;
		switch (choice)
		{


		case 1:
		{
			edit(pp);
			for (int i = 0; i < p_number; i++)
			{
				pp[i].print();
			}
		}
		break;
		case 2:
		{
			for (int i = 0; i < p_number; i++)
			{
				pp[i].print();
			}
		}
		break;
		case 3:
		{
			sort_by_name(pp);
			for (int i = 0; i < p_number; i++)
			{
				pp[i].print();
			}
		}
		break;
		}
		delete[]pp;
	}
	else if (n == 3)
	{
		cout << "Создайте массив экземпляров структуры «Запись» и реализуйте для него следующие функции:" << endl;
		record p1;
		record* pp = new record;
		int t;
		int choice;
		cout << "Введите количество имен: ";
		cin >> t;

		while (true)
		{
			cout << " 1. Добавить запись, \n 2. Отредактировать запись, \n 3. Удалить запись, \n 4. Печать всех телефонов, \n 5. Сортировка по ФИО, \n 6. Сортировка по номеру телефона." << endl;
			cout << "Ваш выбор: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				for (int i = 0; i < t; i++)
				{
					p1.enter2();
					add1(pp, p1);
				}
				for (int i = 0; i < t; i++)
				{
					pp[i].print();
				}
			}
			break;
			case 2:
			{
				edit(pp);
				cout << "После редактирования: " << endl;
				for (int i = 0; i < t; i++)
				{
					pp[i].print();
				}
			}
			break;
			case 3:
			{
				erase(pp);
				cout << "После удаления: " << endl;
				for (int i = 0; i < t; i++)
				{
					pp[i].print();
				}
			}
			break;
			case 4:
			{
				for (int i = 0; i < t; i++)
				{
					pp[i].print();
				}
			}
			break;
			case 5:
			{
				sort_by_name(pp);
				for (int i = 0; i < p_number; i++)
				{
					pp[i].print();
				}
			}
			break;
			case 6:
			{
				sort_by_number(pp);
				for (int i = 0; i < p_number; i++)
				{
					pp[i].print();
				}
			}
			break;

			}
			int n1;
			cout << "Продолжить: 1 - да, 0 -нет: ";
			cin >> n1;
			if (n1 == 0) break;
		}

		delete[] pp;
	}
	system("pause");

}