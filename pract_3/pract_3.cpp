﻿﻿#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char surName[17];
	char commandCode;
	double score;
	unsigned short place;
	struct Date date;
	bool isEmpty;
};

struct node {
	Record data;
	struct node* next;
};
struct node* myHead;
int countItem = 0;

void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void printWhithZero(int num, int width) {
	if (num > 999 and num < 10000) {
		cout.width(width + 1);
		cout << right << "00" << num;
	}
	if (num > 9999 and num < 100000) {
		cout.width(width);
		cout << right << "0" << num;
	}
}

void Draw(struct Record* records) {
	unsigned short width = 78 + 16;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Ведомость спортивных состязаний"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|  Фамилия участника   ";
	cout << left << "|  Код команды  ";
	cout << left << "|  Количество балов  ";
	cout << left << "|  Место в итоге  ";
	cout << left << " |     Дата     |" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 10; i++) {
		if (not records[i].isEmpty) {
			cout << left << "|";  cout.width(22); cout << left << records[i].surName;
			cout << left << "|";  cout.width(15); cout << left << records[i].commandCode;
			cout.precision(4);
			cout << left << "|"; cout << left << fixed << records[i].score;
			unsigned short w = 12;
			if (records[i].score > 9 and records[i].score < 100)
				w += 1;
			if (records[i].score > 0 and records[i].score < 10)
				w += 2;
			cout.width(w); cout.fill(' '); cout << " ";
			cout << left << "|";  cout.width(18); cout << left << records[i].place;
			cout << left << "|";
			printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
			cout << "|" << endl;
		}
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Д - \"Динамо\", С - \"Спартак\", Ш - \"Шахтер\""; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

void addItem(Record data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) {
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}
/// <summary>
/// Вставка элемента в список
/// </summary>
/// <param name="index">индекс после которого вставить</param>
/// <param name="data">значение которое необходимо вставить</param>
void insertItem(int index, Record data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}
/// <summary>
/// Изменить элемент списка
/// </summary>
/// <param name="index">индекс изменяемого элемента</param>
/// <param name="data">значение на которое нужно изменить</param>
void editItem(int index, Record data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
			//cout << "+" << current->data;
		}
		current->data = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}
/// <summary>
/// Функция для удаления элемента из динамического списка
/// </summary>
/// <param name="index">Индекс удаляемого элемента</param>
void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}
}
void printMyList() {
	struct node* current = myHead;
	cout << endl;
	while (current) {
		cout << " " << current->data.surName;
		current = current->next;
	}
}
void DrawWithList() {
	unsigned short width = 78 + 16;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Ведомость спортивных состязаний"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|  Фамилия участника   ";
	cout << left << "|  Код команды  ";
	cout << left << "|  Количество балов  ";
	cout << left << "|  Место в итоге  ";
	cout << left << " |     Дата     |" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(22); cout << left << current->data.surName;
		cout << left << "|"; cout.width(15); cout << left << current->data.commandCode;
		cout << left << "|"; cout.width(10 + 10); cout << left << current->data.score;
		std::cout.precision(4);
		cout << left << "|"; cout.width(18); cout << left << fixed << current->data.place;
		cout << left << "|";
		printDate(current->data.date.day, current->data.date.month, current->data.date.year, 16);
		cout << "|" << endl;
		current = current->next;
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Д - \"Динамо\", С - \"Спартак\", Ш - \"Шахтер\""; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Баландин", 'С', 123.7000, 2, {06,06,2022},0 };
	records[1] = { "Шишков", 'Ш', 79.9800, 3, {07,07,2022},0 };
	records[2] = { "Кравченко", 'Д',  134.8000, 1, {07,06,2022},0 };

	Draw(records);

	records[3] = { "Min", 'M',  0.0001, 1, {01,01,2000},0 };


	Draw(records);
	cout << endl << "Практическая № 2 (Динамические массивы):" << endl;


	Record* A;
	int n = 3;
	A = (Record*)malloc(n * sizeof(Record));
	//A = (Record*)calloc(n, sizeof(Record)); 
	for (int i = 0; i < n; i++) {
		strcpy_s(A[i].surName, records[i].surName);
		//strcpy_s(A[i].commandCode, records[i].commandCode);
		//A[i].surName = records[i].surName;
		/*A[i].year, records[i].year;*/
		//A[i].surName.assign(records[i].surName.c_str());
		//	*(B[i]) = records[i];
		//basic_string<char>
	}

	Record** B;
	B = (Record**) new Record * [10];
	for (int i = 0; i < 10; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = records[i];
	}

	//
	A = (Record*)realloc(A, 10 * sizeof(Record));
	// 
	//Record ** B;
	//B = (Record**) new Record * [10];
	//for (int i = 0; i < 10; i++) {
	//	B[i] = (Record*) new Record;
	//	*(B[i]) = A[i];
	//	//B[i].surName = A[i].surName;
	//	//*(B[i])->surName = A[i]->surName;
	//	
	//}

	//адрес а[i], значение a[i]->строковое_поле, адрес в[i], значение в[i]->строковое_поле.
	for (int i = 0; i < 10; i++) {
		cout << endl << "адрес A[i] " << &A[i] << " a[i]->surName " << A[i].surName;
		//cout << endl << "адрес B[i] " << &B[i] << " B[i]->surName " << B[i]->surName;
	}

	//for (int i = 0; i < 10; i++) {
	//	delete B[i];
	//}
	//delete[]B;
	//free(A);


	//pract_3

	addItem(records[0]);
	addItem(records[1]);
	addItem(records[2]);
	DrawWithList();
	struct Record newRecord = { "Баландин", 'С', 123.7000, 2, {06,06,2022},0 };
	insertItem(1, newRecord);
	DrawWithList();
	deleteItem(3);
	DrawWithList();
	struct Record editRecord = { "Шишков", 'Ш', 79.9800, 3, {07,07,2022},0 };
	editItem(1, editRecord);
	DrawWithList();







}