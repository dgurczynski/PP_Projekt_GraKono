// DOMINIK GURCZYŃSKI S203854 ACIR 2A - GRA a la KONO

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

const int BOARD_SIZE = 4;
const int NAME_LENGHT = 15;
const int INPUT_LENGHT = 5;
const char BLACK = 'c';
const char WHITE = 'b';
const char EMPTY = ' ';

char board[BOARD_SIZE][BOARD_SIZE] = {
    {BLACK, BLACK, BLACK, BLACK},
    {EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY},
    {WHITE, WHITE, WHITE, WHITE}
};

void display_board(char board[BOARD_SIZE][BOARD_SIZE]) { 
    char separator_symbol = char(186);
    char row_symbol = char(205);
    std::cout << "    A   B   C   D\n";
    std::cout << "  " << char(201) << row_symbol << row_symbol << row_symbol << char(203) << row_symbol << row_symbol << row_symbol << char(203) << row_symbol << row_symbol << row_symbol << char(203) << row_symbol << row_symbol << row_symbol << char(187) << std::endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i != 0) {
            std::cout << "  " << char(204) << row_symbol << row_symbol << row_symbol << char(206) << row_symbol << row_symbol << row_symbol << char(206) << row_symbol << row_symbol << row_symbol << char(206) << row_symbol << row_symbol << row_symbol << char(185) << std::endl;
        }
        std::cout << 4 - i << " " << separator_symbol;
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << " " << board[i][j] << " " << separator_symbol;
        }
        std::cout << "\n";
    }
    std::cout << "  " << char(200) << row_symbol << row_symbol << row_symbol << char(202) << row_symbol << row_symbol << row_symbol << char(202) << row_symbol << row_symbol << row_symbol << char(202) << row_symbol << row_symbol << row_symbol << char(188) << std::endl;
    std::cout << "    A   B   C   D\n";
}

void move(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_column, int end_row, int end_column) {
    board[end_row][end_column] = board[start_row][start_column];
    board[start_row][start_column] = EMPTY;
}

int get_index(char input) {
    if (std::isalpha(input)) {
        int index = input - 'A';
        return index;
    }
    if (std::isdigit(input)) {
        int index = 4 - (input - '0');
        return index;
    }
    return -1;
}

bool player_translate_input(char player_input[INPUT_LENGHT], int& start_row, int& start_column, int& end_row, int& end_column) {
    if (start_row == -1 || start_column == -1 || end_row == -1 || end_column == -1) {
        return false;
    }
    if (player_input[2] != '-') {
        return false;
    }
    start_row = get_index(player_input[1]);
    start_column = get_index(toupper(player_input[0]));
    end_row = get_index(player_input[4]);
    end_column = get_index(toupper(player_input[3]));
    return true;
}

void player_process_move(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_column, int end_row, int end_column) {
    int row_difference = start_row - end_row;
    int column_difference = start_column - end_column;

    if (row_difference == -2 && column_difference == 0) {
        int middle_row = start_row + 1;
        int middle_column = start_column;
        if (board[middle_row][middle_column] == BLACK && board[end_row][end_column] == EMPTY) {
            if (board[end_row + 1][end_column] == WHITE) {
                move(board, start_row, start_column, end_row + 1, end_column);
            }
        }
    }
    else if (row_difference == 2 && column_difference == 0) {
        int middle_row = start_row - 1;
        int middle_column = start_column;
        if (board[middle_row][middle_column] == BLACK && board[end_row][end_column] == EMPTY) {
            if (board[end_row - 1][end_column] == WHITE) {
                move(board, start_row, start_column, end_row - 1, end_column);
            }
        }
    }
    else if (row_difference == 0 && column_difference == -2) {
        int middle_row = start_row;
        int middle_column = start_column + 1;
        if (board[middle_row][middle_column] == BLACK && board[end_row][end_column] == EMPTY) {
            if (board[end_row][end_column + 1] == WHITE) {
                move(board, start_row, start_column, end_row, end_column + 1);
            }
        }
    }
    else if (row_difference == 0 && column_difference == 2) {
        int middle_row = start_row;
        int middle_column = start_column - 1;
        if (board[middle_row][middle_column] == BLACK && board[end_row][end_column] == EMPTY) {
            if (board[end_row][end_column - 1] == WHITE) {
                move(board, start_row, start_column, end_row, end_column - 1);
            }
        }
    }
    else if (row_difference == -1 && column_difference == 0) {
        if (board[start_row][start_column] == BLACK && board[end_row][end_column] == EMPTY) {
            move(board, start_row, start_column, end_row, end_column);
        }
    }
    else if (row_difference == 1 && column_difference == 0) {
        if (board[start_row][start_column] == BLACK && board[end_row][end_column] == EMPTY) {
            move(board, start_row, start_column, end_row, end_column);
        }
    }
    else if (row_difference == 0 && column_difference == -1) {
        if (board[start_row][start_column] == BLACK && board[end_row][end_column] == EMPTY) {
            move(board, start_row, start_column, end_row, end_column);
        }
    }
    else if (row_difference == 0 && column_difference == 1) {
        if (board[start_row][start_column] == BLACK && board[end_row][end_column] == EMPTY) {
            move(board, start_row, start_column, end_row, end_column);
        }
    }
}

bool player_check_move(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_column, int end_row, int end_column) {
    if (board[start_row][start_column] == EMPTY || board[end_row][end_column] != EMPTY) {
        return false;
    }
    if (start_row < 0 || start_row >= BOARD_SIZE || start_column < 0 || start_column >= BOARD_SIZE) {
        return false;
    }
    if (end_row < 0 || end_row >= BOARD_SIZE || end_column < 0 || end_column >= BOARD_SIZE) {
        return false;
    }
    return true;
}


void bot_possible_moves(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_column) {
    int possible_moves_list[BOARD_SIZE * BOARD_SIZE][2];
    int index = 0;

    if (board[start_row + 1][start_column] == WHITE && board[start_row + 2][start_column] == EMPTY && board[start_row + 3][start_column] == BLACK && start_row + 3 < 4) {
        int end_row = start_row + 3;
        int end_column = start_column;
        move(board, start_row, start_column, end_row, end_column);
    }
    if (board[start_row - 1][start_column] == WHITE && board[start_row - 2][start_column] == EMPTY && board[start_row - 3][start_column] == BLACK && start_row - 3 >= 0) {
        int end_row = start_row - 3;
        int end_column = start_column;
        move(board, start_row, start_column, end_row, end_column);
    }
    if (board[start_row][start_column + 1] == WHITE && board[start_row][start_column + 2] == EMPTY && board[start_row][start_column + 3] == BLACK && start_column + 3 < 4) {
        int end_row = start_row;
        int end_column = start_column - 3;
        move(board, start_row, start_column, end_row, end_column);
    }
    if (board[start_row][start_column - 1] == WHITE && board[start_row][start_column - 2] == EMPTY && board[start_row][start_column - 3] == BLACK && start_column - 3 >= 0) {
        int end_row = start_row;
        int end_column = start_column + 3;
        move(board, start_row, start_column, end_row, end_column);
    }
    if (board[start_row + 1][start_column] == EMPTY && start_row + 1 < 4) {
        possible_moves_list[index][0] = start_row + 1;
        possible_moves_list[index][1] = start_column;
        index++;
    }
    if (board[start_row - 1][start_column] == EMPTY && start_row - 1 >= 0) {
        possible_moves_list[index][0] = start_row - 1;
        possible_moves_list[index][1] = start_column;
        index++;
    }
    if (board[start_row][start_column + 1] == EMPTY && start_column + 1 < 4) {
        possible_moves_list[index][0] = start_row;
        possible_moves_list[index][1] = start_column + 1;
        index++;
    }
    if (board[start_row][start_column - 1] == EMPTY && start_column - 1 >= 0) {
        possible_moves_list[index][0] = start_row;
        possible_moves_list[index][1] = start_column - 1;
        index++;
    }
    int end_row = start_row;
    int end_column = start_column;

    if (index > 0) {
        int random_index = rand() % index;
        int end_row = possible_moves_list[random_index][0];
        int end_column = possible_moves_list[random_index][1];

        move(board, start_row, start_column, end_row, end_column);
    }
}

void bot_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int positions[BOARD_SIZE * BOARD_SIZE][2];
    int index = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == WHITE) {
                positions[index][0] = i;
                positions[index][1] = j;
                index++;
            }
        }
    }

    if (index > 0) {
        srand(time(0));
        int random_index = rand() % index;

        int start_row = positions[random_index][0];
        int start_column = positions[random_index][1];
        bot_possible_moves(board, start_row, start_column);
    } 
}


char is_pawn_blocked(char board[BOARD_SIZE][BOARD_SIZE], char pawn_type) {
    int possible_moves = 0;
    int pawns_count = 0;
    int pawns_blocked = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == pawn_type) {
                pawns_count++;
                int start_row = i;
                int start_column = j;

                if (board[start_row + 1][start_column] == WHITE && board[start_row + 2][start_column] == EMPTY && board[start_row + 3][start_column] == BLACK && start_row + 3 < 4) {
                    possible_moves++;
                }
                if (board[start_row - 1][start_column] == WHITE && board[start_row - 2][start_column] == EMPTY && board[start_row - 3][start_column] == BLACK && start_row - 3 >= 0) {
                    possible_moves++;
                }
                if (board[start_row][start_column + 1] == WHITE && board[start_row][start_column + 2] == EMPTY && board[start_row][start_column + 3] == BLACK && start_column + 3 < 4) {
                    possible_moves++;
                }
                if (board[start_row][start_column - 1] == WHITE && board[start_row][start_column - 2] == EMPTY && board[start_row][start_column - 3] == BLACK && start_column - 3 >= 0) {
                    possible_moves++;
                }
                if (board[start_row + 1][start_column] == EMPTY && start_row + 1 < 4) {
                    possible_moves++;
                }
                if (board[start_row - 1][start_column] == EMPTY && start_row - 1 >= 0) {
                    possible_moves++;
                }
                if (board[start_row][start_column + 1] == EMPTY && start_column + 1 < 4) {
                    possible_moves++;
                }
                if (board[start_row][start_column - 1] == EMPTY && start_column - 1 >= 0) {
                    possible_moves++;
                }

                if (possible_moves == 0) {
                    pawns_blocked++;
                }
            }
        }
    }
    if (pawns_count == pawns_blocked) {
        return pawn_type;
    }
    else {
        return EMPTY;
    }
}

char is_game_won(char board[BOARD_SIZE][BOARD_SIZE]) {
    int black_count = 0, white_count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == BLACK) {
                black_count++;
            }
            else if (board[i][j] == WHITE) {
                white_count++;
            }
        }
    }

    if (black_count == 0) {
        return BLACK;
    }
    else if (white_count == 0) {
        return WHITE;
    }
    else {
        return EMPTY;
    }
}


int main() {
    char bot_player[NAME_LENGHT], user_player[NAME_LENGHT], player_move_input[INPUT_LENGHT];
    int start_row, end_row, start_column, end_column;
    std::cout << "===========================================  Witaj w grze planszowej Kono!  ===========================================" << std::endl;
    std::cout << "\n";

    std::cout << "Podaj imie BOTA (BIALY - b): ";
    std::cin >> bot_player;
    std::cout << "Podaj imie GRACZA (CZARNY - c): ";
    std::cin >> user_player;
    std::cout << "\n";

    while (true) {
        char winner = is_game_won(board);
        
        if (winner != EMPTY) {
            if (winner == WHITE) {
                std::cout << bot_player << "(BIALY) wygral gre!" << std::endl;
                break;
            }
            if (winner == BLACK) {
                std::cout << user_player << "(CZARNY) wygral gre!" << std::endl;
                break;
            }
        }
        
        std::cout << "==================================================================================" << std::endl;
        std::cout << bot_player << " (BIALY) wykonal ruch: " << std::endl;
        std::cout << "\n";
        bot_move(board);

        display_board(board);

        std::cout << "\n";
        std::cout << "==================================================================================" << std::endl;
        std::cout << user_player << " (CZARNY) - Podaj pozycje ruchu np (A4-A3): ";
        std::cin >> player_move_input;

        if (player_translate_input(player_move_input, start_row, start_column, end_row, end_column) && player_check_move(board, start_row, start_column, end_row, end_column)) {
            if (board[start_row][start_column] == BLACK) {
                player_process_move(board, start_row, start_column, end_row, end_column);
            }
            else {
                std::cout << "Podano nieprawidlowe dane, sprobuj ponownie!" << std::endl;
            }
        }
        else {
            std::cout << "Podano nieprawidlowe dane, sprobuj ponownie!" << std::endl;
        }

        display_board(board);

        char blocked_pawn = is_pawn_blocked(board, WHITE);
        if (blocked_pawn != EMPTY) {
            std::cout << user_player << "(CZARNY) wygral gre! Biale pionki zostaly zablokowane!!" << std::endl;
            break;
        }

        blocked_pawn = is_pawn_blocked(board, BLACK);
        if (blocked_pawn != EMPTY) {
            std::cout << bot_player << "(BIALY) wygral gre! Czarne pionki zostaly zablokowane!!" << std::endl;
            break;
        }
    }
    return 0;
}
