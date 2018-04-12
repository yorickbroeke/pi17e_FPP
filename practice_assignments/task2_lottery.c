#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ticketcount = 1;
int totalwin = 0;
int totalpayout = 0;








void _playRound(){

    char _fruits[12][32];
    strcpy(_fruits[0], "tomato");
    strcpy(_fruits[1], "banana");
    strcpy(_fruits[2], "pear");
    strcpy(_fruits[3], "orange");
    strcpy(_fruits[4], "grapes");
    strcpy(_fruits[5], "lime");
    strcpy(_fruits[6], "apple");
    strcpy(_fruits[7], "peach");
    strcpy(_fruits[8], "mango");
    strcpy(_fruits[9], "lemon");
    strcpy(_fruits[10], "melon");
    strcpy(_fruits[11], "cherry");

    int _prizes[12] = {2,4,5,10,20,30,40,50,100,500,5000,50000};

    int a;
    int i = 0;
    float winchance = rand() % 100; //for checking if the users wins
    int ticket[6][2];
    int x = rand() % 5;

    int winfruit1 = rand() % 11;
    int winfruit2 = rand() % 11;

// If the users wins the lottery
    if (winchance <= 22.02){
        int _prob = (rand() % 2936156) * (rand() % 90); //All the potential prizes
        int bincheck = rand() % 1;

        // Randomly makes the 1st or 2nd the winning fruit
        if (bincheck == 1){
            ticket[x][0] = winfruit1;
        }
        else if (bincheck == 0){
            ticket[x][0] = winfruit2;
        }

        // Fills the rest of the ticket
        while(i < 6){
            if(i != x){
                ticket[i][0] = rand() % 12;
                while(ticket[i][0] == winfruit1 || ticket[i][0] == winfruit2){
                    ticket[i][0] = rand() % 12;
                }

                ticket[i][1] = rand() % 12;
            i++;
            }
            else{
                i++;
            }
        }

        if (_prob <= 12){                               //Jackpot
            ticket[x][1] = 11;
        }

        else if(_prob > 12 && _prob <= 24){             //€5000
            ticket[x][1] = 10;
        }

        else if(_prob > 24 && _prob <= 684){            //€500
            ticket[x][1] = 9;
        }

        else if(_prob > 684 && _prob <= 21998){         //€100
            ticket[x][1] = 8;
        }

        else if(_prob > 21998 && _prob <= 38730){       //€50
            ticket[x][1] = 7;
        }

        else if(_prob > 38730 && _prob <= 56476){       //€40
            ticket[x][1] = 6;
        }

        else if(_prob > 56476 && _prob <= 89852){       //€30
            ticket[x][1] = 5;
        }

        else if(_prob > 89852 && _prob <= 178799){      //€20
            ticket[x][1] = 4;
        }

        else if(_prob > 178799 && _prob <= 534587){     //€10
            ticket[x][1] = 3;
        }

        else if(_prob > 534587 && _prob <= 712481){     //€5
            ticket[x][1] = 2;
        }
        else if(_prob > 712481 && _prob <= 1335110){    //€4
            ticket[x][1] = 1;
        }
        else{                                           //€2
            ticket[x][1] = 0;
        }

        totalpayout = totalpayout + _prizes[ticket[x][1]];
        totalwin++;
    }



    else{
        while(i < 6){
            ticket[i][0] = rand() % 12;
            while(ticket[i][0] == winfruit1 || ticket[i][0] == winfruit2){
                ticket[i][0] = rand() % 12;
            }
            ticket[i][1] = rand() % 12;
            i++;
        }

    }

    i=0;
    char filename[128];
    sprintf(filename, "Ticket_%d.html", ticketcount);

    FILE *htmlfile;
    htmlfile = fopen(filename , "w");

    fprintf(htmlfile, "<!DOCTYPE html>\n");
    fprintf(htmlfile, "<html>\n");
    fprintf(htmlfile, "<head>\n");
    fprintf(htmlfile, "<title>%s</title>\n\n",filename);
    fprintf(htmlfile, "<style>\n    div.container{width: 1000px;}\ndiv.block{float: left; background-color: black; width: 256px; height: 256px; margin: 5px; color: white;}\nheader, footer{ width: 778px; height: 128px; margin: 5px; padding: 5px; background-color: #2ABBF5; color: black; text-align: center;}\nimg{ position: relative; top: 10px; left: 64px;}\np{text-align: center; position: relative; bottom: 0px; font-size: 32px}\n\n</style>\n");
    fprintf(htmlfile, "</head>\n\n");
    fprintf(htmlfile, "<body>\n <div class=\"container\">\n <header><h1 style=\"font-size: 64px;\">Fruit Fiesta Festival Lottery</h1></header>\n\n");
    fprintf(htmlfile, "<header style=\"background-color: black;\"><h1 style=\"color: white; font-size: 32px; width: 522px\">Fruit from the Winners Tree: </h1>");
    fprintf(htmlfile, "<img style=\"position: absolute; top: 153px; left: 538px\" src=\"Images\\%s.png\">\n <img style=\"position: absolute; top: 153px; left: 666px\" src=\"Images\\%s.png\"></header>\n\n", _fruits[winfruit1], _fruits[winfruit2]);

    while(i < 6){
        fprintf(htmlfile, "<div class=\"block\">\n");
        fprintf(htmlfile, "<img style=\"position: relative;top: 10px;left: 64px;\" src=\"Images\\%s.png\" alt= \"%s\">\n",_fruits[ticket[i][0]], _fruits[ticket[i][0]]);
        fprintf(htmlfile, "<p>€ %d</p>\n</div>\n\n", _prizes[ticket[i][1]]);
        i++;
    }

    if (winchance <= 22.02){
        fprintf(htmlfile, "<footer style=\"background-color: white;\"><h1>You have won € %d. Congratulations!!</h1></footer>\n ", _prizes[ticket[x][1]]);
    }
    else{
        fprintf(htmlfile, "<footer style=\"background-color: white;\"><h1>Thank you for Playing!</h1></footer>\n ");
    }
    fprintf(htmlfile, "</body>\n</html>");
    fclose(htmlfile);
}

void lottery_main(){
    srand(time(0));
    char choice;
    int j, tic;
    float winpay, avgpay, winrate;


     do{
        printf("\n \n \n--Lottery Menu--------------------------------- \n");
        printf("1) Buy a ticket\n");
        printf("2) Buy multiple tickets \n");
        printf("3) Show statistics \n");
        printf("4) Exit \n");
        scanf(" %c", &choice);



        switch(choice){
        case '1':
            _playRound();
            ticketcount++;
            break;
        case '2':
            printf("\nHow many tickets would you like to buy? ");
            scanf(" %d", &tic);
            for(j=0; j<tic; j++){
                _playRound();
                ticketcount++;
            }
            break;
        case '3':
            if (totalwin == 0){
                break;
            }
            else{
            winpay = totalpayout / (float)totalwin;
            winrate = totalwin / (float)ticketcount;
            avgpay = totalpayout / (float)ticketcount;
            printf("\nTickets Sold:          %d\n", ticketcount-1);
            printf("Winrate:                %.4f\n", winrate);
            printf("Average Total Payout:   %.4f EUR\n", avgpay);
            printf("Average Win Payout:     %.4f\n", winpay);
            break;
            }

        case '4':
            printf("\nExiting Lottery menu \n\n");
            break;
        default:
            printf("Invalid input, please enter a valid value");
            break;


        }

    }while (choice != '4');

}
