#include "Functions.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu(int& option)
{
	cout<< "�������� ��������: " << endl
		<< "[0. ����� �� ���������]" << endl
		<< "[1. �����]" << endl
		<< "[2. ��������]" << endl
		<< "[3. �������������]" << endl
		<< "[4. �������]" << endl
		<< "[5. ���������]" << endl
		<< "[6. ���������]" << endl
		<< "[7. �����]" << endl
		<< "[8. ����������]" << endl
		<< "��� �����: ";
	cin >> option;
	system("cls");
}

void Print(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	int option;
	cout<< "�������� ��������: " << endl
		<< "[0. �����]" << endl
		<< "[1. ����� ����� �������]" << endl
		<< "[2. ����� ����� �������]" << endl
		<< "[3. ����� ����������� �������]" << endl
		<< "[4. ����� ��������� �������]" << endl
		<< "��� �����: ";
	cin >> option;

	system("cls");

	if (option == 0) return;

	switch (option)
	{
	case 1:
		cout << "\t***����� �������***" << endl;
		Print(a);
		break;
	case 2:
		cout << "\t***����� �������***" << endl;
		Print(v);
		break;
	case 3:
		cout << "\t***����������� �������***" << endl;
		Print(g);
		break;
	case 4:
		cout << "\t***��������� �������***" << endl;
		Print(t);
		break;
	default:
		cout << "�������� �����" << endl;
		return;
	}
}

void Add(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	int option;
	cout<< "�������� ��������: " << endl
		<< "[0. �����]" << endl
		<< "[1. �������� ��������� �������]" << endl
		<< "[2. �������� ����� �������]" << endl
		<< "[3. �������� ����������� �������]" << endl
		<< "[4. �������� ����� �������]" << endl
		<< "��� �����: ";
	cin >> option;

	system("cls");

	if (option == 0) return;
	else if (option > 4) {
		cout << "�������� �����" << endl;
		return;
	}

	// ��������� ������ 
	TNote tvrem;
	VNote vvrem;
	GNote gvrem;
	ANote avrem;
	Data vrem;
	Tags ts;

	cout << "������� ���������: ";
	cin >> vrem.title;

	cout << "������� �������: ";
	cin >> vrem.note;

	cout << "������� ���� �������� (�� �� ����): ";
	cin >> vrem.createDate.day >> vrem.createDate.month >> vrem.createDate.year;

	vrem.editDate.day = 0;
	vrem.editDate.month = 0;
	vrem.editDate.year = 0;

	system("cls");

	cout << "������� ���������� �����: ";
	cin >> ts.count;
	ts.items = new string[ts.count];

	for (int i = 0; i < ts.count; i++) {
		cout << "����� �" << i + 1 << ": ";
		cin >> ts.items[i];
	}

	system("cls");

	switch (option) {
	case 1:
		tvrem.SetData(vrem);
		tvrem.SetTags(ts);
		Add(t, tvrem);
		break;
	case 2:
		vvrem.SetData(vrem);
		vvrem.SetTags(ts);
		Add(v, vvrem);
		break;
	case 3:
		gvrem.SetData(vrem);
		gvrem.SetTags(ts);
		Add(g, gvrem);
		break;
	case 4:
		avrem.SetData(vrem);
		avrem.SetTags(ts);
		Add(a, avrem);
		break;
	default:
		break;
	}

	cout << "������ ���������" << endl;
}

void Edit(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	int option;
	cout<< "�������� ��������: " << endl
		<< "[0. �����]" << endl
		<< "[1. ������������� ����� �������]" << endl
		<< "[2. ������������� ����� �������]" << endl
		<< "[3. ������������� ����������� �������]" << endl
		<< "[4. ������������� ��������� �������]" << endl
		<< "��� �����: ";
	cin >> option;

	system("cls");

	if (option == 0) return;
	else if (option > 4) {
		cout << "�������� �����" << endl;
		return;
	}

	// ��������� ������ 
	ANote avrem;
	VNote vvrem;
	GNote gvrem;
	TNote tvrem;
	Data vrem;
	Tags ts;
	bool y;
	int index;

	ts.count = 0;
	ts.items = new string[0];

	if (option == 1) {
		cout << "�������� ����� �������� (�� 1 �� " << a.count << "): ";
		cin >> index;
		index--; // ��� ��� ������ �� 1, � ���� �� 0

		// �������� �������
		if (index < 0 || index > a.count - 1) {
			cout << "������ ��� ���������" << endl;
			return;
		}

		vrem = a.items[index].GetData();
		ts = a.items[index].GetTags();
	}
	else if (option == 2) {
		cout << "�������� ����� �������� (�� 1 �� " << v.count << "): ";
		cin >> index;
		index--; // ��� ��� ������ �� 1, � ���� �� 0

		// �������� �������
		if (index < 0 || index > v.count - 1) {
			cout << "������ ��� ���������" << endl;
			return;
		}

		vrem = v.items[index].GetData();
		ts = v.items[index].GetTags();
	}
	else if (option == 3) {
		cout << "�������� ����� �������� (�� 1 �� " << g.count << "): ";
		cin >> index;
		index--; // ��� ��� ������ �� 1, � ���� �� 0

		// �������� �������
		if (index < 0 || index > g.count - 1) {
			cout << "������ ��� ���������" << endl;
			return;
		}

		vrem = g.items[index].GetData();
		ts = g.items[index].GetTags();
	}
	else if (option == 4) {
		cout << "�������� ����� �������� (�� 1 �� " << t.count << "): ";
		cin >> index;
		index--; // ��� ��� ������ �� 1, � ���� �� 0

		// �������� �������
		if (index < 0 || index > t.count - 1) {
			cout << "������ ��� ���������" << endl;
			return;
		}

		vrem = t.items[index].GetData();
		ts = t.items[index].GetTags();
	}
	system("cls");

	cout << "�������� ���������? (��:1/���:0): ";
	cin >> y;
	system("cls");

	if (y) {
		cout << "������� ���������: ";
		cin >> vrem.title;
		system("cls");
	}

	cout << "�������� �������? (��:1/���:0): ";
	cin >> y;
	system("cls");

	if (y) {
		cout << "������� �������: ";
		cin >> vrem.note;
		system("cls");
	}

	cout << "������� ���� �������������� (�� �� ����): ";
	cin >> vrem.editDate.day >> vrem.editDate.month >> vrem.editDate.year;
	system("cls");

	cout << "�������� �����? (��:1/���:0): ";
	cin >> y;
	system("cls");

	if (y) {
		cout << "������� ���������� �����: ";
		cin >> ts.count;
		ts.items = new string[ts.count];

		for (int i = 0; i < ts.count; i++) {
			cout << "����� �" << i + 1 << ": ";
			cin >> ts.items[i];
		}
	}
	system("cls");

	switch (option) {
	case 1:
		avrem.SetData(vrem);
		avrem.SetTags(ts);
		Edit(index, a, avrem);
		break;
	case 2:
		vvrem.SetData(vrem);
		vvrem.SetTags(ts);
		Edit(index, v, vvrem);
		break;
	case 3:
		gvrem.SetData(vrem);
		gvrem.SetTags(ts);
		Edit(index, g, gvrem);
		break;
	case 4:
		tvrem.SetData(vrem);
		tvrem.SetTags(ts);
		Edit(index, t, tvrem);
		break;
	default:
		break;
	}
}

void Del(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	int index;
	int option;
	cout<< "�������� ��������: " << endl
		<< "[0. �����]" << endl
		<< "[1. ������� ����� �������]" << endl
		<< "[2. ������� ����� �������]" << endl
		<< "[3. ������� ����������� �������]" << endl
		<< "[4. ������� ��������� �������]" << endl
		<< "��� �����: ";
	cin >> option;

	system("cls");

	if (option == 0) return;
	else if (option > 4) {
		cout << "�������� �����" << endl;
		return;
	}

	if (option == 1) cout << "�������� ����� �������� (�� 1 �� " << a.count << "): ";
	else if (option == 2) cout << "�������� ����� �������� (�� 1 �� " << v.count << "): ";
	else if (option == 3) cout << "�������� ����� �������� (�� 1 �� " << g.count << "): ";
	else if (option == 4) cout << "�������� ����� �������� (�� 1 �� " << t.count << "): ";
	cin >> index;
	index--; // ��� ��� ������ �� 1, � ���� �� 0
	system("cls");

	switch (option)
	{
	case 1:
		Del(index, a);
		break;
	case 2:
		Del(index, v);
		break;
	case 3:
		Del(index, g);
		break;
	case 4:
		Del(index, t);
		break;
	default:
		break;
	}
}

void Search(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	int option;
	cout<< "�������� ��������: " << endl
		<< "[0. �����]" << endl
		<< "[1. ����� ����� ����� �������]" << endl
		<< "[2. ����� ����� ����� �������]" << endl
		<< "[3. ����� ����� ����������� �������]" << endl
		<< "[4. ����� ����� ��������� �������]" << endl
		<< "��� �����: ";
	cin >> option;

	system("cls");

	if (option == 0) return;
	else if (option > 4) {
		cout << "�������� �����" << endl;
		return;
	}

	string tag;
	cout << "������� �����: ";
	cin >> tag;
	system("cls");

	switch (option)
	{
	case 1:
		Search(tag, a);
		break;
	case 2:
		Search(tag, v);
		break;
	case 3:
		Search(tag, g);
		break;
	case 4:
		Search(tag, t);
		break;
	default:
		break;
	}
}

void Filtration(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	int option;
	cout<< "�������� ��������: " << endl
		<< "[0. �����]" << endl
		<< "[1. ���������� �� ������� ����� �������]" << endl
		<< "[2. ���������� �� ������� ����� �������]" << endl
		<< "[3. ���������� �� ������� ����������� �������]" << endl
		<< "[4. ���������� �� ������� ��������� �������]" << endl
		<< "��� �����: ";
	cin >> option;

	system("cls");

	if(option == 0) return;
	else if (option > 4) {
		cout << "�������� �����" << endl;
		return;
	}

	string tag;
	cout << "������� �����: ";
	cin >> tag;
	system("cls");

	switch (option)
	{
	case 1:
		Filtration(tag, a);
		break;
	case 2:
		Filtration(tag, v);
		break;
	case 3:
		Filtration(tag, g);
		break;
	case 4:
		Filtration(tag, t);
		break;
	default:
		break;
	}
}

void Save(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	string fname;
	cout << "������� �������� �����: ";
	cin >> fname;

	system("cls");

	// �������� ������ ��� ������ � ����
	ofstream save(fname, ios::out);

	save << a.count << endl;
	for (int i = 0; i < a.count; i++) {
		save << a.items[i].GetData().title << endl;
		save << a.items[i].GetData().note << endl;
		save << a.items[i].GetData().createDate.day << endl;
		save << a.items[i].GetData().createDate.month << endl;
		save << a.items[i].GetData().createDate.year << endl;
		save << a.items[i].GetData().editDate.day << endl;
		save << a.items[i].GetData().editDate.month << endl;
		save << a.items[i].GetData().editDate.year << endl;

		save << a.items[i].GetTags().count << endl;
		for (int j = 0; j < a.items[i].GetTags().count; j++) {
			save << a.items[i].GetTags().items[j]<< endl;
		}
	}

	save << v.count << endl;
	for (int i = 0; i < v.count; i++) {
		save << v.items[i].GetData().title << endl;
		save << v.items[i].GetData().note << endl;
		save << v.items[i].GetData().createDate.day << endl;
		save << v.items[i].GetData().createDate.month << endl;
		save << v.items[i].GetData().createDate.year << endl;
		save << v.items[i].GetData().editDate.day << endl;
		save << v.items[i].GetData().editDate.month << endl;
		save << v.items[i].GetData().editDate.year << endl;

		save << v.items[i].GetTags().count << endl;
		for (int j = 0; j < v.items[i].GetTags().count; j++) {
			save << v.items[i].GetTags().items[j]<< endl;
		}
	}

	save << g.count << endl;
	for (int i = 0; i < g.count; i++) {
		save << g.items[i].GetData().title << endl;
		save << g.items[i].GetData().note << endl;
		save << g.items[i].GetData().createDate.day << endl;
		save << g.items[i].GetData().createDate.month << endl;
		save << g.items[i].GetData().createDate.year << endl;
		save << g.items[i].GetData().editDate.day << endl;
		save << g.items[i].GetData().editDate.month << endl;
		save << g.items[i].GetData().editDate.year << endl;

		save << g.items[i].GetTags().count << endl;
		for (int j = 0; j < v.items[i].GetTags().count; j++) {
			save << g.items[i].GetTags().items[j]<< endl;
		}
	}

	save << t.count << endl;
	for (int i = 0; i < t.count; i++) {
		save << t.items[i].GetData().title << endl;
		save << t.items[i].GetData().note << endl;
		save << t.items[i].GetData().createDate.day << endl;
		save << t.items[i].GetData().createDate.month << endl;
		save << t.items[i].GetData().createDate.year << endl;
		save << t.items[i].GetData().editDate.day << endl;
		save << t.items[i].GetData().editDate.month << endl;
		save << t.items[i].GetData().editDate.year << endl;

		if (i < t.count - 1) {
			save << t.items[i].GetTags().count << endl;
			for (int j = 0; j < t.items[i].GetTags().count; j++) {
				save << t.items[i].GetTags().items[j]<< endl;
			}
		}
		else {
			save << t.items[i].GetTags().count;
			if (t.items[i].GetTags().count != 0) {
				save << endl;

				for (int j = 0; j < t.items[i].GetTags().count; j++) {
					save << t.items[i].GetTags().items[j];

					if (j < t.items[i].GetTags().count - 1) save << endl;
				}
			}
		}
	}

	save.close();
	cout << "������ ���������" << endl;
}

void Load(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t)
{
	string fname;
	cout << "������� �������� �����: ";
	cin >> fname;

	system("cls");

	// �������� ������ ��� ������
	ifstream load(fname);

	// �������� �����
	if (!load) {
		cout << "������ ������ �����" << endl;
		return;
	}

	// ��������� ������ 
	ANote avrem;
	VNote vvrem;
	GNote gvrem;
	TNote tvrem;
	Data vrem;
	Tags ts;
	int count;

	load >> count;
	a.items = new ANote[count];
	a.count = 0;

	for (int i = 0; i < count; i++) {
		load >> vrem.title;
		load >> vrem.note;
		load >> vrem.createDate.day;
		load >> vrem.createDate.month;
		load >> vrem.createDate.year;
		load >> vrem.editDate.day;
		load >> vrem.editDate.month;
		load >> vrem.editDate.year;

		load >> ts.count;
		ts.items = new string[ts.count];
		for (int j = 0; j < ts.count; j++) {
			load >> ts.items[j];
		}

		avrem.SetData(vrem);
		avrem.SetTags(ts);

		Add(a, avrem);
	}

	load >> count;
	v.items = new VNote[count];
	v.count = 0;

	for (int i = 0; i < count; i++) {
		load >> vrem.title;
		load >> vrem.note;
		load >> vrem.createDate.day;
		load >> vrem.createDate.month;
		load >> vrem.createDate.year;
		load >> vrem.editDate.day;
		load >> vrem.editDate.month;
		load >> vrem.editDate.year;

		load >> ts.count;
		ts.items = new string[ts.count];
		for (int j = 0; j < ts.count; j++) {
			load >> ts.items[j];
		}

		vvrem.SetData(vrem);
		vvrem.SetTags(ts);

		Add(v, vvrem);
	}

	load >> count;
	g.items = new GNote[count];
	g.count = 0;

	for (int i = 0; i < count; i++) {
		load >> vrem.title;
		load >> vrem.note;
		load >> vrem.createDate.day;
		load >> vrem.createDate.month;
		load >> vrem.createDate.year;
		load >> vrem.editDate.day;
		load >> vrem.editDate.month;
		load >> vrem.editDate.year;

		load >> ts.count;
		ts.items = new string[ts.count];
		for (int j = 0; j < ts.count; j++) {
			load >> ts.items[j];
		}

		gvrem.SetData(vrem);
		gvrem.SetTags(ts);

		Add(g, gvrem);
	}

	load >> count;
	t.items = new TNote[count];
	t.count = 0;

	for (int i = 0; i < count; i++) {
		load >> vrem.title;
		load >> vrem.note;
		load >> vrem.createDate.day;
		load >> vrem.createDate.month;
		load >> vrem.createDate.year;
		load >> vrem.editDate.day;
		load >> vrem.editDate.month;
		load >> vrem.editDate.year;

		load >> ts.count;
		ts.items = new string[ts.count];
		for (int j = 0; j < ts.count; j++) {
			load >> ts.items[j];
		}

		tvrem.SetData(vrem);
		tvrem.SetTags(ts);

		Add(t, tvrem);
	}

	load.close();
	cout << "������ ���������" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Copy(int n, ANote* org, ANote* (&res), int excl) {
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q].SetData(org[i].GetData());
			res[q].SetTags(org[i].GetTags());
			q++;
		}
	}
}

void Add(VectorANote(&origin), ANote a) {
	if (origin.count == 0) {
		origin.count = 1;
		origin.items = new ANote[origin.count];
	}
	else {
		ANote* vrem = new ANote[origin.count];
		Copy(origin.count, origin.items, vrem, -1);

		origin.count++;
		origin.items = new ANote[origin.count];

		Copy(origin.count - 1, vrem, origin.items, -1);

		delete[] vrem;
	}

	origin.items[origin.count - 1].SetData(a.GetData());
	origin.items[origin.count - 1].SetTags(a.GetTags());
}

void Print(VectorANote n) {
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	for (int i = 0; i < n.count; i++) {
		n.items[i].Print();
		cout << "-=-=-=-=-=-=-=-=-=-=-" << endl;
	}
}

void Edit(int i, VectorANote& n, ANote a) {
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (i < 0 || i > n.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	n.items[i].SetData(a.GetData());
	n.items[i].SetTags(a.GetTags());

	cout << "������ ��������" << endl;
}

void Del(int index, VectorANote(&origin)) {
	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (index < 0 || index > origin.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	// ��������� ������
	ANote* vrem = new ANote[origin.count];
	Copy(origin.count, origin.items, vrem, -1);

	origin.items = new ANote[origin.count - 1];

	Copy(origin.count, vrem, origin.items, index);
	origin.count--;

	delete[] vrem;

	cout << "������ �������" << endl;
}

void Search(string t, VectorANote n) {
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;
			n.items[i].Print();
			break;
		}
	}
	if (!found)	cout << "���������� �� �������" << endl;
}

void Filtration(string t, VectorANote n) {
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;
			n.items[i].Print();
		}
	}
	if (!found) cout << "���������� �� �������" << endl;
}

void Clear(VectorANote& n) {
	delete[] n.items;
	n.count = 0;
	n.items = new ANote[0];
}

void Init(VectorANote& n) {
	n.count = 0;
	n.items = new ANote[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Copy(int n, VNote* org, VNote* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q].SetData(org[i].GetData());
			res[q].SetTags(org[i].GetTags());
			q++;
		}
	}
}

void Add(VectorVNote(&origin), VNote a)
{
	if (origin.count == 0) {
		origin.count = 1;
		origin.items = new VNote[origin.count];
	}
	else {
		VNote* vrem = new VNote[origin.count];
		Copy(origin.count, origin.items, vrem, -1);

		origin.count++;
		origin.items = new VNote[origin.count];

		Copy(origin.count - 1, vrem, origin.items, -1);

		delete[] vrem;
	}

	origin.items[origin.count - 1].SetData(a.GetData());
	origin.items[origin.count - 1].SetTags(a.GetTags());
}

void Print(VectorVNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	for (int i = 0; i < n.count; i++) {
		n.items[i].Print();
		cout << "-=-=-=-=-=-=-=-=-=-=-" << endl;
	}
}

void Edit(int i, VectorVNote& n, VNote a)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (i < 0 || i > n.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	n.items[i].SetData(a.GetData());
	n.items[i].SetTags(a.GetTags());

	cout << "������ ��������" << endl;
}

void Del(int index, VectorVNote(&origin))
{
	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (index < 0 || index > origin.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// ��������� ������
	VNote* vrem = new VNote[origin.count];
	Copy(origin.count, origin.items, vrem, -1);

	origin.items = new VNote[origin.count - 1];

	Copy(origin.count, vrem, origin.items, index);
	origin.count--;

	delete[] vrem;

	cout << "������ �������" << endl;
}

void Search(string t, VectorVNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;

			n.items[i].Print();
			break;
		}
	}

	if (!found)	cout << "���������� �� �������" << endl;
}

void Filtration(string t, VectorVNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;
			n.items[i].Print();
		}
	}

	if (!found) cout << "���������� �� �������" << endl;
}

void Clear(VectorVNote& n)
{
	delete[] n.items;
	n.count;
}

void Init(VectorVNote& n)
{
	n.count = 0;
	n.items = new VNote[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Copy(int n, GNote* org, GNote* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q].SetData(org[i].GetData());
			res[q].SetTags(org[i].GetTags());
			q++;
		}
	}
}

void Add(VectorGNote(&origin), GNote a)
{
	if (origin.count == 0) {
		origin.count = 1;
		origin.items = new GNote[origin.count];
	}
	else {
		GNote* vrem = new GNote[origin.count];
		Copy(origin.count, origin.items, vrem, -1);

		origin.count++;
		origin.items = new GNote[origin.count];

		Copy(origin.count - 1, vrem, origin.items, -1);

		delete[] vrem;
	}

	origin.items[origin.count - 1].SetData(a.GetData());
	origin.items[origin.count - 1].SetTags(a.GetTags());
}

void Print(VectorGNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	for (int i = 0; i < n.count; i++) {
		n.items[i].Print();
		cout << "-=-=-=-=-=-=-=-=-=-=-" << endl;
	}
}

void Edit(int i, VectorGNote& n, GNote a)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (i < 0 || i > n.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	n.items[i].SetData(a.GetData());
	n.items[i].SetTags(a.GetTags());

	cout << "������ ��������" << endl;
}

void Del(int index, VectorGNote(&origin))
{
	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (index < 0 || index > origin.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// ��������� ������
	GNote* vrem = new GNote[origin.count];
	Copy(origin.count, origin.items, vrem, -1);

	origin.items = new GNote[origin.count - 1];

	Copy(origin.count, vrem, origin.items, index);
	origin.count--;

	delete[] vrem;

	cout << "������ �������" << endl;
}

void Search(string t, VectorGNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;
			n.items[i].Print();
			break;
		}
	}

	if (!found) cout << "���������� �� �������" << endl;
}

void Filtration(string t, VectorGNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;
			n.items[i].Print();
		}
	}

	if (!found) cout << "���������� �� �������" << endl;
}

void Clear(VectorGNote& n)
{
	delete[] n.items;
	n.count;
}

void Init(VectorGNote& n)
{
	n.count = 0;
	n.items = new GNote[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Copy(int n, TNote* org, TNote* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q].SetData(org[i].GetData());
			res[q].SetTags(org[i].GetTags());
			q++;
		}
	}
}

void Add(VectorTNote(&origin), TNote a)
{
	if (origin.count == 0) {
		origin.count = 1;
		origin.items = new TNote[origin.count];
	}
	else {
		TNote* vrem = new TNote[origin.count];
		Copy(origin.count, origin.items, vrem, -1);

		origin.count++;
		origin.items = new TNote[origin.count];

		Copy(origin.count - 1, vrem, origin.items, -1);

		delete[] vrem;
	}

	origin.items[origin.count - 1].SetData(a.GetData());
	origin.items[origin.count - 1].SetTags(a.GetTags());
}

void Print(VectorTNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	for (int i = 0; i < n.count; i++) {
		n.items[i].Print();
		cout << "-=-=-=-=-=-=-=-=-=-=-" << endl;
	}
}

void Edit(int i, VectorTNote& n, TNote a)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (i < 0 || i > n.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	n.items[i].SetData(a.GetData());
	n.items[i].SetTags(a.GetTags());

	cout << "������ ��������" << endl;
}

void Del(int index, VectorTNote(&origin))
{
	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// �������� �������
	if (index < 0 || index > origin.count - 1) {
		cout << "������ ��� ���������" << endl;
		return;
	}

	if (origin.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	// ��������� ������
	TNote* vrem = new TNote[origin.count];
	Copy(origin.count, origin.items, vrem, -1);

	origin.items = new TNote[origin.count - 1];

	Copy(origin.count, vrem, origin.items, index);
	origin.count--;

	delete[] vrem;

	cout << "������ �������" << endl;
}

void Search(string t, VectorTNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;
			n.items[i].Print();
			break;
		}
	}

	if (!found) cout << "���������� �� �������" << endl;
}

void Filtration(string t, VectorTNote n)
{
	if (n.count == 0) {
		cout << "������ �����������" << endl;
		return;
	}

	bool found = false; // ���� ��� ������ �� �����

	for (int i = 0; i < n.count; i++) {
		if (n.items[i].Search(t)) {
			found = true;

			n.items[i].Print();
		}
	}

	if (!found) cout << "���������� �� �������" << endl;
}

void Clear(VectorTNote& n)
{
	delete[] n.items;
	n.count;
}

void Init(VectorTNote& n)
{
	n.count = 0;
	n.items = new TNote[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
