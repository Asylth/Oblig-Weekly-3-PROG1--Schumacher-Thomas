#include <iostream>
#include <cstdlib>
#include <ctime>

void rightwrong();
void continuegame();
//int counter();

int toguess;
int guess;
char yesno;
bool contrw = true;
bool run = true;
int globalcounter = 1;
int hscore = 100;
int yscore;

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
		else { //does not work for now
			std::cout << std::endl << "Enter a valid guess \n";
		}

		globalcounter++;

	} while (contrw == true);
}

void continuegame() {
	
	globalcounter = yscore;

	if (yscore < hscore) {
		std::cout << "Your score " << yscore << " is lower than the highscore " << hscore << std::endl;
		yscore = hscore;
	}
	else if (yscore > hscore) {
		std::cout << "Your score " << yscore << " is higher than the highscore " << hscore << std::endl;
	}
	else if (yscore == hscore) {
		std::cout << "Your score " << yscore << " is equal to the highscore" << std::endl;
	}

	std::cout << "Highscore: " << hscore << std::endl;
	std::cout << "Your score: " << globalcounter << std::endl;
	

	globalcounter = 0;
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
