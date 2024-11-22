#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

void animate_text(const string& text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50)); // Typing effect speed
    }
    cout << endl;
}

void display_choice_animation(const string& choice) {
    string animation[] = {"|", "/", "-", "\\"};
    for (int i = 0; i < 4; i++) {
        cout << "\rComputer is choosing " << animation[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << "\rComputer chose " << choice << "!" << endl;
}

class RockPaperScissiors {
    int User_choice;
    int System_choice;
    char play_again;

public:
    RockPaperScissiors() {
        User_choice = 0;
        System_choice = 0;
        srand(time(0));
    }

    void input() {
        animate_text("Hello user, welcome to rock paper scissors. Enter your choice and let's play the game:");
        animate_text("1. Rock \n2. Paper \n3. Scissors");
        cin >> User_choice;
    }

    void process() {
        System_choice = rand() % 3 + 1;

        string choices[] = {"Rock", "Paper", "Scissors"};

        display_choice_animation(choices[System_choice - 1]);

        if (System_choice == User_choice) {
            animate_text("It's a tie!");
        }
        else if (User_choice == 1) {
            if (System_choice == 2) animate_text("Paper covers Rock - You lose!");
            else animate_text("Rock crushes Scissors - You win!");
        }
        else if (User_choice == 2) {
            if (System_choice == 3) animate_text("Scissors cuts Paper - You lose!");
            else animate_text("Paper covers Rock - You win!");
        }
        else if (User_choice == 3) {
            if (System_choice == 1) animate_text("Rock crushes Scissors - You lose!");
            else animate_text("Scissors cuts Paper - You win!");
        }
    }

    bool play_more() {
        animate_text("\nWould you like to play again? (y/n): ");
        cin >> play_again;
        return (play_again == 'y' || play_again == 'Y');
    }
};

int main() {
    RockPaperScissiors game;
    do {
        game.input();
        game.process();
    } while (game.play_more());

    animate_text("\nThanks for playing!");
    return 0;
}
