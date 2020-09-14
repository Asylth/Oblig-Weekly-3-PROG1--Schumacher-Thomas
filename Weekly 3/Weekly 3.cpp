#include <iostream>
#include <cstdlib>
#include <ctime>

int toguess;
int guess;
bool cont = true;
bool run = true;


//make a guess a number game
int main()
{
	while (run == true){

		std::srand(std::time(NULL));
		toguess = rand() % 10 + 1;

		std::cout << "Try to guess my number: ";
		std::cin >> guess;

	};

}

void rightwrong() {

	do {

		for (int guesscount = 0; ++guesscount;) {
			std::cout << "Nr of Guesses: " << guesscount << std::endl;
		}



	} while (cont == true);

}

