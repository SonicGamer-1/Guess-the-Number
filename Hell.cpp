#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int score = 0;
	int rounds;
	srand(time(0));

	do {
    	cout << "How many rounds do you want to play? ";
    	cin >> rounds;

    	if(cin.fail()) {
        	cout << "Invalid input! Letters are not allowed.\n";
        	cin.clear();
        	cin.ignore(1000, '\n');
    	}
    	else if(rounds <= 0) {
        	cout << "Number of rounds must be at least 1!\n";
    	}

	} while(cin.fail() || rounds <= 0);

	for (int i = 0; i < rounds; i++) //Game Loop
	{
		int x;
		int y = rand() % 10;

		do //Input Validation
		{
			cin.clear();
			cin.ignore(1000, '\n');
			
			cout << "\nThink of a number (0-9): ";
			cin >> x;

			if (cin.fail())
			{
				cout << "Invalid! Letters are not allowed.\n";		
			}
			else if (x < 0 || x > 9)
			{
				cout << "Number must be 0-9!\n";
			}
		} while (cin.fail() || x < 0 || x > 9);

		if (x == y) //Game Logic
		{
			cout << "W\n";
			score++;
		}
		else
		{
			cout << "I guessed " << y << "\n";
		}
	}

	cout << "\nYour Score is " << score; //Score System
}
