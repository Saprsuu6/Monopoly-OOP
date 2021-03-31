#include "Header.h"

WorkingFile::WorkingFile(const char* path)
{
	in.open(path, ios_base::binary);
	rules.open(path);
}


WorkingFile::~WorkingFile()
{
	in.close();
	rules.close();
}

void WorkingFile::SetProperty(Property* property)
{
	_property = property;
}

void WorkingFile::SettingFromFile()
{
	char* buffer = new char[255];
	int nameSize = 0;
	in.read((char*)&nameSize, sizeof(int));
	in.read(buffer, nameSize);
	buffer[nameSize] = '\0';
	string name = buffer;
	_property->SetName(name);

	int colour = 0;
	in.read((char*)&colour, sizeof(int));
	_property->SetColour(colour);

	int price = 0;
	in.read((char*)&price, sizeof(int));
	_property->SetPrice(price);

	int* rent = new int[_property->GetAmountProperties()];
	int size = _property->GetAmountProperties();
	for (int i = 0; i < size; i++)
	{
		in.read((char*)&rent[i], sizeof(int));
	}
	_property->SetRent(rent);

	int collateralValue = 0;
	in.read((char*)&collateralValue, sizeof(int));
	_property->SetCollateralValue(collateralValue);

	delete[] buffer;
	delete[] rent;
}

void WorkingFile::ReadRules()
{
	setlocale(0, "RUS");

	string line;

	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}

	setlocale(0, "C");
}
