#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int RandomNumber(int& computer_choice, int from, int to)
{
    //Function to generate a random number
    computer_choice = rand() % (to - from + 1) + from;
    return computer_choice;
}

int raed_rounds_number(int& number_of_rounds)
{
    cout << "How Many Rounds You Want To Play? ";
    cin >> number_of_rounds;

    while (number_of_rounds <= 0)
    {
        cout << "number of rounds must be bigger than 0 ,enter howmany rounds you want to play again: ";
        cin >> number_of_rounds;
    }
    return number_of_rounds;
}


int  start_round(int& player_choice, int round_number)
{
    cout << "round [" << round_number << "] begins \n";
    cout << "Your choice [1]:Stone , [2]:Paper , [3]:Scissor : ";
    cin >> player_choice;
    while (player_choice < 1 || player_choice > 3)
    {
        cout << "wrong choice you must choice 1 ,2 or 3 , enter number again ";
        cin >> player_choice;
    }
    return player_choice;
}

enum en_game { stone = 1, paper = 2, scissor = 3 };

string convert_choose(int choice)
{

    switch (choice)
    {
    case en_game::stone:
        return "STONE";
    case en_game::paper:
        return "PAPER";
    case en_game::scissor:
        return "SCISSOR";
    }
}

void round_result(int player_choice, int computer_choice)
{
    cout << endl;
    if (player_choice == computer_choice)
    {
        cout << "       YOUR CHOICE IS " << convert_choose(player_choice) << "\n";
        cout << "       COMPUTER CHOICE IS " << convert_choose(computer_choice) << "\n";
        cout << "       Result is DRAW\n";
        //system("color 1F"); //turn screen to yellow
        cout << "\a"; //make alert sound
    }
    else if ( (( player_choice == en_game::paper)   &&  (computer_choice == en_game::stone   )) ||
              (( player_choice == en_game::stone)   &&  (computer_choice == en_game::scissor )) ||
              (( player_choice == en_game::scissor) &&  (computer_choice == en_game::paper   )) )
    {
        cout << "       YOUR CHOICE IS " << convert_choose(player_choice) << "\n";
        cout << "       COMPUTER CHOICE IS " << convert_choose(computer_choice) << "\n";
        cout << "       YOU WIN \n";
        //system("color 2F"); //turn screen to green
        cout << "\a"; //make alert sound
    }
    else if ( ((computer_choice == en_game::paper)   &&  (player_choice == en_game::stone   )) ||
              ((computer_choice == en_game::stone)   &&  (player_choice == en_game::scissor )) ||
              ((computer_choice == en_game::scissor) &&  (player_choice == en_game::paper   )) )
    {
        cout << "       YOUR CHOICE IS " << convert_choose(player_choice) << "\n";
        cout << "       COMPUTER CHOICE IS " << convert_choose(computer_choice) << "\n";
        cout << "       COMPUTER WINS \n";
        //system("color 4F"); //turn screen to red
        cout << "\a"; //make alert sound
    }
    cout << endl;
}


void game(int number_of_rounds, int& computer_choice, int player_choice)
{
    for (int i = 1; i <= number_of_rounds; i++)
    {
        RandomNumber(computer_choice, 1, 3);
        cout << "========================================================================\n";
        start_round(player_choice, i);
        round_result(player_choice, computer_choice);
    }

}

void start_restart_game(int &number_of_rounds, int &computer_choice, int &player_choice )
{
    string play_again = "";
    do
    {
        raed_rounds_number(number_of_rounds);
        game(number_of_rounds, computer_choice, player_choice); 
        do
        {
            cout << "GAME HAS ENDED ,DO YOU WANT TO PLAY AGAIN ? [ Y or N ]: \n";
            cin >> play_again;
        } while ( (play_again != "Y" ) && ( play_again != "y" ) && ( play_again != "N" ) && ( play_again != "n" ) );
        //system("color 0F"); //turn screen to black
    } while (play_again == "y" || play_again == "Y");

    cout << "           GOOD BYE";
}

int main()
{
    srand((unsigned)time(NULL));

    int number_of_rounds = 0;
    int computer_choice = 0;
    int player_choice = 0;

    start_restart_game(number_of_rounds, computer_choice, player_choice );
    return 0;
}
