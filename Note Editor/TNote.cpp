#include "TNote.h"

TNote::TNote()
{
	tags.count = 0;
	tags.items = new string[0];
}

TNote::~TNote()
{

}

void TNote::SetData(Data nd)
{
	data = nd;
}

void TNote::SetTags(Tags nt)
{
	tags.count = nt.count;
	tags.items = new string[tags.count];

	for (int i = 0; i < tags.count; i++) {
		tags.items[i] = nt.items[i];
	}
}

void TNote::Print()
{
	cout << "?????????: " << data.title << endl;
	cout << "???? ???????? (??.??.????): " << data.createDate.day << "." << data.createDate.month << "." << data.createDate.year << endl;
	cout << "???? ?????????????? (??.??.????): " << data.editDate.day << "." << data.editDate.month << "." << data.editDate.year << endl;
	cout << "???????: " << data.note << endl;
	cout << "?????: ";
	if (tags.count == 0) {
		cout << "???????????!";
	}
	else {
		for (int i = 0; i < tags.count; i++) {
			cout << tags.items[i] << "; ";
		}
	}
	cout << endl;
}

bool TNote::Search(string t)
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

