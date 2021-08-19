#include "VNote.h"

VNote::VNote()
{
	tags.count = 0;
	tags.items = new string[0];
}

VNote::~VNote()
{

}

void VNote::SetData(Data nd)
{
	data = nd;
}

void VNote::SetTags(Tags nt)
{
	tags.count = nt.count;
	tags.items = new string[tags.count];

	for (int i = 0; i < tags.count; i++) {
		tags.items[i] = nt.items[i];
	}
}

void VNote::Print()
{
	cout << "Заголовок: " << data.title << endl;
	cout << "Дата создания (дд.мм.гггг): " << data.createDate.day << "." << data.createDate.month << "." << data.createDate.year << endl;
	cout << "Дата редактирования (дд.мм.гггг): " << data.editDate.day << "." << data.editDate.month << "." << data.editDate.year << endl;
	cout << "Заметка: " << data.note << endl;
	cout << "Метки: ";
	if (tags.count == 0) {
		cout << "отсутствуют!";
	}
	else {
		for (int i = 0; i < tags.count; i++) {
			cout << tags.items[i] << "; ";
		}
	}
	cout << endl;
}

bool VNote::Search(string t)
{
	int a = 0, b = 0;

	if (tags.count % 2 == 0) {
		a = tags.count / 2;
		b = tags.count;
	}
	else {
		a = (tags.count / 2) + 1;
		b = tags.count;
	}

	for (int i = 0; i < a; i++) {
		if (tags.items[i] == t)
			return true;
	}

	for (int i = 0; i < b; i++) {
		if (tags.items[i] == t)
			return true;
	}

	return false;
}