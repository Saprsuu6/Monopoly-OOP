#include"Header.h"

int main()
{
	GameEngine* gameplay = gameplay->GetInstance();

	while (true)
	{
		if (gameplay->StartMenu())
		{
			break;
		}
		gameplay->MusikStart();
		gameplay->Playing();
	}

	cout << "Hello world" << endl;

	cout << "it's final" << endl;
}