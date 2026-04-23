#include <iostream>
#include <cstdlib>
using namespace std;
enum enchoice { rock = 1, paper = 2, scissors = 3 };

struct stroundinfo
{
	int rounds;
	enchoice player;
	enchoice computer;
	int scoreplayer;
	int scorecomputer;
	int draw;

};

int numberofrounds()
{
	int round;
	do
	{
		cout << "How many rounds do you want to play 1 to 10 ?  ";
		cin >> round;
	} while (round < 0 || round>10);

	return round;
}

int randomnumber(int from, int to)
{
	return (from - to + 1) + to;
}

void judging(enchoice choiceplayer, enchoice choicecomputer)
{

	if (choiceplayer == enchoice::rock && choicecomputer == enchoice::scissors)
	{
		cout << "\n PLAYER WINS\n";

		cout << "\nThe PLAYER chose : " << " ROCK " << endl;
		cout << "\nThe COMPUTER chose : " << " SCISSORS " << endl;

		system("color 2F");

	}
	else if (choiceplayer == enchoice::rock && choicecomputer == enchoice::paper)
	{
		cout << "\nCOMPUTER WINS\n";

		cout << "\nThe PLAYER chose : " << " ROCK " << endl;
		cout << "\nThe COMPUTER chose : " << " PAPER " << endl;

		system("color 4F"); cout << "\a";

	}
	else if (choiceplayer == enchoice::paper && choicecomputer == enchoice::rock)
	{
		cout << "\n PLAYER WINS\n";

		cout << "\nThe PLAYER chose : " << " PAPER " << endl;
		cout << "\nThe COMPUTER chose : " << " ROCK " << endl;

		system("color 2F");

	}
	else if (choiceplayer == enchoice::paper && choicecomputer == enchoice::scissors)
	{
		cout << "\nCOMPUTER WINS\n";

		cout << "\nThe PLAYER chose : " << " PAPER " << endl;
		cout << "\nThe COMPUTER chose : " << " SCISSORS " << endl;

		system("color 4F"); cout << "\a";

	}
	else if (choiceplayer == enchoice::scissors && choicecomputer == enchoice::paper)
	{
		cout << "\n PLAYER WINS\n";

		cout << "\nThe PLAYER chose : " << " SCISSORS " << endl;
		cout << "\nThe COMPUTER chose : " << " PAPER " << endl;

		system("color 2F");

	}
	else if (choiceplayer == enchoice::scissors && choicecomputer == enchoice::rock)
	{
		cout << "\nCOMPUTER WINS\n";

		cout << "\nThe PLAYER chose : " << " SCISSORS " << endl;
		cout << "\nThe COMPUTER chose : " << " ROCK " << endl;

		system("color 4F"); cout << "\a";

	}
	else
	{
		cout << "\nDRAW no one won\n";
		if (choiceplayer == enchoice::rock)
		{
			cout << "\nThe PLAYER chose : " << " ROCK " << endl;
			cout << "\nThe COMPUTER chose : " << " ROCK " << endl;
		}
		else if (choiceplayer == enchoice::paper)
		{
			cout << "\nThe PLAYER chose : " << " PAPER " << endl;
			cout << "\nThe COMPUTER chose : " << " PAPER " << endl;
		}
		else
		{
			cout << "\nThe PLAYER chose : " << " SCISSORS " << endl;
			cout << "\nThe COMPUTER chose : " << " SCISSORS " << endl;
		}
		system("color 6F");
	}
}

enchoice playerchoice()
{
	cout << "\nPlease enter ur choice  Rock [1] - Paper [2] - scissors [3]. \n";

	int choice;
	cin >> choice;

	while (choice > 3)
	{
		cout << "Please choose a valid number (from 1 to 3).\n";
		cin >> choice;
	}


	return (enchoice)choice;
}

enchoice computerchoice()
{
	int n = randomnumber(1, 3);
	return (enchoice)n;
}

void reset()
{
	system("cls");
	system("color 0F");
}

void gameover(stroundinfo round)
{
	cout << "\n ------------------------- ROUND ENDED ------------------------- \n";
	cout << "\nRounds played = " << round.rounds << endl;
	cout << "\nPlayer score = " << round.scoreplayer << endl;
	cout << "\nComputer score = " << round.scorecomputer << endl;
	cout << "\nDraw times = " << round.draw << endl;

	if (round.scoreplayer > round.scorecomputer)
	{
		cout << "\nPLAYER WINS\n";
	}
	else
	{
		cout << "\nCOMPUTER WINS\n";
	}
	cout << "\n -------------------------------------------------------------- \n";
}
stroundinfo eachround()
{
	stroundinfo round;

	round.rounds = numberofrounds();

	int scorep = 0;
	int scorec = 0;
	int draw = 0;
	for (int i = 1; i <= round.rounds; i++)
	{
		round.player = playerchoice();
		round.computer = computerchoice();




		cout << "\n ROUND [" << i << "] : \n";
		judging(round.player, round.computer);

		if (round.player == enchoice::rock && round.computer == enchoice::scissors)scorep++;
		else if (round.scoreplayer == enchoice::paper && round.scorecomputer == enchoice::rock)scorep++;
		else if (round.player == enchoice::scissors && round.computer == enchoice::paper)scorep++;

		if (round.player == enchoice::rock && round.computer == enchoice::paper)scorec++;
		else if (round.scoreplayer == enchoice::paper && round.scorecomputer == enchoice::scissors)scorec++;
		else if (round.scoreplayer == enchoice::scissors && round.scorecomputer == enchoice::rock)scorec++;

		if (round.player == round.computer)draw++;

		round.scoreplayer = scorep;
		round.scorecomputer = scorec;
		round.draw = draw;

		cout << "\n--------------------------------------------------\n";
	}
	return round;

}

void startgame()
{
	char cont = 'y';

	do
	{
		reset();
		gameover(eachround());
		cout << "\nDo you want to continue (Y Or N)? \n";
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
}

int main()
{
	startgame();
}
