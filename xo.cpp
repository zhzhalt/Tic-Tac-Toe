#include <bits/stdc++.h>

using namespace std;

string name1, name2;
char p1, p2, turn, win;
int x, y;
char board[3][3];
bool over = false;

void initialize(char (&board)[3][3]) {
    for (int i = 0 ; i < 3; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            board[i][j] = '_';
        }
    }
    cout<<"Hi! We're gonna play tic-tac-toe. Player 1! What do you want to be called?"<<endl;
    cin>>name1;
    cout<<"And Player 2?"<<endl;
    cin>>name2;
    cout<<name1<<"! Do you want to be X or O?"<<endl;
    cin>>p1;
    if (p1 == 'X' || p1 == 'x')  {cout<<"Okay, "<<name2<<", you'll be O!"<<endl; p2 = 'O'; p1 = 'X';}
    else {cout<<"Okay, "<<name2<<", you'll be X!"<<endl; p2 = 'X'; p1 = 'O';}
    cout<<"Player 1 goes first!"<<endl;
    cout<<"Remember, your positions lie between 1 and 3!"<<endl;
    turn = p1;
}

void display(char (&board)[3][3]) {
    cout<<endl;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool checkpos(int x, int y) {
    if (!((x>=1 && x<=3) && (y>=1 && y<=3))) return false;
    return true;
}

bool check(char (&board)[3][3], char &win) {
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '_') {
        win = board[0][0]; 
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '_') {
        win = board[1][1]; 
        return true;
    }
    for (int i = 0 ; i < 3 ; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_') {
            win = board[i][0];
            return true;
        }
    }
    for (int j = 0 ; j < 3 ; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '_') {
            win = board[j][0];
            return true;
        }
    }
    return false;
}

int checkFull(char (&board)[3][3]) {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (board[i][j] == '_') return 1;
        }
    }
    cout<<"It's a draw!"<<endl;
    return 0;
}

int main() {
    initialize(board);
    while (!over) {
        display(board);
        if (turn == p1) {
            cout<<name1<<", enter the position you want to mark."<<endl;
            cin>>x>>y;
            if (!checkpos(x, y)) {
                cout<<"That's not a valid position! Enter a valid position."<<endl;
                continue;
            }
            board[x-1][y-1] = p1;
            turn = p2;
        }
        else {
            cout<<name2<<", enter the position you want to mark."<<endl;
            cin>>x>>y;
            if (!checkpos) {
                cout<<"That's not a valid position! Enter a valid position."<<endl;
                continue;
            }
            board[x-1][y-1] = p2;
            turn = p1;
        }
        if (check(board, win)) {
            over = true;
            break;
        }
        if (checkFull(board) == 0) return 0;
    }
    display(board);
    cout<<"Game over!"<<endl;
    if (p1 == win) cout<<name1<<", congratulations, you won!"<<endl;
    else cout<<name2<<", congratulations, you won!"<<endl;
}