# include "header.h"

void XO::startGame(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = 0;
        }
    }
    turn = 0;
    isGameover = 0;
    drawBoard();
    playGame();
}

void XO::playGame(){
    int move;

    while(!isGameover){
        turn = Player;
        std::cout<<"Make your move\n";
        std::cin>>move;
        Move(move);
        drawBoard();
        checkWin();
        if(!isGameover){
            std::cout<<"Now it is computer's turn\n";
            turn = Computer;
            Move(compMove());
            drawBoard();
            checkWin();
        }
    }
    if(turn == Player){
        std::cout<<"You win\n";
    }
    else{
        std::cout<<"The computer wins\n";
    }

}

void XO::Move(int i){
    int x = (i-1)/3;
    int y = (i+2)%3;
    if(board[x][y] ==0){
        board[x][y] = turn;
    }
    else{
        std::cout<<"Invalid move\n";
    }
}

int XO::compMove(){
    int temp[] = {1,2,3,4,5,6,7,8,9};
    int num;
    redo:
    srand(time(NULL));
    num = rand() % 8;
    int x = (temp[num] - 1) / 3;
    int y = (temp[num] + 2) % 3;
    if(board[x][y] == 0){
        return temp[num];
    }
    else{
        goto redo;
    }
}

void XO::checkWin(){

    if(board[0][0] == turn && board[0][1] == turn && board[0][2] == turn){
        isGameover = turn;
    }
    else if(board[1][0] == turn && board[1][1] == turn && board[1][2] == turn){
        isGameover = turn;
    }
    else if(board[2][0] == turn && board[2][1] == turn && board[2][2] == turn){
        isGameover = turn;
    }
    else if(board[0][0] == turn && board[1][0] == turn && board[2][0] == turn){
        isGameover = turn;
    }
    else if(board[0][1] == turn && board[1][1] == turn && board[2][1] == turn){
        isGameover = turn;
    }
    else if(board[0][2] == turn && board[1][2] == turn && board[2][2] == turn){
        isGameover = turn;
    }
    else if(board[0][0] == turn && board[1][1] == turn && board[2][2] == turn){
        isGameover = turn;
    }
    else if(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn){
        isGameover = turn;
    }

    
}

void XO::drawBoard(){
    char temp[9];
    int k =0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == 0){
                temp[k] = (char)(k+49);
            }
            else{
                if(board[i][j] == 1){
                    temp[k] = (char)(88);
                }
                else{
                    temp[k] = (char)(79);
                }
            }
            k++;
        }
    }

    std::cout<<" "<<temp[0]<<" | "<<temp[1]<<" | "<<temp[2]<<std::endl;
    std::cout<<"***********\n";
    std::cout<<" "<<temp[3]<<" | "<<temp[4]<<" | "<<temp[5]<<std::endl;
    std::cout<<"***********\n";
    std::cout<<" "<<temp[6]<<" | "<<temp[7]<<" | "<<temp[8]<<std::endl;

}
