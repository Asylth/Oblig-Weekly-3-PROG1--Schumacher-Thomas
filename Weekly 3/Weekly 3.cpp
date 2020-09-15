#include <iostream>
#include <cstdlib>
#include <ctime>

void rightwrong();
void postgame();


int difficulity;		//desides difficulity
int toguess;			//the number to guess
int guess;				//user guess input
char yesno;				//continue game after playing
//char changediff;		//keep playing current difficulity or switch. not currently implemented
bool contrw = true;		//continue the right/wrong function
bool run = true;		//controls the main function
int globalcounter;		//tracks the score of player (number of guesses)
int hscore = 100;		//default high score
int yscore = 0;			//player score


//make a guess a number game
int main()
{
	//main menu with difficulity select.
	while (run == true){

		std::cout << "Select a difficulity \n";
		std::cout << "1. Easy (1-5) \n";
		std::cout << "2. Normal (1-10) \n";
		std::cout << "3. Hard (1-30) \n";
		std::cout << "Difficulity: ";
		std::cin >> difficulity;

			switch (difficulity) {
			case 1:
				std::srand(std::time(NULL));
				toguess = rand() % 5 + 1;
				contrw = true;
				rightwrong();
				break;
			case 2:
				std::srand(std::time(NULL));
				toguess = rand() % 10 + 1;
				contrw = true;
				rightwrong();
				break;
			case 3:
				std::srand(std::time(NULL));
				toguess = rand() % 30 + 1;
				contrw = true;
				rightwrong();
				break;
			default:
				std::cout << "Enter a valid difficulity \n";
				break;
			}
	}

}

//checks if the guess of user is higher, lower or equal to the random number
void rightwrong() {

	do {

		std::cout << "Try to guess my number: \n";
		std::cin >> guess;
		globalcounter++;

		if (guess == toguess) {
			std::cout << std::endl << "You guessed the right number! \n";
			contrw = false;
			postgame();
		}
		else if (guess < toguess) {
			std::cout << std::endl << "Your guess is to low \n";

		}
		else if (guess > toguess) {
			std::cout << std::endl << "Your guess is to high \n";

		}
		//else { //does not work for now, may add this later
		//	std::cout << std::endl << "Enter a valid guess \n";
		//}

	} while (contrw == true);
}

//post game screen where user sees their score and the current high score
//also promts user if they want to play again
void postgame() {
	
	yscore = globalcounter;

	if (yscore < hscore) {
		std::cout << "Your score " << yscore;
		hscore = yscore;
		std::cout << " is lower than the previous bestscore " << hscore << std::endl;
	}
	else if (yscore > hscore) {
		std::cout << "Your score " << yscore << " is higher than the bestscore " << hscore << std::endl;
	}
	else if (yscore == hscore) {
		std::cout << "Your score " << yscore << " is equal to the bestscore" << std::endl;
	}

	
		std::cout << "Highscore: " << hscore << std::endl;
		std::cout << "Your score: " << yscore << std::endl;

	globalcounter = 0;
	std::cout << "\n Do you want to continue the game (Y/N): "; //add option to continue playing current diff or change it (and del scores)
	std::cin >> yesno;
	switch (yesno) {
	case 'Y':case 'y':
		run = true;
		break;
	case 'N':case 'n':
		run = false;
		break;
	}
	std::cout << "Do you want to keep playing with the same difficulity (Y) or switch (N)? \n";
	std::cout << "A switch will result in your scores being deleted. \n";

	/*switch (changediff) { //may add difficulity dependent scores and highscors later
		case 'Y':case 'y':
			;
			break;
		case 'N':case 'n':
			run = true;
			break;
		}*/
	
}
