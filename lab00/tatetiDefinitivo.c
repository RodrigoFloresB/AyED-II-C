#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#define VERDE_T "\x1b[32m"
#define RESET_COLOR "\x1b[0m" /* Color para Texto */

#include <assert.h>  /* assert() */

int t = 4; /* Tamaño del tablero t x t */
#define CELL_MAX (t*t - 1 )

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[t][t])
{
    int cell = 0;

    print_sep(t);
    for (int row = 0; row < t; ++row) {
        for (int column = 0; column < t; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(t);
    }
}

char get_winner(char board[t][t])
{
    char winner = '-';
    bool res_winner = true;

    for (int i = 0; i < t; i++)
    {
        /* Filas */
        for (int j = 1; j < t; j++)
        {
            res_winner = res_winner && (board[i][0] == board[i][j]);
        }
        if (res_winner)
        {
            winner = board[i][0];
            break;
        }
        
        res_winner = true; /* Reset Var*/

        /* Columnas */
        for (int j = 1; j < t; j++)
        {
            res_winner = res_winner && (board[0][i] == board[j][i]);
        }
        if (res_winner)
        {
            winner = board[0][i];
            break;
        }
    }

    res_winner = true; /* Reset Var*/

    /* Diagonales */
    for (int i = 1, j = 1; i < t && j < t; i++ , j++)
    {
        res_winner = res_winner && (board[0][0] == board[i][j]);  
    }
    if (res_winner)
    {
        winner = board[0][0];
    }

    res_winner = true; /* Reset Var*/

    /* Error, no compara bien */
    for (int i = 0, j = t-1; i < t; i++ , j--)
    {
        res_winner = res_winner && (board[j][i] == board[t-1][0]);
    }
    if (res_winner)
    {
        winner = board[0][t-1];
    } 

    return winner;
}

bool has_free_cell(char board[t][t])
{
    bool free_cell=false;
    
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (board[i][j] == '-')
            {
                free_cell = true;
            }
            
        }
    }
    
    return free_cell;
}

int main(void)
{
    printf(VERDE_T "\t Ta Te Ti\n");

    /* 
    Aun tengo que resolver este apartado para
    poder darle un tamaño t x t 
    */
    char board[4][4] = {
        { '-', '-', '-' , '-'},
        { '-', '-', '-' , '-'},
        { '-', '-', '-' , '-'},
        { '-', '-', '-' , '-'}
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (numero del 0 al %d): \n", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un numero desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / t;
            int colum = cell % t;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board); 
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda invalida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("\n \t El ganador es : %c \n", winner);
    }
        printf(RESET_COLOR);
        
    return 0;
}
