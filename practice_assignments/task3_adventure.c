#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int wincondition = 0;
int ogre_talk = 0;

struct character{
    int hp;
    int damage;
};

void knight_encounter(struct character hero){
    int options;
    int dead = 0;
    int kill = 0;
    printf("\n1) Fight          2) Talk\n3) Run\n\n>>");
    scanf(" %d", &options);

    if (options == 1){      //Fightscene
        struct character knight_1;
        knight_1.damage = 10 + rand() % 100;
        knight_1.hp = 100;

        struct character knight_2;
        knight_2.damage = 10 + rand() % 100;
        knight_2.hp = 100;

        while(dead == 0 && kill != 3){
            printf("\n\nYOU        ||  HP: %d      AD: %d\n", hero.hp, hero.damage);
            if (kill != 1){printf("WHITE KNIGHT||  HP: %d      AD: %d\n", knight_1.hp, knight_1.damage);}
            if (kill != 2){printf("BLUE  KNIGHT||  HP: %d      AD: %d\n", knight_2.hp, knight_2.damage);}
            if (kill == 0){
                printf("1) Attack the WHITE KNIGHT      2) Attack the BLUE KNIGHT\n\n>>");
                scanf(" %d", &options);

                hero.hp = hero.hp - knight_1.damage;
                hero.hp = hero.hp - knight_2.damage;

                if (options == 1){
                    knight_1.hp = knight_1.hp - hero.damage;
                }
                else{
                    knight_2.hp = knight_2.hp - hero.damage;
                }
            }

            else if (kill == 1){
                system("pause");
                hero.hp = hero.hp - knight_2.damage;
                knight_2.hp = knight_2.hp - hero.damage;
            }

            else{
                system("pause");
                hero.hp = hero.hp - knight_1.damage;
                knight_1.hp = knight_1.hp - hero.damage;
            }

            if (hero.hp <= 0){
                dead = 1;

            }
            else if (knight_1.hp <= 0 && knight_2.hp){
                printf("\n\n As the last foe falls to your mighty blow, you know, victory is yours");
                kill =  3;
                system("pause");
            }
            else if (knight_1.hp <= 0 && knight_2.hp > 0){
                printf("\n\n The WHITE KNIGHT falls to your mighty blow");
                kill = 1;
            }
            else if (knight_2.hp <= 0 && knight_1.hp > 0){
                printf("\n\n The BLUE KNIGHT falls to your mighty blow");
                kill = 2;
            }

        }

        if (dead != 0){
            wincondition = 2;
            system("pause");
        }
        else{
            wincondition =  1;
        }

    }

    else if (options == 2){     //TALKINGSCENE
        printf("\n\nYou ask the guards if you are allowed into the castle, since you heard her screaming for help\n");
        system("pause");

        int random = rand() % 100;
        if (random <= 10){
            printf("\n\nThe guards respond with \"Why the well not, it is a boring day anyway, but just know that we will be keeping an eye out!\"\n");
            wincondition = 1;
        }
        else {
            printf("\n\n The guards stare briefly at you before they burst out in laughter.\n");
            system("pause");
            printf("\n\n After 3 minutes of laughter you decide to leave and go back to the crossroad.");
        }
    }
    else{
        printf("\n\nYou got scared by the big scary knights, and decided to hightail it back to the crossroad.");
        system("pause");
    }
}

void princess_boss(struct character hero){
    int options;
    printf("\n1) Fight          2) Talk\n3) Run\n\n>>");
    scanf(" %d", &options);

    if (options == 1){
        struct character princess;
        princess.hp = 75;
        princess.damage = 20 + rand() % 30;

        while (hero.hp > 0 && princess.hp > 0){
            printf("\n\nYOU         ||  HP: %d      AD: %d\n", hero.hp, hero.damage);
            printf("PRINCESS        ||  HP: %d      AD: %d\n", princess.hp, princess.damage);
            system("pause");
            hero.hp = hero.hp - princess.damage;
            princess.hp = princess.hp - hero.damage;
        }
        if (hero.hp <= 0){
            wincondition = 2;
        }
        else{
            printf("\n\nYou killed the princess...\n");
            system("pause");
            printf("\n\nYOU KILLED THE PRINCESS...YOU MONSTER\n");
            system("pause");
            printf("\n\nYou decide to run away, as fast as you can!\n");
            system("pause");
            printf("\n\nThe news about your MURDER of the princess starts making the rounds. Miraculously the king from a rival kingdom takes you under his wing\n");
            system("pause");
            printf("\n\nThe Rival King is delighted that you took out his competition for him, and for that he wants to reward you...\n");
            system("pause");
            printf("\n\nThe King decides to adopt you as his own son, and make you successor to the throne.\n");
            system("pause");
            wincondition = 4;
        }
    }
    else if (options == 2){
        printf("\n\nYou walk towards the princess and decide to help her out with her shoe\n");
        system("pause");

        int random = rand() % 100;
        if (random = 1){
            printf("\n\n The princess is so delighted by your noble act that she decides on the spot that she will marry you!\n");
            system("pause");
            wincondition = 4;
        }
        else{
            printf("\n\nYou try to help the princess, but she starts screaming and calls the guards\n");
            system("pause");
            printf("\n\nWhen the guards arrive, the princess accuses you of sexual assault\n");
            system("pause");
            printf("\n\nYou are dragged to the courtyard where you are promptly executed...\n");
            system("pause");
            wincondition = 2;
        }
    }
    else {
        printf("\n\nYou got scared by the beauty of the princess, and decided to hightail it back to the crossroad.");
        system("pause");
    }


}

void barfight_boss(struct character hero){
    int options;
    int dead = 0;
    int kill = 0;
    printf("\n1) Fight          2) Talk\n3) Run\n\n>>");
    scanf(" %d", &options);

    if (options == 1){      //Fightscene
        struct character barfighter_1;
        barfighter_1.hp = 75;
        barfighter_1.damage = rand() % 30;

        struct character barfighter_2;
        barfighter_2.hp = 100;
        barfighter_2.damage = 50;

        while(dead == 0 && kill != 3){
            printf("\n\nYOU        ||  HP: %d      AD: %d\n", hero.hp, hero.damage);
            if (kill != 1){printf("DRUNKEN BRAWLER||  HP: %d      AD: %d\n", barfighter_1.hp, barfighter_1.damage);}
            if (kill != 2){printf("CROSS-EYED DRUNK||  HP: %d      AD: %d       MISS: 50\% \n", barfighter_2.hp, barfighter_2.damage);}
            if (kill == 0){
                printf("1) Attack the DRUNKEN BRAWLER      2) Attack the CROSS-EYED BRAWLER");
                scanf(" %d", &options);

                hero.hp = hero.hp - barfighter_1.damage;
                int random = rand() % 1;
                hero.hp = hero.hp - (barfighter_2.damage * random);

                if (options == 1){
                    barfighter_1.hp = barfighter_1.hp - hero.damage;
                }
                else{
                    barfighter_2.hp = barfighter_2.hp - hero.damage;
                }
            }

            else if (kill == 1){
                system("pause");
                int random = rand() % 1;
                hero.hp = hero.hp - (barfighter_2.damage * random);
                barfighter_2.hp = barfighter_2.hp - hero.damage;
            }

            else{
                system("pause");
                hero.hp = hero.hp - barfighter_1.damage;
                barfighter_1.hp = barfighter_1.hp - hero.damage;
            }

            if (hero.hp <= 0){
                dead = 1;
            }
            else if (barfighter_1.hp <= 0 && barfighter_2.hp <= 0){
                printf("\n\n As the last foe falls to your mighty blow, you know, victory is yours");
                kill =  3;
            }
            else if (barfighter_1.hp <= 0 && barfighter_2.hp > 0){
                printf("\n\n The DRUNKEN BRAWLER falls to your mighty blow");
                kill = 1;
            }
            else if (barfighter_2.hp <= 0 && barfighter_1.hp > 0){
                printf("\n\n The CROSS-EYED DRUNK falls to your mighty blow");
                kill = 2;
            }

        }
        if (dead != 0){
            wincondition = 2;
            system("pause");
        }
        else{
            wincondition =  3;
            system("pause");
        }

    }

    else if (options == 2){     //TALKINGSCENE
        printf("\n\nYou try to start a nice conversation with the gentlemen\n");
        system("pause");
        printf("\n\nHowever, they do not seem to interested in talking.\n");
        system("pause");
        printf("\n\nThe closest man stabs you right through the heart\n");
        system("pause");
        wincondition = 2;
    }
    else{
        printf("\n\nYou got scared by the big scary men coming your way, and decided to hightail it back to the crossroad.\n");
        system("pause");
        printf("\n\nAs you get close to the door, you see that it is blocked.\n");
        system("pause");
        printf("\n\nYou turn around just in time to see a dagger enter your chest\n");
        system("pause");
        wincondition = 2;
    }

}

void fisherman_encounter(){
    int options;
    printf("\n1) Stay          2) Talk\n3) Run\n\n>>");
    scanf(" %d", &options);

    if (options == 1){
        printf("\n\nYou sit near the river for a couple of more hours.\nAfter a couple of hours you decide to end your day, and just go home\n");
        system("pause");
        wincondition = 3;
    }
    else if (options == 2){
        printf("\n\nYou decide to see if you can help the old man in some way.\n");
        system("pause");
        wincondition = 1;
    }
    else{
        printf("\n\nYou are afraid that the old man might notice you and ask you for help, so you run back to the crossroad\n");
        system("pause");
    }

}

void fisherman_boss(struct character hero){
    int options;
    printf("\n1) Fight          2) Help\n3) Run\n\n>>");
    scanf(" %d", &options);

    if (options == 1){
        struct character fisherman;
        fisherman.hp = 100;
        fisherman.damage = 10 + rand() % 65;

        while (hero.hp > 0 && fisherman.hp > 0){
            printf("\n\nYOU         ||  HP: %d      AD: %d\n", hero.hp, hero.damage);
            printf("FISHERMAN        ||  HP: %d      AD: %d\n", fisherman.hp, fisherman.damage);
            system("pause");
            hero.hp = hero.hp - fisherman.damage;
            fisherman.hp = fisherman.hp - hero.damage;
        }
        if (hero.hp <= 0){
            wincondition = 2;
        }
        else{
            printf("\n\nYou just killed an old man\n");
            system("pause");
            printf("\n\nIS THAT WHAT YOU WANT TO BE IN LIFE... A MURDERER OF THE ELDERLY\n");
            system("pause");
            printf("\n\nYou are not sure what to do, as you look around to evaluate your options, the guards come running towards you\n");
            system("pause");
            printf("\n\nYou don't ever try to escape, you are ashamed of your deeds\n");
            system("pause");
            printf("\n\nThe guards grab you, beat you, and then drag you to the dungeon\n");
            system("pause");
            printf("\n\n2 Days later you are executed for the brutal murder of an elderly community member\n");
            system("pause");
            wincondition = 2;
        }
    }
    else if (options == 2){
        printf("\n\nYou tell the fisherman about your recent struggles, and that you would love to help him out\n");
        system("pause");
        wincondition =  4;
        printf("\n\nAfter helping the old fisherman for a couple of weeks, he introduces you to his granddaughter.\n");
        system("pause");
        printf("\n\nHer beauty is stunning, soon you fall in love and get married.\n");
        system("pause");
        printf("\n\nAs the old fisherman becomes to old to operate the fishing boat, you take over the family business.\n");
        system("pause");

        }
    else {
        printf("\n\nYou got scared by all the fishing equipment, and decided to hightail it back to the crossroad.");
        system("pause");
    }
}

void ogre_encounter(struct character hero){
    int options;
    printf("\n1) Fight          2) Talk\n3) Run\n\n>>");
    scanf(" %d", &options);

    if (options == 1){
      int chance = rand() % 1;
        struct character ogre;
        if (chance == 0){ogre.hp = 150;}
        else{ogre.hp = 200;}
        ogre.damage = 35;

        while (hero.hp > 0 && ogre.hp > 0){
            printf("\n\nYOU         ||  HP: %d      AD: %d\n", hero.hp, hero.damage);
            printf("OGRE           ||  HP: %d      AD: 0-100\n", ogre.hp);
            system("pause");
            int random = rand() % 5;
            hero.hp = hero.hp - (ogre.damage * random);
            ogre.hp = ogre.hp - hero.damage;
        }
        if (hero.hp <= 0){
            wincondition = 2;
        }
        else{
            printf("\n\nThe corpse of the OGRE causes a minor earthquake as it hits the ground\n");
            system("pause");
        }
    }
    else if (options == 2){
        printf("\n\nYou hesitantly start talking to the enormous ogre\n");
        system("pause");
        printf("\n\nStrangely enough, the ogre responds very positively. The ogre is happy that you didn't just run away screaming or attack him\n");
        system("pause");
        printf("\n\nYou tell the ogre that you would like to get to the other side of the forest.\n");
        system("pause");
        printf("\n\nSince the Ogre knows the woods like the back of his hand, he decides to help you out.\n");
        system("pause");
        printf("\n\nThe Ogre tells you that at the end of the current road you can find the exit of the forest. As you walk away, you think you see a tear forming in the corner of the Ogre's eye.");
        system("pause");
        ogre_talk = 1;

    }
    else{
        printf("\n\nYou are (rightfully) frightened by the giant Ogre, and decide to run back as fast as you can.\n");
    }

}

void depression_boss(struct character hero){
    int options;
    printf("\n1) Fight          2) Talk\n3) Run\n\n>>");
    scanf(" %d", &options);
    if (options == 1){
        struct character mind;
        mind.hp = 1000;
        mind.damage = 15;

        while (hero.hp > 0 && mind.hp > 0){
            printf("\n\nYOU         ||  HP: %d      AD: %d\n", hero.hp, hero.damage);
            printf("YOUR MIND       ||  HP: %d      AD: %d       MISS: 50% \n", mind.hp, mind.damage);
            system("pause");


            int random = rand() % 2;
            hero.hp = hero.hp - (mind.damage * random);
            mind.hp = mind.hp - hero.damage;

        }

        if (hero.hp <=0){
            printf("\n\nIn the end the darkness inside your mind takes over.\n");
            system("pause");
            printf("\n\nThe wind blows hard in your face as you jump of a nearby rocky cliff.\n");
            system("pause");
        }
        else{
            printf("\n\nIt was a long hard battle, but you beat your depression.\n");
            system("pause");
            printf("\n\nYou decide to keep moving forward, and see where you might end up.\n");
            system("pause");
            wincondition = 4;
        }
    }

    else if(options == 2){
        printf("/n/n...Who or what are you talking to?\n");
        system("pause");
        printf("\n\nYou know that there is noone there right?\n");
        system("pause");
        printf("\n\nYou are talking to yourself... YOU HAVE COMPLETELY LOST IT!!\n");
        system("pause");
        printf("\n\nThose thoughts of insanity are your last, as you run of a cliff with your hands covering your ears in a futile attempt to stop the voices.\n");
        system("pause");
        wincondition = 2;
    }
    else{
        wincondition = 1;
    }


}



void adventure_main(){
    srand(time(0));
    int chance = rand() % 1;
    struct character hero;

    if (chance == 0){
        hero.hp = 100;
    }
    else{
        hero.hp = 150;
    }
    hero.damage  = 10 + rand() % 90;

    char choice;
    int random_encounter = rand() % 100;
    char next;
    int cheat;

    printf("\n\nWelcome to the world of Whateveria, a land filled with mystery, castles, magic and of course boring old you.\n");
    system("pause");
    printf("\n\nOne day when you wake up you are tired of having accomplished nothing in your miserable life. So, you get dressed and step out of the door.\n");
    system("pause");

    do{
    printf("\n\nLooking at the open road ahead of you, you start to look around to determine a direction. To the north you see the Royal Castle, and you think you hear a distant call for help carried by the wind. To the east you see Vingar Forest, you have always wanted to go there, but it seems so ominous. Just to the east you see a village, it seems boring. You have been there once but nothing interesting ever seem to happen in the village.\n");
    system("pause");
    printf("\n\nWhere will you go, please type the first letter one of the cardinal directions: ");
    scanf(" %c", &choice);

    switch(choice){
    case 'n':
    case 'N':
        printf("\n\nAs you come closer to the castle the feint cry for help you thought to have heard seems to get louder.\n");
        system("pause");
        printf("\n\nAs you walk up to the gate you see 2 guards, what will you do: ");
        knight_encounter(hero);
        if (wincondition == 1){
            system("pause");
            printf("\n\nYou enter the castle, and open the door of the princess's chamber.\nYou see the princess hopping around the room, trying to put on a shoe, what will you do now?\n");
            princess_boss(hero);
        }
        break;
    case 'w':
    case 'W':
        printf("\n\nAs you are walking through the town, you see that just like last time nothing interesting ever happens there. With this realization setting in, you decide there are 2 things you can do at this point:\n  1) Go to the bar for a drink.\n  2) Go to the river to contemplate life.\n\n...... ");
        scanf(" %d", &cheat);

        if(cheat == 1){
            printf("\n\nAfter ordering your drink a couple of very large aggressive men walk towards you. They slowly move their hands towards their weapons as they get closer, what will you do now!\n");
            barfight_boss(hero);
        }
        else if (cheat == 2){
            printf("\n\nAs you sit by the river, splashing you feet in the water, you hear an old man groaning and struggling as he tries to prepare his fishing boat. You can see 3 options for now:");
            fisherman_encounter();
            if (wincondition = 1){
                printf("\n\nDuring your talk with the old man you figure out that he has a lot of trouble as of late with his work now that he has to work alone.\nAs you hear this, you start looking at your options, what to do? what to do?\n");
                fisherman_boss(hero);
            }
        }
        break;
    case 'e':
    case 'E':
        printf("\n\nAs you are walking towards the forest, you notice the sun seems to be trying to hide as it gradually gets darker.\n\n");
        if(random_encounter <= 75){
            printf("When reaching the forest you see that the main path is blocked by a gigantic Ogre. Oh no! what will you do now?!?!\n");
            ogre_encounter(hero);
        }

        if(wincondition == 2){
            break;
        }

        else{
        printf("\n\nAfter a lot of walking you have reached the other side of the forest. You start to smile.\n");
        system("pause");
        printf("\n\nHowever.....\n");
        system("pause");
        printf("\n\nThat feeling joy soon disappears as you realize that you have absolutely no idea of what to do now. Slowly the depression starts to set in");
        depression_boss(hero);
        if (wincondition == 1 && ogre_talk == 1){
            printf("\n\nYou run back while partially crying.\n");
            system("pause");
            printf("\n\nAs you find the ogre, you ask him you you can live in the forest with him.\n");
            system("pause");
            wincondition = 4;
        }
        else if (wincondition == 1 && ogre_talk != 1){
            printf("\n\nYour impossible attempt to run away from your thoughts fails.\n");
            system("pause");
            printf("\n\nBecause you are not paying any attention to the dangerous road, you trip, hit your head on a rock and slowly bleed to death");
            wincondition = 2;

        }
        break;
        }
    case 's':
    case 'S':
        printf("\n\nYou decided that it might best to not do anything after all.");
        wincondition = 3;
        break;
    case 'x':
    case 'X':
        printf("\n\nAs you are standing there you feel reality around you start to change, everything turns black. And suddenly, you hear an ominous voice say to you:\n\nHello lowly human, we are the beings of the 4th dimension. We will set your spirit free if you give us the password to life, the universe, and everything. Answer incorrectly and you will DIE.\n\nYou decide to scream into the void:");
        scanf(" %d", &cheat);
        if(cheat == 42){
            wincondition = 42;
        }
        else{
            wincondition = 2;
        }
        break;
    default:
        printf("\n\nInvalid input, please enter a valid value\n\n");
        break;
    }
    }while (wincondition < 2);

    if(wincondition == 2){ //Bad ending
        printf("\n\nAfter your (not so) glorious death, your body was dumped in a mass grave, to be forgotten by the cruel mistress of time.\n");
        system("pause");
    }
    else if (wincondition == 3){ //Neutral ending
        printf("\n\nAfter returning home, you sit back down at your kitchen table. You contemplate your day.\n");
        system("pause");
        printf("\n\nAfter everything, you didn't achieve something great.\n");
        system("pause");
        printf("\n\nBut hey, as you start thinking, you don't actually need to achieve something great right? as long as you live a life that has some meaning to you, what does the big picture matter, right?\n");
        system("pause");
        printf("\n\nYou continue your life as usual.\n\nAnd in the end after many years of just being yourself, you die peacefully in your sleep.\n");
        system("pause");
    }
    else if (wincondition == 4){ //Good ending
        printf("\n\nMany years later as you lie on your deathbed, you think back on your life and the day that changed it forever.\n");
        system("pause");
        printf("\n\nYou are happy with the way your life turned out, and it causes you to smile, one last time as you slowly close your eyes.\n");
        system("pause");
    }
    else{       // secret ending
        printf("\n\nWHAT ON EARTH DID YOU JUST DO!?!?!?!?!?!\n\nTHIS MIGHT BE THE END OF EXISTANCE AS WE KNOW IT...\n");
        system("pause");
        printf("\n\nWell, there is no point of arguing now. \nAlthough, I think you should know, you are the worst type of human... \nTHE ONE THAT DESTROYS EXISTANCE AS WE KNOW IT, THANKS A LOT...\n");
        system("pause");
        printf("\n\nJust so you know, this is all YOUR fault, are we clear on that? yeah? Ok, well let's get on with it then...\n");
        system("pause");
        while(1 != 42){
            int i = rand() %100;
            printf("%d", i);
        }
    }
    wincondition = 0;


}
