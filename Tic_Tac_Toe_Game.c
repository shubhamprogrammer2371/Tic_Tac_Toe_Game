#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void showBoard(char arr[])
{
    system("cls");
    printf("******************* Tic Tac Toe *******************\n\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n", arr[0], arr[1], arr[2]);
    printf("\t\t|\t\t|\t\t\n");
    printf("================|===============|===============\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n", arr[3], arr[4], arr[5]);
    printf("\t\t|\t\t|\t\t\n");
    printf("================|===============|===============\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n", arr[6], arr[7], arr[8]);
    printf("\t\t|\t\t|\t\t\n");
}

int checkForWin(char arr[])
{
    if ((arr[0] == arr[1] && arr[1] == arr[2]) || (arr[3] == arr[4] && arr[4] == arr[5]) || (arr[6] == arr[7] && arr[7] == arr[8])) // horizontal win
        return 1;
    if ((arr[0] == arr[3] && arr[3] == arr[6]) || (arr[1] == arr[4] && arr[4] == arr[7]) || (arr[2] == arr[5] && arr[5] == arr[8])) // vertical win
        return 1;
    if ((arr[0] == arr[4] && arr[4] == arr[8]) || (arr[2] == arr[4] && arr[4] == arr[6])) // diagonal win
        return 1;
    if ((arr[0] != '0') && (arr[1] != '1') && (arr[2] != '2') && (arr[3] != '3') && (arr[4] != '4') && (arr[5] != '5') && (arr[6] != '6') && (arr[7] != '7') && (arr[8] != '8'))
        return 0;
    else
        return -1;
}

int main()
{
    // two player game , we will assign the control to both the players accordimg to their turns
    int choice, player1_won = 0, player2_won = 0, no_of_matches = 0, match_draw = 0;
    char mark, flag = 'y'; // to store X or O
    while (flag == 'y')
    {
        int player = 1, i = -1;
        char arr[9] = {
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
        };
        no_of_matches++;
        do
        {
            showBoard(arr);
            player = (player % 2) ? 1 : 2;
            printf("Player 1 is \" X \"\nPlayer 2 is \" O \"\n");
            printf("Enter the number (0 to 8) from the above Tic Tac Toe board player %d : ", player);
            scanf("%d", &choice);

            mark = (player == 1) ? 'X' : 'O';

            if ((choice == 0) && (arr[0] == '0'))
                arr[0] = mark;
            else if ((choice == 1) && (arr[1] == '1'))
                arr[1] = mark;
            else if ((choice == 2) && (arr[2] == '2'))
                arr[2] = mark;
            else if ((choice == 3) && (arr[3] == '3'))
                arr[3] = mark;
            else if ((choice == 4) && (arr[4] == '4'))
                arr[4] = mark;
            else if ((choice == 5) && (arr[5] == '5'))
                arr[5] = mark;
            else if ((choice == 6) && (arr[6] == '6'))
                arr[6] = mark;
            else if ((choice == 7) && (arr[7] == '7'))
                arr[7] = mark;
            else if ((choice == 8) && (arr[8] == '8'))
                arr[8] = mark;
            else
            {
                printf("Invalid Input");
                player--;
                getch();
            }

            i = checkForWin(arr);
            player++;
        } while (i == -1);
        showBoard(arr);
        printf("************************ Result of the Match ****************************\n");
        if (i == 1)
        {
            if (player == 2)
            {
                player1_won++;
                player = 1;
            }
            else
            {
                player2_won++;
                player = 2;
            }
            printf("Player 1 was \" X \"\nPlayer 2 was \" O \"\n");
            printf("Player %d won !! Congraluations :) \n", player);
        }
        else
        {
            match_draw++;
            printf("Game Draw , Better luck next time :( \n");
        }
        printf("Do you want to play more (y/n) : ");
        scanf("%s", &flag);
    }
    system("cls");
    printf("Both the Players have played the game %d times and the results are :- \n", no_of_matches);
    printf("Player 1 won the game %d times.\nPlayer 2 won the game %d times.\nGame Draw %d times.\n", player1_won, player2_won, match_draw);
    printf("Thanks for playing the Tic Tac Toe game.\nI hope you enjoyed the game :)");

    return 0;
}