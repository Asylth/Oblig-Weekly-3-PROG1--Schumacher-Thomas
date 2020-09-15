#include <iostream>
#include <cstdlib>
#include <ctime>

void rightwrong();
void continuegame();

int toguess;
int guess;
char yesno;
bool contrw = true;
bool run = true;
int globalcounter;



//make a guess a number game
int main()
{
	while (run == true){

		std::srand(std::time(NULL));
		toguess = rand() % 10 + 1;

		rightwrong();

	};

}

void rightwrong() {

	do {
		for (globalcounter = 0; globalcounter++;) {
			
		}

		std::cout << "Try to guess my number: ";
		std::cin >> guess;

		if (guess == toguess) {
			std::cout << std::endl << "You guessed the right number! \n";
			contrw = false;
			continuegame();
		}
		else if (guess < toguess) {
			std::cout << std::endl << "Your guess is to low \n";

		}
		else if (guess > toguess) {
			std::cout << std::endl << "Your guess is to high \n";

		}
		else {//go again
			std::cout << std::endl << "Enter a valid guess \n";
		}

	} while (contrw == true);
}

void continuegame() {

	std::cout << "\n Do you want to continue the game (Y/N): ";
	std::cin >> yesno;

	switch (yesno) {
	case 'Y':case 'y':
		run = true;
		break;
	case 'N':case 'n':
		run = false;
		break;
	}
}