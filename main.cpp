//
//  main.cpp
//  TicTacToe
//
//  Created by Lester Suo on 7/16/17.
//  Copyright © 2017 Lester Suo. All rights reserved.
//

#include <iostream>
#include "TicTacToe.h"

int main(int argc, const char * argv[]) {
    Board b;
    Player comp;
    Player human;
    //b.game_start(human, comp);
    b.game_menu(human, comp);
    //b.print_board();
    return 0;
}
