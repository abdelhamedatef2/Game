#include <iostream>
using namespace std;
enum enWeapon { Stone = 1, Paper = 2, Scissors = 3 };
enum enRoundWinner { User = 1, Computer = 2, Draw = 3 };
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
int NumerOfRounds()
{
	return ReadPositiveNumber("How many rounds u wanna play 1~10");
}
enWeapon UserChoices()
{
	return (enWeapon)ReadPositiveNumber("Your choice From==>  [1]:Stone, [2]:Paper, [3]:Scissors ?");
}
enWeapon ComputerChoices()
{
	return (enWeapon)RandomNumber(1, 3);
}
enRoundWinner RoundResult(enWeapon& UserChoice, enWeapon& ComputerChoice)
{

	if (UserChoice == enWeapon::Paper && ComputerChoice == enWeapon::Paper)
		return enRoundWinner::Draw;
	else if (UserChoice == enWeapon::Scissors && ComputerChoice == enWeapon::Scissors)
		return enRoundWinner::Draw;
	else if (UserChoice == enWeapon::Stone && ComputerChoice == enWeapon::Stone)
		return enRoundWinner::Draw;
	else if (UserChoice == enWeapon::Stone && ComputerChoice == enWeapon::Paper)
		return enRoundWinner::Computer;
	else if (UserChoice == enWeapon::Stone && ComputerChoice == enWeapon::Scissors)
		return enRoundWinner::User;
	else if (UserChoice == enWeapon::Paper && ComputerChoice == enWeapon::Stone)
		return enRoundWinner::Computer;
	else if (UserChoice == enWeapon::Paper && ComputerChoice == enWeapon::Scissors)
		return enRoundWinner::User;
	else if (UserChoice == enWeapon::Scissors && ComputerChoice == enWeapon::Stone)
		return enRoundWinner::Computer;
	else if (UserChoice == enWeapon::Scissors && ComputerChoice == enWeapon::Paper)
		return enRoundWinner::User;

}
void PrintRoundWeapon(enWeapon UserChoice, enWeapon ComputerChoice)
{
	if (UserChoice == enWeapon::Stone)
		cout << "Player 1 choice : Stone\n";
	else if (UserChoice == enWeapon::Paper)
		cout << "Player 1 choice : Paper\n";
	else if (UserChoice == enWeapon::Scissors)
		cout << "Player 1 choice : Scissors\n";
	if (ComputerChoice == enWeapon::Stone)
		cout << "Computer choice : Stone\n";
	else if (ComputerChoice == enWeapon::Paper)
		cout << "Computer choice : Paper\n";
	else if (ComputerChoice == enWeapon::Scissors)
		cout << "Computer choice : Scissors\n";
}
void PrintRoundWinner(enWeapon UserChoice, enWeapon ComputerChoice)
{
	if (RoundResult(UserChoice, ComputerChoice) == enRoundWinner::Draw)
	{
		cout << "Round Winner    :[Draw]\n";
		system("color 6F");
	}
	else if (RoundResult(UserChoice, ComputerChoice) == enRoundWinner::Computer)
	{
		cout << "Round Winner    :[Computer]\n";
		system("color 4F");
		cout << "\a";
	}
	else if (RoundResult(UserChoice, ComputerChoice) == enRoundWinner::User)
	{
		cout << "Round Winner    :[User]\n";
		system("color 2F");
	}
}
void LoopOfRounds(int& NumberOfRound)
{
	int i = 0, Playerwins = 0, Computerwins = 0, Draws = 0;

	for (i = 1; i <= NumberOfRound; i++)
	{
		cout << "\n\nRound[" << i << "] Begain \n" << endl;
		enWeapon UserChoice = UserChoices();
		enWeapon ComputerChoice = ComputerChoices();
		NumberOfRound;
		cout << "\n\n----------Round[" << i << "]------------------ \n" << endl;
		PrintRoundWeapon(UserChoice, ComputerChoice);
		PrintRoundWinner(UserChoice, ComputerChoice);
		cout << "------------------------------------------" << endl;
		if (RoundResult(UserChoice, ComputerChoice) == enRoundWinner::Computer)
			Computerwins = Computerwins + 1;
		else if (RoundResult(UserChoice, ComputerChoice) == enRoundWinner::User)
			Playerwins = Playerwins + 1;
		else if (RoundResult(UserChoice, ComputerChoice) == enRoundWinner::Draw)
			Draws = Draws + 1;
	}
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t\t+++ G A M E O V E R \n";
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t-----------[Game Result]------------\n";
	cout << "\t\tGame Rounds         : " << NumberOfRound << endl;
	cout << "\t\tPlayer 1 Won Times  : " << Playerwins << endl;
	cout << "\t\tComputer Won Times  : " << Computerwins << endl;
	cout << "\t\tDraw Times          : " << Draws << endl;
	if (Playerwins > Computerwins)
		cout << "\t\tFinal Winner        :  Plyer1" << endl;
	else if (Playerwins < Computerwins)
		cout << "\t\tFinal Winner        :  Computer" << endl;
	else if (Playerwins == Computerwins)
		cout << "\t\tFinal Winner        :  No Winner" << endl;
	cout << "\t\t-----------------------------------\n";

}

int main()
{
	srand((unsigned)time(NULL));
	int NumberOfRound = 0;
	NumberOfRound = NumerOfRounds();
	LoopOfRounds(NumberOfRound);
	bool WantToPlayAgain;
	cout << "wanna play again [1] yes , [2] no \n";
	cin >> WantToPlayAgain;
	if (WantToPlayAgain)
	{
		system("cls");
		system("color 0F");
		int NumberOfRound = 0;
		NumberOfRound = NumerOfRounds();
		LoopOfRounds(NumberOfRound);
		bool WantToPlayAgain;
		cout << "wanna play again [1] yes , [2] no \n";
		cin >> WantToPlayAgain;

	}

}
