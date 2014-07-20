// Brandon Aroas
// 7/6/2014

/*
		Game of Rock, paper, scissors, spock and lizard
		Notes:  I assumed that if the user wants to select spock,  he/she would either type 'k' or 'spock' otherwise, 
				the program will not identitfy the selection as spock because of confusion with "scissors". The other variables can accept  mispelled/single characters/words as inputs
				because the input is unique in that the first letter of the input string is taken to be the first character of the word.

*/

#include <iostream>
#include <cmath>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;



char computer() // Computer generates random choice
	{
		int random = 0; 
		srand(unsigned(time(0))); // seed rand() function
		random = rand() % 5; // generate and limit positive random choices from 0-4
		char computer_choice; // store computer choice;
	


		//assign random number to corresponding choices
		if(random == 0) computer_choice = 'r';
		else if(random == 1) computer_choice = 's';
		else if(random == 2) computer_choice = 'p';
		else if(random == 3) computer_choice = 'l';
		else computer_choice = 'k';

		return computer_choice;
	}


int introduction() // Outputs introduction
	{
		int local_or_comp;
		
		cout << "Hello, welcome to a game of Rock, paper, scissors, lizard and spock\n";
		cout << "This game play's just like rock paper, scissors except with the small two\nadditional variables namely \"spock\" and \"lizard\" \n";
		cout << "With that in mind, lets play\n\n";
		cout << "\t************************************************\n";
		cout << "Enter: \n '1' for Local multiplayer \n '2' for Computer" << endl;
		cin >> local_or_comp;
		
		return local_or_comp;

	}
	
void controls()
	{
		cout << "\t************************************************\n";
		cout << "\tPlease choose 1 of the five variables " <<endl;
		cout << "\tYou can type either the first letter of the\n\tword or the full word." <<endl<<endl;
		cout << "\tFor example: " <<endl;
		cout << "\t\t \'R\' or \'Rock\'" <<endl;
		cout << "\t\t \'P\' or \'Paper\'" <<endl;
		cout << "\t\t \'S\' or \'Scissor\'" <<endl;
		cout << "\t\t \'L\' or \'Lizard\'" <<endl;
		cout << "\t\t \'K\' or \'Spock\'" << endl;
		cout << "\t\t Enter \'q\' to quit" <<endl;
		cout << "\t************************************************\n";
	}




int main()
{	
	int mode;
	int computer_won = 0, user_won = 0, tie = 0;
	int flag_input = 0; // random flag_input integer initialized to initially start while loop
	char computer_choice;
	char again = 'r'; //random character assigment allows loop to initially run 
	string user_input; 


	mode = introduction();// output introduction
	controls(); // output user input controls
	

	while(again != 'q') //loop/game continues until user enters 'q' for quit
	{
		while (flag_input == 0) // loop used to check for valid input
		{
			
			if (mode == 2)
			{	
				computer_choice = computer();// computer generates random choice;
				cin >> user_input; // user inputs data	
			}
			else
			{	
				cout << "Player 1 enter in your choice" <<endl;
				cin >> user_input;
				cout << endl;
				//use computer_choice to store player 2's input
				cout <<"Player 2 enter in your choice" <<endl;
				cin >> computer_choice;
				cout <<endl;
			}
				
			if (user_input[0] == 'R' || user_input[0] == 'r') // if user selects Rock
			{
		
					cout << "You choose Rock" <<endl;
					++flag_input; //valid input: "flag" loop to stop
					
					if (mode == 1)
						{cout <<"Player 2";}
					else 
						{cout <<"Computer";}
					//output based on computers choice
					switch(computer_choice)
					{
						case 'r': {cout<<" chose rock"<< "\nTIE!" <<endl; ++tie; break;} 
						case 'l': {cout<<" choose lizard" <<"\nRock crushes lizard" << "\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 's': {cout<<" chose scissors" <<"\nRock crushes scissors" << "\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 'k': {cout<<" chose spock" <<"\nPlayer1 lost!" <<endl; ++computer_won; break;}
						case 'p': {cout<<" chose paper" <<"\nPlayer1 lost!!"<<endl; ++computer_won; break;}
					}
			}

			else if(user_input[0] == 'P' || user_input[0] == 'p')// if user selects paper
			{
		
					cout <<"You chose Paper" <<endl;
					++flag_input; //valid input: "flag" loop to stop
					
					if (mode == 1)
						{cout <<"Player 2";}
					else 
						{cout <<"Computer";}

					//output based on computers choice 
					switch(computer_choice)
					{
						case 'p': {cout<<" chose paper"<<"\nTIE!" <<endl; ++tie; break;} 
						case 'r': {cout<<" chose rock" <<"\nPaper covers rock" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 'k': {cout<<" chose spock" <<"\nPaper disproves Spock" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 's': {cout<<" chose scissors" <<"\nPlayer1 lost!" <<endl; ++computer_won; break;}
						case 'l': {cout<<" chose lizard" <<"\nPlayer1 lost!!"<<endl; ++computer_won; break;}
					}

			}

			else if(user_input[0] == 'K' || user_input[0] == 'k'|| user_input == "spock") // if user selects spock
			{
			
					cout <<"You choose Spock" <<endl;
					++flag_input; //valid input: "flag" loop to stop
					
					if (mode == 1)
						{cout <<"Player 2";}
					else 
						{cout <<"Computer";}

					//output based on computers choice 
					switch(computer_choice)
					{
						case 'k': {cout<<" chose Spock"<<"\nTIE!" <<endl; ++tie; break;} 
						case's': {cout<<" chose Scissors" <<"\nSpock smashes Scissors" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case'r': {cout<<" chose Rock" <<"\nSpock vaporizes rock" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case'p': {cout<<" chose paper" <<"\nPlayer1 lost!" <<endl; ++computer_won; break;}
						case'l': {cout<<" chose lizard" <<"\nPlayer1 lost!!"<<endl; ++computer_won; break;}
					}
			}

			else if(user_input[0] == 'S' || user_input[0] == 's') // if user selects scissors
			{
		
					cout <<"You choose scissors" <<endl;
					++flag_input; //valid input: "flag" loop to stop
					
					if (mode == 1)
						{cout <<"Player 2";}
					else 
						{cout <<"Computer";}

					//output based on computers choice
					switch(computer_choice)
					{
						case 's': {cout<<" chose Scissors"<<"\nTIE!" <<endl; ++tie; break;}
						case 'p': {cout<<" chose paper" <<"\nScissors cut paper" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 'l': {cout<<" chose lizard" <<"\nScissors decapitate Lizard" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 'r': {cout<<" chose rock" <<"\nPlayer1 lost!" <<endl; ++computer_won; break;}
						case 'k': {cout<<" chose spock" <<"\nPlayer1 lost!!"<<endl; ++computer_won; break;}
					}
	
			}

			else if(user_input[0] == 'L' || user_input[0] == 'l') //if user selects lizard
			{	
		
					cout <<"You chose Lizard" <<endl;
					++flag_input; //valid input: "flag" loop to stop
					
					if (mode == 1)
						{cout <<"Player 2";}
					else 
						{cout <<"Computer";}

					//output based on computers choice 
					switch(computer_choice)
					{
						case 'l': {cout<<" chose Lizard"<<"\nTIE!" <<endl; ++tie; break;}
						case 'k': {cout<<" chose Spock" <<"\nLizard poisons Spock" <<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 'p': {cout<<" chose lizard" <<"\nLizard eats paper"<<"\nPlayer1 Won!!"<<endl; ++user_won; break;}
						case 'r': {cout<<" chose rock" <<"\nPlayer1 lost!" <<endl; ++computer_won; break;}
						case 's': {cout<<" chose scissors" <<"\nPlayer1 lost!!"<<endl; ++computer_won; break;}
					}
			}

			else if(user_input[0] == 'q'|| user_input[0] == 'Q' || computer_choice == 'q' || computer_choice == 'Q')// if user quits
			{
				again = 'q';
				++flag_input;
			}


			else//if all if statements fail then flag_input remains at 0: loop runs again 
			{
				cout <<"Error: input not valid" <<"\nPlease enter a choice listed above\n" <<endl;
			}

		}

	cout <<endl<<endl; 
	flag_input = 0; //"program is complete" clear loop condition: prepare to start game again
	}

	
	
	cout << "Player 1 won " << user_won << " games." <<endl;
	
	if (mode == 1)
		{cout << "Player 2";}
	else
		cout << "Computer";
	
	cout << " won " << computer_won << " games." <<endl;
	cout << "Total Ties: " <<  tie << endl;
	cout << "\n\nGAME ENDED\n\n" <<endl;


return 0;
}




