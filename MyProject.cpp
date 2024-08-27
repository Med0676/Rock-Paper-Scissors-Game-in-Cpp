#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTime = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1","Computer","NO Winner" };
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::computer;
        }
        break;

    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::computer;
        }
        break;

    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::computer;
        }
        break;

    }
    // if you here then player1 is the winner.
    return enWinner::Player1;

}

string ChoiceName(enGameChoice choice)
{
    string arrGameChoices[3] = { "Stone","Paper","Scissors" };
    return arrGameChoices[choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); // turn screen to Green
        break;
    case enWinner::computer:
        system("color 4F"); // turn screen to Red
        cout << "\a";
        break;
    default:
        system("color 6F"); // turn screen to Yellow
        break;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________ [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1  choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResult(int GameRounds, short Player1WinTimes, short ComputerWinChoice, short DrawTimes)
{
    stGameResults GameResult;

    GameResult.GameRounds = GameRounds;
    GameResult.Player1WinTime = Player1WinTimes;
    GameResult.Computer2WinTimes = ComputerWinChoice;
    GameResult.DrawTimes = DrawTimes;
    GameResult.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinChoice);
    GameResult.WinnerName = WinnerName(GameResult.GameWinner);
    return GameResult;
}

enGameChoice ReadPlayer1Choice()
{
    short choice = 1;

    do
    {
        cout << "\nYour Choice : [1]:stone, [2]:Paper, [3]Scissors ? ";
        cin >> choice;

    } while (choice < 1 || choice > 3);
    return (enGameChoice)choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRound)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRound; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begin:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        //Increase win/Draw counters
        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::computer)
            ComputerWinTimes++;
        else
            DrawTimes++;
        PrintRoundResults(RoundInfo);
    }
    return FillGameResult(HowManyRound, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
    string t = "";

    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________\n\n";
    cout << Tabs(2) << "             +++ G a m e O v e r +++\n";
    cout << Tabs(2) << "__________________________________________________\n\n";
}

void ShowFinalGameResult(stGameResults GameResult)
{
    cout << Tabs(2) << "____________________[Game Result ]__________________________\n\n";
    cout << Tabs(2) << "Game Round         : " << GameResult.GameRounds << endl;
    cout << Tabs(2) << "Player1 won times  : " << GameResult.Player1WinTime << endl;
    cout << Tabs(2) << "Computer won times : " << GameResult.Computer2WinTimes << endl;
    cout << Tabs(2) << "Draw times         : " << GameResult.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResult.WinnerName << endl;
    cout << Tabs(2) << "____________________________________________________________\n\n";
    SetWinnerScreenColor(GameResult.GameWinner);
}

short ReadHowManyRounds()
{
    short GameRound = 1;

    do
    {
        cout << "How Many Round 1 to 10 ?\n";
        cin >> GameRound;
    } while (GameRound < 1 || GameRound >10);
    return GameRound;
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

short ReadHowManyRound()
{
    short GameRounds = 1;

    do 
    {
        cout << "How Many Rounds 1 To 10 ? \n";
        cin >> GameRounds;

    } while (GameRounds < 1 || GameRounds>10);
    return GameRounds;
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResult(GameResults);

        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    
    
    StartGame();
    

    return 0;
}