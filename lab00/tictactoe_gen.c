#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(int n, char board[n][n]) {
    int cell = 0;

    print_sep(n);
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(n);
    }
}

char get_winner(int n, char board[n][n]) {
    char winner = '-';
    // Verificar filas
    for (int i = 0; i < n; i++) {
        int fila_ganadora = 1;
        for (int j = 1; j < n; j++) {
            fila_ganadora *= (board[i][j] == board[i][0] && board[i][0] != winner);
        }
        if (fila_ganadora) return board[i][0];
    }

    // Verificar columnas
    for (int i = 0; i < n; i++) {
        int columna_ganadora = 1;
        for (int j = 1; j < n; j++) {
            columna_ganadora *= (board[j][i] == board[0][i] && board[0][i] != winner);
        }
        if (columna_ganadora) return board[0][i];
    }

    // Verificar diagonal principal
    int diag_principal = true;
    for (int i = 1; i < n; i++) {
        diag_principal *= (board[i][i] == board[0][0] && board[0][0] != winner);
    }
    if (diag_principal) return board[0][0];


    // Verificar diagonal secundaria
    int diag_secundaria = true;
        for (int i = 1; i < n; i++) {
            int j = n - 1 - i;
            diag_secundaria *= (board[i][j] == board[0][n - 1] && board[0][n - 1] != winner);
        }
        if (diag_secundaria) return board[0][n - 1];

    return winner; // Si no hay ganador, retorna '-' 
}

bool has_free_cell(int n, char board[n][n]) {
    bool free_cell=false;
    //
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            if (board[row][column] == '-' ) {
                free_cell = true;
                column = n;
                row = n;
            }
        }
    }
    //
    return free_cell;
}

int main(void){
    int n;
    
    printf("Ingresa un numero mayor a 3 para el tamanho del tablero: ");
    scanf("%d", &n);

    int cell_max = ((n * n) - 1);
    char turn = 'X';
    char winner = '-';
    int cell = 0;

    printf("TicTacToe:\n");

    char board[n][n];  //definiendo el board

    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            board[row][column] = '-';
        }
    }

/*    char board[4][4] = {
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' }
    }; */


    while (winner == '-' && has_free_cell(n, board)) {
        print_board(n, board);
        printf("\nTurno %c - Elija posicion (numero del 0 al %d): ", turn, cell_max);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un numero desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= cell_max) {
            int row = cell / n;
            int colum = cell % n;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(n, board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda invalida!\n");
        }
    }
    print_board(n, board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Gano %c\n", winner);
    }
    return 0;
}
