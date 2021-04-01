#include "Header.h"

PropertyBase* PropertyBase::instance = nullptr;

PropertyBase* PropertyBase::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new PropertyBase();
		instance->_railwayArray = new Railway[instance->amountStreets];
		instance->_streetArray = new Street[instance->amountStreets];
	}
	return instance;
}

const int PropertyBase::amountRailway = 4;

const int PropertyBase::amountStreets = 5;

void PropertyBase::CreateRailways()
{
	string path = "Propertyes\\Stations.dll";
	WorkingFile work(path.c_str());
	for (int i = 0; i < PropertyBase::amountRailway; i++)
	{
		work.SetProperty(_railwayArray[i].GetProperty());
		work.SettingFromFile();
	}
}

void PropertyBase::CreateStreets()
{
	string path = "Propertyes\\Streets.dll";
	WorkingFile work(path.c_str());
	for (int i = 0; i < PropertyBase::amountStreets; i++)
	{
		work.SetProperty(_streetArray[i].GetProperty());
		work.SettingFromFile();
	}
}

Railway* const PropertyBase::GetRailwayArr() const
{
	return _railwayArray;
}

Street* const PropertyBase::GetStreetArr() const
{
	return _streetArray;
}

PropertyBase::~PropertyBase()
{
	delete[] _railwayArray;
	delete[] _streetArray;
}