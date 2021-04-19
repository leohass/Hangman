#include<stdio.h>


void printGameStart(){
    char welcome[3][255] ={
     " +-++-++-++-++-++-++-+ +-++-+ +-++-++-++-++-++-++-+ ",
     " |W||e||l||c||o||m||e| |T||o| |H||a||n||g||m||a||n| ",
     " +-++-++-++-++-++-++-+ +-++-+ +-++-++-++-++-++-++-+ "
    };

    char rules[4][255] = {
        "The rules are simple",
        " 1. You have 7 tries",
        " 2. Only use letters of the alphabet",
        " 3. Lose"
    };

    for(int i = 0; i < 3; i ++){
        printf("%s \n", welcome[i]);
    }

    for(int i = 0; i < 4; i++ ){
        printf("%s \n", rules[i]);
    }

}

void getUserInput(char *input[],char typeOf[])){

    switch(typeOf){
        case "answer":
            printf("pls enter a letter:");
            fflush(stdin);
            scanf("%s", &input);
            break;
        case "name":
            printf("pls enter your name:");
            fflush(stdin);
            scanf("%s", &input);
            break;
    }
}

int inputValidation(char input[]){
    if(sizeof(input)-1 == 1){
        if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')){
            return 1;
        }
        printf("input must be alphabet");
        return 0;
    }
    printf("please enter only one character");
    return 0;
}

void printStatus(int i, char input){

    printHangman(i-1);

    printf("Sorry but %c is not what we are looking for \n", input);

    if(i = 1){
        printf("so close, you have 6 tries left \n");
    }
    if(i = 2){
        printf("even a blind hen sometimes finds a grain of corn, apparently you not, you have 5 tries left \n");
    }
    if(i = 3){
        printf("better luck next time, you have 4 tries left \n");
    }
    if(i = 4){
        printf("i am running out of jokes, you have 3 tries left \n");
    }
    if(i = 5){
        printf("amazon has a great margin on English dictionary's, maybe you should look into that, you have 2 tries left  \n");
    }
    if(i = 6){
        printf("you never give up do you well this is your last try \n");
    }
    if(i = 7){
        printf("did you juts really loose a game designed for children? \n");
    }
}
void printHangman(int i ){
    char hangman[7][255] = {" \
  +---+ \n \
  |   | \n \
      | \n \
      | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
      | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
  |   | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|   | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|\\  | \n \
      | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|\\  | \n \
 /    | \n \
      | \n \
=========", " \
  +---+ \n \
  |   | \n \
  O   | \n \
 /|\\  | \n \
 / \\  | \n \
      | \n \
========="};
    printf("%s \n", hangman[i]);
}

void clearScreen(){
    system("@cls||clear");
}
