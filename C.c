#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Letters that will represent the pieces
char white = 'B';
char black = 'P';

//Count on pieces eaten
int black_pieces_eaten = 0;
int white_pieces_eaten = 0;

//Draws and presents the board
char board[34][95];
void draw_board();
void present_board();

//Menu and menu options
void credit();
void present_personalize_pieces();
void present_menu();

//Method to move pieces
void move_piece_W();
void move_piece_B();

//Runs the game
void play();
bool running_game = false;

//Begins the algorithm
void GAME();
bool running = true;

//Instructions to navigate the menu
void navigation_instructions();

//Option for PLYAER versus PLAYER or PLAYER versus PC & location for pc pieces
bool pvp = false;
int pc_location[12][2] = {
    {2,23 },    {2,43 },    {2,63 },    {2,83 },
    {6,13 },    {6,33 },    {6,53 },    {6,73 },
    {10,23},    {10,43},    {10,63},    {10,83}
};

//Ends game & finds winner
void game_over();
bool winner;

//Menu navigation
int pointer = 4;
char user_input;


//Main method
int main()

{
    navigation_instructions();
    GAME();
    return 0;
}
void GAME()
{
    while (running){
        present_menu();
        printf("\e[1;1H\e[2J");
    }
}

void present_menu()
{
    
    for(int i = 0; i < 41; i++)
        printf("-");
    printf("\n");
    
    for(int i = 0; i < 11; i++){
        for (int j = 0; j < 41; j++){
            if (!pvp){

                if (i == 4 && j == 17)
                    printf("Jogar");
                
                if (i == 5 && j == 17)
                    printf("Personalizar");
                if (i == 6 && j == 17)
                    printf("Creditos");
                    
                if (i == 7 && j == 17)
                    printf("Exit");
                
            }
            else
            {
                if (i == 4 && j == 17)
                    printf("PVP");
                if (i == 5 && j == 17)
                    printf("CPU");
                if (i == 6 && j == 17)
                    printf("Voltar");
            }
            
            if (i == pointer && j == 16)
                printf("->");
            
            printf(" ");
        }
        printf("\n");
    }
    
    for(int i = 0; i < 41; i++)
        printf("-");
    printf("\n\n");
    
    scanf(" %c", &user_input);
    
    switch (user_input) {
        case 'w':
            if(pointer != 4)
                pointer--;
            break;
        case 'W':
            if(pointer != 4)
                pointer--;
            break;
        case 's':
            if(pointer != 7)
                pointer++;
            break;
        case 'S':
            if(pointer != 7)
                pointer++;
            break;
        case 'k':
            if (!pvp){
                if(pointer == 4)
                    pvp = true;
                if (pointer == 5)
                    present_personalize_pieces();
                if(pointer == 6)
                    credit();
                if(pointer == 7)
                    running = false;
            } else
            {
                if(pointer == 4)
                    play();
                if (pointer == 5){
                    pvp = false;
                    play();
                }
                if(pointer == 6){
                    pvp = false;
                    pointer = 4;
                }
                }
            break;
        case 'K':
            if (!pvp){
                if(pointer == 4)
                    pvp = true;
                if (pointer == 5)
                    present_personalize_pieces();
                if(pointer == 6)
                    credit();
                if(pointer == 7)
                    running = false;
            } else
            {
                if(pointer == 4)
                    play();
                if (pointer == 5){
                    pvp = false;
                    play();
                }
                if(pointer == 6){
                    pvp = false;
                    pointer = 4;
                }
                 
            }
            break;
        default:
            printf("ERROR... \n Aperte 'w' para movimentar a seta para cima e 's' para movimentar seta para baixo");
            break;
    }
    printf("\n\n\n%i\n\n\n", pointer);   
}

void play()
{
    draw_board();
    running_game = true;

     while(running_game)
     {
        printf("\e[1;1H\e[2J");
        present_board();
        move_piece_W();
        
        if(black_pieces_eaten == 12){
            running_game = false;
            winner = true;
            game_over();
        }
         
        else {
            printf("\e[1;1H\e[2J");
            present_board();
            move_piece_B();

            if(white_pieces_eaten == 12){
                running_game = false;
                winner = false;
                game_over();
            }
             
        }
     }
}

void move_piece_B()
{
    char letter, let;
    int num_from, letter_from, num_to, letter_to;
    bool loop = true;
    bool permit = false;
    int infomation_from, infomation_to;
    bool existant_location = true;
    if (pvp){

    while (!permit){
    do {
        printf("MOVIMENTO DA PECA present_board:\n");
        
        printf ("Ecolha uma Peca:  ");
        scanf(" %c", &letter);
        scanf(" %i", &num_from);
        infomation_from = num_from;
        num_from = (num_from - 1) * 4 + 2;

                
        switch (letter) {
            case 'A':
                letter_from = 13;
                loop = false;
                break;
            case 'B':
                letter_from = 23;
                loop = false;
                break;
            case 'C':
                letter_from = 33;
                loop = false;
                break;
            case 'D':
                letter_from = 43;
                loop = false;
                break;
            case 'E':
                letter_from = 53;
                loop = false;
                break;
            case 'F':
                letter_from = 63;
                loop = false;
                break;
            case 'G':
                letter_from = 73;
                loop = false;
                break;
            case 'H':
                letter_from = 83;
                loop = false;
                break;
            default:
                break;
        }
                
        

        printf("\nEscolha o Destino: ");
        scanf(" %c", &let);
        scanf(" %i", &num_to);
        infomation_to = num_to;

        num_to = (num_to - 1) * 4 + 2;

        switch (let) {
            case 'A':
                letter_to = 13;
                loop = false;
                break;
            case 'B':
                letter_to = 23;
                loop = false;
                break;
            case 'C':
                letter_to = 33;
                loop = false;
                break;
            case 'D':
                letter_to = 43;
                loop = false;
                break;
            case 'E':
                letter_to = 53;
                loop = false;
                break;
            case 'F':
                letter_to = 63;
                loop = false;
                break;
            case 'G':
                letter_to = 73;
                loop = false;
                break;
            case 'H':
                letter_to = 83;
                loop = false;
                break;
            default:
                loop = true;
                break;
            }
                
            if ( board[num_from][letter_from] == black){
                board[num_from][letter_from] = ' ';
                loop = true;
            } else {
                loop = true;
                existant_location = false;
            }
                
            if (loop){
                printf("\e[1;1H\e[2J");
                printf("\n\n         MOVIMENTO NAO PERMITIDO\n\n         VOCE TENTOU MOVIMENTAR: %c%i -> %c%i\n", letter, infomation_from, let, infomation_to);
                if(existant_location){
                    board[num_from][letter_from] = black;
                }
                present_board();
            }
                
        } while(loop);
        loop = true;
        
        if(num_from - num_to == 8 || num_to - num_from == 8)
        {
            if (letter_from > letter_to){
                if (board[num_from + 4][letter_from - 10] == white){
                    board[num_to][letter_to] = black;
                    board[num_from + 4][letter_from - 10] = ' ';
                    white_pieces_eaten++;
                    permit = true;

                }
                
            }
            else if (letter_from  < letter_to){
                if(board[num_from + 4][letter_from + 10] == white){
                    board[num_to][letter_to] = black;
                    board[num_from + 4][letter_from + 10] = ' ';
                    white_pieces_eaten++;
                    permit = true;
                }
            }
        }

        else {
            if(letter_to - letter_from == 10 ||letter_from - letter_to  == 10){
                if( num_to >= num_from){
                    board[num_to][letter_to] = black;
                    permit = true;
                } else {
                    board[num_from][letter_from] = black;
                    printf("\e[1;1H\e[2J");
                    present_board();
                    printf("\n\nMOVE INTERRUPTED\n\n");
                }
            } else {
                board[num_from][letter_from] = black;
                printf("\n\n MOVE NOT PERMITED!\n\n");
                printf("\e[1;1H\e[2J");
                present_board();
            }
        }
    }}
    else {
        int pc, pc_from, pc_to;
        bool test = false;
        int change, arr_can_move_localizer =0, arr_can_eat = 0;
        bool pc_can_eat;
        
        sleep(2);
        
        while (!test){
            int can_move[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
            int can_eat[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
            
            for (int i = 0; i <12; i++)
                printf("%i  -  PC LOCATION: %i//%i\n",i, pc_location[i][0], pc_location[i][1]);
            
            for(int i = 1; i < 12; i++){
                if(pc_location[i][0] < pc_location[i - 1][0]){
                    change = pc_location[i][0];
                    pc_location[i][0] = pc_location[i -1][0];
                    pc_location[i - 1][0] = change;
                    
                    change = pc_location[i][1];
                    pc_location[i][1] = pc_location[i - 1][1];
                    pc_location[i - 1][1] = change;
                    i -=i;
                }
            }
            
            for(int i = 2; i <32; i+=4)
                for(int j = 13; j <93; j+=10)
                    for(int x = 0; x <12; x++)
                        if(pc_location[x][0] == i && pc_location[x][1] == j){
                            if(board[i][j] == ' '){
                                pc_location[x][0] = -10;
                                pc_location[x][1] = -10;
                            }
                            else if (board[i][j] == black){
                                if(board[i + 4][j + 10] == ' ' || board[i + 4][ j - 10] == ' '){
                                    if (j - 10 > 10){
                                    can_move[arr_can_move_localizer] = x;
                                    arr_can_move_localizer++;
                                    }
                                }
                                
                                if(board[i + 4][j + 10] == white && board[i + 8][j + 20] == ' '){
                                    if (j - 10 > 2){
                                        can_eat[arr_can_eat] = x;
                                        arr_can_eat++;
                                        pc_can_eat = true;
                                    }
                                } else if (board[i + 4][ j - 10] == white && board[i + 8][j - 20] == ' ')
                                {
                                    if (j - 10 > 2){
                                        if(j !=23){
                                            can_eat[arr_can_eat] = x;
                                            arr_can_eat++;
                                            pc_can_eat = true;
                                        }
                                    }
                                }
                            }
                        }
            for (int i = 0; i <12; i++)
                printf("Can Eat:%i\n", can_eat[i]);
            
            for (int i = 0; i <12; i++)
                printf("Can Move:%i\n", can_move[i]);
            printf("\n\n\n");
            for (int i = 0; i <12; i++)
                printf("%i  -  PC LOCATION: %i//%i\n",i, pc_location[i][0], pc_location[i][1]);

            
            
            if(pc_can_eat){
                srand(time(NULL));
                
                int random_eater = rand()%arr_can_eat;
                
                if(board[pc_location[can_eat[random_eater]][0] + 4] [pc_location[can_eat[random_eater]][1] + 10] == white && pc_location[can_eat[random_eater]][1] < 70){
                    if(board[pc_location[can_eat[random_eater]][0] + 8] [pc_location[can_eat[random_eater]][1] + 20] == ' '){
                        board[pc_location[can_eat[random_eater]][0] + 8] [pc_location[can_eat[random_eater]][1] + 20] = black;
                        board[pc_location[can_eat[random_eater]][0] + 4] [pc_location[can_eat[random_eater]][1] + 10] = ' ';
                        board[pc_location[can_eat[random_eater]][0]][pc_location[can_eat[random_eater]][1]] = ' ';
                        pc_location[can_eat[random_eater]][0] += 8;
                        pc_location[can_eat[random_eater]][1] +=20;
                        white_pieces_eaten++;
                        test = true;
                        }
                } else if (board[pc_location[can_eat[random_eater]][0] + 4] [pc_location[can_eat[random_eater]][1] - 10] == white && pc_location[can_eat[random_eater]][1] > 30){
                    if(board[pc_location[can_eat[random_eater]][0] + 8] [pc_location[can_eat[random_eater]][1] - 20] == ' '){
                        board[pc_location[can_eat[random_eater]][0] + 8] [pc_location[can_eat[random_eater]][1] - 20] = black;
                        board[pc_location[can_eat[random_eater]][0] + 4] [pc_location[can_eat[random_eater]][1] - 10] = ' ';
                        board[pc_location[can_eat[random_eater]][0]][pc_location[can_eat[random_eater]][1]] = ' ';
                        pc_location[can_eat[random_eater]][0] += 8;
                        pc_location[can_eat[random_eater]][1] -=20;
                        white_pieces_eaten++;
                        test = true;
                    }
                }
            } else
            {
                int random_move = rand()%arr_can_move_localizer;
                
                if (board[pc_location[can_move[random_move]][0] + 4] [pc_location[can_move[random_move]][1] + 10] == ' '){
                    board[pc_location[can_move[random_move]][0] + 4] [pc_location[can_move[random_move]][1] + 10] = black;
                    board[pc_location[can_move[random_move]][0]][pc_location[can_move[random_move]][1]] = ' ';
                    pc_location[can_move[random_move]][0] += 4;
                    pc_location[can_move[random_move]][1] +=10;
                    test = true;
                }
                else if (board[pc_location[can_move[random_move]][0] + 4] [pc_location[can_move[random_move]][1] - 10] == ' ' && pc_location[can_move[random_move]][1] > 10){
                    board[pc_location[can_move[random_move]][0] + 4] [pc_location[can_move[random_move]][1] - 10] = black;
                    board[pc_location[can_move[random_move]][0]][pc_location[can_move[random_move]][1]] = ' ';
                    pc_location[can_move[random_move]][0] += 4;
                    pc_location[can_move[random_move]][1] -=10;
                    test = true;
                }
            }
        }
    }
}

void move_piece_W()
{
    char letter, let;
    int num_from, letter_from, num_to, letter_to;
    bool loop = true;
    bool permit = false;
    int infomation_from, infomation_to;
    bool existant_location = true;

    while (!permit){
    do {
        printf("MOVIMENTO DA PECA BRANCA:\n");
        
        printf ("Ecolha uma Peca:  ");
        scanf(" %c", &letter);
        scanf(" %i", &num_from);
        infomation_from = num_from;
        num_from = (num_from - 1) * 4 + 2;

                
        switch (letter) {
            case 'A':
                letter_from = 13;
                loop = false;
                break;
            case 'B':
                letter_from = 23;
                loop = false;
                break;
            case 'C':
                letter_from = 33;
                loop = false;
                break;
            case 'D':
                letter_from = 43;
                loop = false;
                break;
            case 'E':
                letter_from = 53;
                loop = false;
                break;
            case 'F':
                letter_from = 63;
                loop = false;
                break;
            case 'G':
                letter_from = 73;
                loop = false;
                break;
            case 'H':
                letter_from = 83;
                loop = false;
                break;
            default:
                break;
        }
                
        

        printf("\nEscolha o Destino: ");
        scanf(" %c", &let);
        scanf(" %i", &num_to);
        infomation_to = num_to;

        num_to = (num_to - 1) * 4 + 2;

        switch (let) {
            case 'A':
                letter_to = 13;
                loop = false;
                break;
            case 'B':
                letter_to = 23;
                loop = false;
                break;
            case 'C':
                letter_to = 33;
                loop = false;
                break;
            case 'D':
                letter_to = 43;
                loop = false;
                break;
            case 'E':
                letter_to = 53;
                loop = false;
                break;
            case 'F':
                letter_to = 63;
                loop = false;
                break;
            case 'G':
                letter_to = 73;
                loop = false;
                break;
            case 'H':
                letter_to = 83;
                loop = false;
                break;
            default:
                loop = true;
                break;
            }
                
            if ( board[num_from][letter_from] == white){
                board[num_from][letter_from] = ' ';
                loop = true;

            } else {
                loop = true;
                existant_location = false;
            }
                
            if (loop){
                printf("\e[1;1H\e[2J");
                printf("\n\n         MOVIMENTO NAO PERMITIDO\n\n         VOCE TENTOU MOVIMENTAR: %c%i -> %c%i\n", letter, infomation_from, let, infomation_to);
                if(existant_location){
                    board[num_from][letter_from] = white;
                }
                present_board();
            }
                
        } while(loop);
        loop = true;
        
        if(num_from - num_to == 8 || num_to - num_from == 8)
        {
            if (letter_from - letter_to == 20){
                if (board[num_from - 4][letter_from - 10] == black){
                    board[num_to][letter_to] = white;
                    board[num_from - 4][letter_from - 10] = ' ';
                    black_pieces_eaten++;
                    permit = true;

                }
                
            }
            else if (letter_to - letter_from  == 20){
                if(board[num_from - 4][letter_from + 10] == black){
                    board[num_to][letter_to] = white;
                    board[num_from - 4][letter_from + 10] = ' ';
                    black_pieces_eaten++;
                    permit = true;
                }
            }
        }

        else {
            if(letter_to - letter_from == 10 ||letter_from - letter_to  == 10){
                if( num_to <= num_from){
                    board[num_to][letter_to] = white;
                    permit = true;
                } else {
                    board[num_from][letter_from] = white;
                    printf("\e[1;1H\e[2J");
                    present_board();
                    printf("\n\nMOVE INTERRUPTED\n\n");
                }
            } else {
                board[num_from][letter_from] = white;
                printf("\n\n MOVE NOT PERMITED!\n\n");
                printf("\e[1;1H\e[2J");
                present_board();
            }
        }
    }
}

void draw_board()
{
    char arr[34][95] = {{"       ----------------------------------------------------------------------------------"},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"1     | //////////          //////////          //////////          //////////           |"},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"2     |           //////////          //////////          //////////          ////////// |"},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"3     | //////////          //////////          //////////          //////////           |"},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"4     |           //////////          //////////          //////////          ////////// |"},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"5     | //////////          //////////          //////////          //////////           |"},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"6     |           //////////          //////////          //////////          ////////// |"},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"7     | //////////          //////////          //////////          //////////           |"},
                        {"      | //////////          //////////          //////////          //////////           |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"8     |           //////////          //////////          //////////          ////////// |"},
                        {"      |           //////////          //////////          //////////          ////////// |"},
                        {"       ---------------------------------------------------------------------------------- "},
                        {"            A          B         C         D         E         F         G         H      "},
                        };
    
    for (int i =0; i < 34; i++)
        for (int j = 0; j < 95; j++){
            board[i][j] = arr[i][j];
        }

    
    board[2][23] = black;board[2][43] = black;board[2][63] = black;board[2][83] = black;
    board[6][13] = black;board[6][33] = black;board[6][53] = black;board[6][73] = black;
    board[10][23] = black;board[10][43] = black;board[10][63] = black;board[10][83] = black;


    board[22][13] = white;board[22][33] = white;board[22][53] = white;board[22][73] = white;
    board[26][23] = white;board[26][43] = white;board[26][63] =white;board[26][83] = white;
    board[30][13] = white;board[30][33] = white;board[30][53] = white;board[30][73] = white;
}

void present_board()
{
    for (int i = 0; i < 34; i++){
        printf("%s\n",board[i]);
    }
}

void present_personalize_pieces()
{
    bool loop = true;
    printf("\e[1;1H\e[2J");
    while(loop){
        printf("\n\n\nPersonalize a peca BRANCA. Como que você deseja que a peca branca seja?\n Escolhe uma letra ou numero:\n\n\n\n");
        scanf(" %c", &white);
        printf("\e[1;1H\e[2J");
        printf("\n\n\n\nPersonalize a peca PRETA. Como que você deseja que a peca branca seja?\n Escolhe uma letra ou numero:\n\n\n\n");
        scanf(" %c", &black);
        
        if(white == black){
            printf("\e[1;1H\e[2J");
            printf("ERRO: As duas pecas nao podem ser iguais, tente de novo!");
        } else {
            loop = false;
        }
    }
}

void navigation_instructions()
{
    printf("\e[1;1H\e[2J");
    printf("\n\n\nBem Vindo ao jogo de dama!\n\nPara navegar o menu principal usa os inputs: \n        'w' (para mover para cima)   \n        's' (para mover para baixo)\n        'k' (para confirmar a opcao)\n\n Dê o input 'k' para continuar\n");
    scanf("%c", &user_input);
    printf("\e[1;1H\e[2J");
}

void credit()
{
    bool credito = true;
    while (credito){
        printf("\e[1;1H\e[2J");
        for(int i = 0; i < 41; i++)
               printf("-");
           printf("\n");
           
           for(int i = 0; i < 11; i++){
               for (int j = 0; j < 41; j++){
                   
                   if (i == 4 && j ==9)
                       printf("Created by Michael Lima");
                   
                   if (i == 6 && j ==17)
                       printf("->");
                   
                   if (i == 6 && j ==17)
                       printf ("Return");
                   
                   printf(" ");
               }
               printf("\n");
           }
           
        for(int i = 0; i < 41; i++)
            printf("-");
        
        printf("\n\n");

        scanf(" %c", &user_input);
        
        if(user_input == 'k' || user_input == 'K')
            credito = false;
    }
}

void game_over()
{
    bool credito = true;
    typedef struct
    {
        char *message;

    } op;
    op message1 = {"YOU WIN!!!!!!"};
    if(!pvp){
        if (!winner)
        {
            message1.message = "COMPUTER WINS!!!!!";
        }
    } else
    {
        message1.message = "WHITE WINS!!!!!!";
        if (!winner)
        {
            message1.message = "BLACK WINS!!!!!";
        }
    }
    while (credito){
        
            printf("\e[1;1H\e[2J");
            for(int i = 0; i < 41; i++)
                   printf("-");
               printf("\n");
               
            for(int i = 0; i < 11; i++){
                for (int j = 0; j < 41; j++){
                       
                    if (i == 4 && j ==12)
                        printf("%s", message1.message);
                       
                    if (i == 6 && j ==7)
                        printf("->");
                       
                    if (i == 6 && j ==7)
                        printf ("Return To Main Menu");
                       
                    printf(" ");
                }
                printf("\n");
            }
               
            for(int i = 0; i < 41; i++)
                printf("-");
            
            printf("\n\n");

            scanf(" %c", &user_input);
            
            if(user_input == 'k' || user_input == 'K')
                credito = false;
                
    }
    pvp = false;
    pointer = 4;
}


