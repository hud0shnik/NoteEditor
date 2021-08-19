#include "Note.h"

Note::Note()
{
	data.createDate.day = 0;
	data.createDate.month = 0;
	data.createDate.year = 0;
	data.editDate.day = 0;
	data.editDate.month = 0;
	data.editDate.year = 0;
	data.note = "";
	data.title = "";
}

Note::~Note()
{
}
