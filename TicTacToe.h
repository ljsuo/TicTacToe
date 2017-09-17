//
//  Header.h
//  TicTacToe
//
//  Created by Lester Suo on 7/16/17.
//  Copyright © 2017 Lester Suo. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


class Player{
public:
    friend class Board;
private:
    char symbol;
    bool turn = false;
};

class Board{
public:
    //constructor to initialize the empty playing board
    Board(){
        for (int i = 0; i < 9; i++){
            pos[i] = ' ';
        }
    }
    
    void human_make_move(Player& human){
        cout << "It is your turn. Choose a square to place your move" << endl;
        int square_move;
        cin >> square_move;
        
        while(true){
            
            if(square_move < 0 || square_move > 8){
                cout << "This is an invalid move. Try again" << endl;
                cin >> square_move;
            }
            else if(pos[square_move] != ' '){
                cout << "This is an invalid move. Try again" << endl;
                
                cin >> square_move;
            }
            else{
                pos[square_move] = human.symbol;
                human.turn = false;
                break;
            }

        }
        
    }
    void comp_make_move(Player& comp){
        cout << "It is the computer's turn to make a move" << endl;
        while(true){
            srand(static_cast<unsigned int>(time(0)));
            int move_place = rand() % 9;
            if(pos[move_place] == ' '){
                pos[move_place] = comp.symbol;
                comp.turn = false;
                break;
            }
        }
    }
    void print_board(){
        cout << endl;
        cout << pos[0] << " | " << pos[1] << " | " << pos[2];
        cout << "\n--+---+--\n";
        cout << pos[3] << " | " << pos[4] << " | " << pos[5];
        cout << "\n--+---+--\n";
        cout << pos[6] << " | " << pos[7] << " | " << pos[8];
        cout << endl;
    }
    
    void game_go(Player& human, Player& comp){
        
        cout << "Welcome to this game of TicTacToe!" << endl;
        cout << "A coin toss will decide who goes first" << endl;
        cout << "Choose heads or tails:" << endl;
        string coin_choice;
        cin >> coin_choice;
        
        while(true){
            if (coin_choice == "heads" || coin_choice == "tails"){
                cout << coin_choice << " chosen\n";
                break;
            }
            
            cout << "Invalid choice. Try again" << endl;
            cin >> coin_choice;
        }
        
        string toss_result;
        srand(static_cast<unsigned int>(time(0)));
        int coin_toss = rand();
        if (coin_toss % 2 == 0){
            toss_result = "heads";
        }
        else if (coin_toss % 2 != 0){
            toss_result = "tails";
        }
        
        cout << "The result is " << toss_result << endl;
        if (coin_choice == toss_result){
            cout << "You have won the coin toss. Would you like the first move? Y/N" << endl;
            string yes_no;
            cin >> yes_no;
            
            while(true){
                if (yes_no == "Y" || yes_no == "Yes" ||
                    yes_no == "y" || yes_no == "yes"){
                    human.turn = true;
                    human.symbol = 'X';
                    comp.turn = false;
                    comp.symbol = 'O';
                    break;
                }
                else if (yes_no == "N" || yes_no == "No" ||
                         yes_no == "n" || yes_no == "no"){
                    human.turn = false;
                    human.symbol = 'O';
                    comp.turn = true;
                    comp.symbol = 'X';
                    break;
                }
                cout << "Invalid choice. Try again" << endl;
                cin >> yes_no;
            }
            
        }
        else{
            cout << "You have lost the coin toss. The computer chooses to go first" << endl;
            human.turn = false;
            human.symbol = 'O';
            comp.turn = true;
            comp.symbol = 'X';
        }
        

        
        while(true){
            print_board();
            
            if(human_win(human)){
                break;
            }
            else if (comp_win(comp)){
                break;
            }
            else if (full_board()){
                cout << "Tie game" << endl;
                break;
            }
            else if(human.turn){
                human_make_move(human);
                human.turn = false;
                comp.turn = true;
            }
            else if(comp.turn){
                comp_make_move(comp);
                comp.turn = false;
                human.turn = true;
            }
        }
    }
    
    void game_menu(Player& human, Player& comp){
        bool game_on = true;
        while(game_on){
            game_go(human, comp);
            cout << "Would you like to play again? Y/N" << endl;
            string y_n;
            cin >> y_n;
            if (y_n == "Y" || y_n == "Yes" ||
                y_n == "y" || y_n == "yes"){
                for(int i = 0; i < 9; i++){
                    pos[i] = ' ';
                }
                
                cout << "New game started" << endl;
                continue;
            }
            else if(y_n == "N" || y_n == "No" ||
                    y_n == "n" || y_n == "no"){
                cout << "Quitting" << endl;
                game_on = false;
                break;
            }
            else{
                cout << "Invalid choice. Try again" << endl;
                cin >> y_n;
            }
        }
    }
    
    bool human_win(Player& human){
        int combos[8][3] = {{0,1,2},
                            {0,3,6},
                            {0,4,8},
                            {1,4,7},
                            {2,4,6},
                            {2,5,8},
                            {3,4,5},
                            {6,7,8}}; // winning combinations
        for(int i = 0; i < 8; i++){
            if(pos[combos[i][0]] == pos[combos[i][1]] &&
               pos[combos[i][1]] == pos[combos[i][2]] &&
               pos[combos[i][0]] == human.symbol){
                cout << "Congratulations! You win!" << endl;
                return true;
            }
        }
        return false;
    }
    
    bool comp_win(Player& comp){
        int combos[8][3] = {{0,1,2},
                            {0,3,6},
                            {0,4,8},
                            {1,4,7},
                            {2,4,6},
                            {2,5,8},
                            {3,4,5},
                            {6,7,8}}; // winning combinations
        for(int i = 0; i < 8; i++){
            if(pos[combos[i][0]] == pos[combos[i][1]] &&
               pos[combos[i][1]] == pos[combos[i][2]] &&
               pos[combos[i][0]] == comp.symbol){
                cout << "Sorry, you lost" << endl;
                return true;
            }
        }
        return false;
    }
    
    bool full_board(){
        for (int i = 0; i < 9; i++){
            if (pos[i] == ' '){
                return false;
            }
        }
        cout << "The board is full" << endl;
        return true;
    }
    
private:
    char pos[9] = {0};
    
};



#endif /* Header_h */
