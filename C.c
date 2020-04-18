#include <stdio.h>

//White Pieces
int w_location_X[12], w_location_Y[12];
char white_piece = 'W';


//Black Pieces
int b_location_X[12], b_location_Y[12];
char black_piece = 'B';


int blackPiece[8];
int width = 64, height = 24;
char letter_ID_on_board [64];
char alphabet [8];

int running = 0;

//Locates which arrays are to be changed
int array_foundX = 0;
int array_foundY = 0;


void pieces_start_location();
void draw_board();
void creating_letters_ID_on_board();
void select_piece();
void move_piece();


int help_move_pieces_number();
int main()
{

    creating_letters_ID_on_board();
   pieces_start_location();
//    while(running != 4)
//    {
//        draw_board();
//        select_piece();
//        move_piece();
//        running++;
//    }
    draw_board();

    select_piece();

    

    
    return 0;
}

void move_piece(){

    char letter;
    
    int new_locationY, new_locationX;
       
    //Defines the row and column(column needs to be defined by number)
    int number_location_ID, letter_location_ID;
    
    //Keeps pieces found in row and column
    int locateX[3], locateY[3];
    
    printf(" To: ");
    scanf("%c %i", &letter, &number_location_ID);
    


    
    //Finds the row
    switch(letter){
            case('A'):
                letter_location_ID = 3;
                break;
            case('B'):
                letter_location_ID = 12;
                break;
            case('C'):
                letter_location_ID = 18;
                break;
            case('D'):
                letter_location_ID = 27;
                break;
            case('E'):
                letter_location_ID = 34;
                break;
            case('F'):
                letter_location_ID = 43;
                break;
            case('G'):
                letter_location_ID = 51;
                break;
            case('H'):
                letter_location_ID = 60;
                break;
           
       }

       //Finds the column
       number_location_ID = help_move_pieces_number(number_location_ID);
       
    w_location_X[array_foundX] = letter_location_ID;
    w_location_Y[array_foundY] = number_location_ID;
       

}

void select_piece()
{
    //Defines the column
    char letter;
    
    //Defines the row and column(column needs to be defined by number)
    int number_location_ID, letter_location_ID;
    
    //Keeps pieces found in row and column
    int locateX[3], locateY[3];
    
    for(int i = 0; i < 4;i++){
        locateX[i] = 5;
        locateY[i] = 6;
    }
    

    
    printf("White's Turn: \n\n Move Piece: ");
    scanf("%c %i", &letter, &number_location_ID);

       
    //Finds the row
    switch(letter){
            case('A'):
                letter_location_ID = 3;
                break;
            case('B'):
                letter_location_ID = 12;
                break;
            case('C'):
                letter_location_ID = 18;
                break;
            case('D'):
                letter_location_ID = 27;
                break;
            case('E'):
                letter_location_ID = 34;
                break;
            case('F'):
                letter_location_ID = 43;
                break;
            case('G'):
                letter_location_ID = 51;
                break;
            case('H'):
                letter_location_ID = 60;
                break;
        
    }

    //Finds the column
    number_location_ID = help_move_pieces_number(number_location_ID);
    
    //Finding all pieces in the row
    for(int i = 0; i < 12; i++)
    {
        if(w_location_Y[i] == number_location_ID){
            locateY[array_foundY] = i;
            printf("Y%i: %i\n\n\n",array_foundY, locateY[array_foundY]);
            array_foundY++;
        }
//        printf("\nY%i:          %i", i, locateY[i]);
    }
    
    //Finds all the pieces in the column
    for(int i = 0; i < 12; i++)
    {
        if(w_location_X[i] == letter_location_ID){
            locateX[array_foundX] = i;
            printf("X : %i\n\n\n", locateX[array_foundX]);
            array_foundX++;
        }
    }
    for(int i = 0; i < 4;i++){
           printf("teST:  x%i: %i   ,   y%i: %i\n",i, locateX[i],i,    locateY[i]);
        
       }
   
    // Finding the Arrays that are to be changed
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(locateX[i] == locateY[j])
            {
                printf("Y%i: %i       ,      X%i: %i\n", j, locateY[j], i , locateX[i]);
                array_foundY = locateY[j];
                array_foundX = locateX[i];
                printf("%i\n%i\n", array_foundY, array_foundX);
            }
            
        }
    }
}

int help_move_pieces_number(int number)
{
    switch (number){
               
           case(1):
                number = 1;
               break;
           case(2):
               number = 4;
               break;
           case(3):
               number = 7;
               break;
           case(4):
               number = 10;
               break;
           case(5):
               number = 13;
               break;
           case(6):
               number = 16;
               break;
           case(7):
               number = 19;
               break;
           case(8):
               number = 21;
               break;
       }
    
    return number;
}



void pieces_start_location()
{
    w_location_X[0] = 12, w_location_X[1] = 27, w_location_X[2] = 43, w_location_X[3] = 60,
    w_location_X[4] = 3, w_location_X[5] = 18, w_location_X[6] = 34, w_location_X[7] = 51,
    w_location_X[8] = 12, w_location_X[9] = 27, w_location_X[10] = 43, w_location_X[11] = 60,
    
    w_location_Y[0] = 1, w_location_Y[1] = 1, w_location_Y[2] = 1, w_location_Y[3] = 1,
    w_location_Y[4] = 4, w_location_Y[5] = 4, w_location_Y[6] = 4, w_location_Y[7] = 4,
    w_location_Y[8] = 7, w_location_Y[9] = 7, w_location_Y[10] = 7, w_location_Y[11] = 7,
    
    
    b_location_X[0] = 3, b_location_X[1] = 18, b_location_X[2] = 34, b_location_X[3] = 51,
    b_location_X[4] = 12, b_location_X[5] = 27, b_location_X[6] = 43,b_location_X[7] = 60;
    b_location_X[8] = 3, b_location_X[9] = 18, b_location_X[10] = 34, b_location_X[11] = 51,

    
    b_location_Y[0] = 16, b_location_Y[1] = 16, b_location_Y[2] = 16, b_location_Y[3] = 16,
    b_location_Y[4] = 19, b_location_Y[5] = 19, b_location_Y[6] = 19, b_location_Y[7] = 19,
    b_location_Y[8] = 22, b_location_Y[9] = 22, b_location_Y[10] = 22, b_location_Y[11] = 22;
    
}

void draw_board()
{
    int black_square = width/8, loop_squares = black_square * 2;
    int squares = width/8;
    int number_ID_on_board = 0, number_ID_printed = 1;
    int final_line = 0;
    int board_color_sequence = 0;
    int line = 0;
    int letter = 0;
    //array Number of pieces
    int w_locateX = 0, w_locateY = 0;
    int b_locateX = 0, b_locateY = 0;
    
    printf("\e[1;1H\e[2J");

    
    printf("              |");
    for(int i = 0; i < width + 1; i++)
        printf("-");
    printf("|");
    printf("\n");
    


    for (int y = 0; y < height; y++){
        if(y - number_ID_on_board == 1){
        printf("            %i |", number_ID_printed);
        }
        else
        {
            printf("              |");
        }
        
        for (int x = 0; x < width; x++){
            
            switch(board_color_sequence){
               
                case 0:
                    if(squares < black_square){
                        if (w_location_Y[w_locateY] == y && w_location_X[w_locateX] == x)
                        {
                            printf("%c", white_piece);
                            w_locateX++;
                            w_locateY++;
                        } else if (b_location_Y[b_locateY] == y && b_location_X[b_locateX] == x)
                        {
                            printf("%c", black_piece);
                            b_locateX++;
                            b_locateY++;
                        
                        }
                        else
                        {
           				 	printf(" ");
           				 }
                        
                    }
                    else
                    {
                        printf("/");
                    }
                    
                    squares++;
                    
                    if (squares == loop_squares)
                        squares-=squares;
                    break;
                    
                case 1:
                    if(squares < black_square){
                        printf("/");
                    } else {
                    //white squares
                    if (w_location_Y[w_locateY] == y && w_location_X[w_locateX] == x)
                    {
                        printf("%c", white_piece);
                        w_locateX++;
                        w_locateY++;
                    } else if (b_location_Y[b_locateY] == y && b_location_X[b_locateX] == x)
                    {
                        printf("%c", black_piece);
                        b_locateX++;
                        b_locateY++;
                    
                    }
                        else
                    {
                        printf(" ");
                    }
                }
                
                squares++;
                        
                if (squares == loop_squares)
                squares-=squares;
                    
            }
                    
        }
        printf(" |");
        printf("\n");

        line++;
    
        if(line == 3){
            printf("              |");
            for(int i = 0; i < width + 1; i++)
                printf("-");
            printf("|");
            line-=line;
            final_line++;
            printf("\n");
            
            if(board_color_sequence == 1){
                board_color_sequence-=board_color_sequence;
            } else {
                board_color_sequence++;
            }
            
            number_ID_on_board+=3;
            number_ID_printed++;
        }
    }
    printf("               ");
    for(int i = 0; i < 64; i++)
        printf("%c", letter_ID_on_board[i]);
              
    printf("\n\n\n\n");

}

void creating_letters_ID_on_board()
{
    int attaches_letters = 4, alphabet_identifier = 0;

    alphabet[0] = 'A';
    alphabet[1] = 'B'; alphabet[2] = 'C',alphabet[3] = 'D',alphabet[4] = 'E',alphabet[5] = 'F' ,alphabet[6] = 'G', alphabet[7] = 'H';
 

    for(int i = 0; i < 64; i++)
    {
        if(attaches_letters == 0){
            letter_ID_on_board[i] = alphabet[alphabet_identifier];
            alphabet_identifier++;
            attaches_letters+= 7;
        } else
        {
            letter_ID_on_board[i] = ' ';
            attaches_letters--;
        }
    }
}

