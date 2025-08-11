class Solution {

bool checkHorizontal(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        unordered_map<char,int> mp;
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                mp[board[i][j]]++;
                if(mp[board[i][j]]>1) return 0;
            }
        }
    }
    return 1;
}

bool checkVertical(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        unordered_map<char,int> mp;
        for(int j=0;j<9;j++){
            if(board[j][i]!='.'){
                mp[board[j][i]]++;
                if(mp[board[j][i]]>1) return 0;
            }
        }
    }
    return 1;
}

bool check(vector<vector<char>>& board, int h, int v){
    cout<<h<<v<<"hv"<<endl;
    unordered_map<char,int> mp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<h+i<<v+j<<" ";
            if(board[h+i][v+j]!='.'){
                mp[board[h+i][v+j]]++;
                if(mp[board[h+i][v+j]]>1) return 0;
            }
        }
    }
    cout<<endl;
    return 1;
}

bool checkBoxes(vector<vector<char>>& board){
    // 00 01 02 10 11 12 20 21 22
    // 03 04 05 13 14 15 23 24 25
    // 06 07 08 16 17 18 26 27 28


    bool b;
    b=check(board,0,0);
    if(!b) return 0;
    b=check(board,0,3);
    if(!b) return 0;
    b=check(board,0,6);
    if(!b) return 0;
    b=check(board,3,0);
    if(!b) return 0;
    b=check(board,3,3);
    if(!b) return 0;
    b=check(board,3,6);
    if(!b) return 0;
    b=check(board,6,0);
    if(!b) return 0;
    b=check(board,6,3);
    if(!b) return 0;
    b=check(board,6,6);
    if(!b) return 0;
    return 1;
    
}

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool b=checkHorizontal(board);
        if(!b) return 0;
        b=checkVertical(board);
        if(!b) return 0;
        b=checkBoxes(board);
        return b;
    }
};