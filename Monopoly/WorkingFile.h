#pragma once
class WorkingFile
{
private:
	ifstream in;
	ifstream rules;
	Property* _property = nullptr;
public:
	WorkingFile(const char* path);
	~WorkingFile();

	void SetProperty(Property* property);

	void SettingFromFile();
	void ReadRules();
};

