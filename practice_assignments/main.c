#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_GB");
    char choice;
     do{
        printf("\n \n \n--TESTING MENU--------------------------------- \n");
        printf("1) Convert .csv / .data to .xml file \n");
        printf("2) Participate in the lottery \n");
        printf("3) Go on an adventure \n");
        printf("4) Guess the colour I'm thinking of \n");
        printf("9) Exit \n");
        scanf(" %c", &choice);

        switch(choice){
        case '1':
            conversion_main();
            break;
        case '2':
            lottery_main();
            break;
        case '3':
            adventure_main();
            break;
        case '4':
            //guessing_game_main();
            break;
        case '9':
            printf("\nExiting testing menu \n\n");
            break;
        default:
            printf("Invalid input, please enter a valid value");
            break;

        }

    }while (choice != '9');

    return 0;
}
