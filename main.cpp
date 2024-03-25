#include <iostream>
#include <cstring>
using namespace std;


string askForRepsonse(){
    string temp;
    cin >> temp;
    return temp;
}


string lowerCase(string input){
    //makes all letters in string lower case
    string newString = "";
    for(int i = 0; i < input.length(); i++){
        newString += tolower(input[i]);
    }
    return newString;
}

bool ifCorrectResponse(string userResponse){
    //checking to make sure that user inputs only "rock" "paper" or "scissors"
    if(userResponse != "rock" && lowerCase(userResponse) != "paper" && lowerCase(userResponse) != "scissors"){
        return true;
    }
    else{
        return false;
    }
}

void gameResult(string userResponse, string generatedResponse){
    //checks all combinations of answers and prints out who wins
    if(userResponse == "rock"){
        if(generatedResponse == "rock"){
            cout << "Tie!";
        }
        if(generatedResponse == "paper"){
            cout << "You lose!";
        }
        if(generatedResponse == "scissors"){
            cout << "You win!";
        }
    }
    if(userResponse == "paper"){
        if(generatedResponse == "rock"){
            cout << "You win!";
        }
        if(generatedResponse == "paper"){
            cout << "Tie!";
        }
        if(generatedResponse == "scissors"){
            cout << "You lose!";
        }
    }
    if(userResponse == "scissors"){
        if(generatedResponse == "rock"){
            cout << "You lose!";
        }
        if(generatedResponse == "paper"){
            cout << "You win!";
        }
        if(generatedResponse == "scissors"){
            cout << "Tie!";
        }
    }
}


int main() {
    string userResponse;
    cout << "Welcome to a game of Rock, Paper, Scissors!\n";

    //keep asking for an input until the user inputs a valid input (rock,paper,scissors)
    do{
        cout << "Please type 'Rock' 'Paper' or 'Scissors': ";
        userResponse = askForRepsonse();
    }
    while(ifCorrectResponse(userResponse));

    //computer randomly generates their response
    int randNum = rand() % 3;
    string generatedResponse;

    if(randNum == 0){
        generatedResponse = "rock";
    }
    if(randNum == 1){
        generatedResponse = "paper";
    }
    if(randNum == 2){
        generatedResponse = "scissors";
    }

    // prints out what user inputted then what the computer generated followed by the results from the inputs
    cout << "Your response: " << userResponse << "\n" << "Computer response: " << generatedResponse << "\n";
    gameResult(userResponse, generatedResponse);
    cout << "\n";

    //repeats the game after the results unless the user types otherwise
    cout << "Play again? (Type 'yes' to play again or anything else to quit): ";
    string playAgain;
    cin >> playAgain;
    if(lowerCase(playAgain) == "yes"){
        main();
    }

    return 0;
}
