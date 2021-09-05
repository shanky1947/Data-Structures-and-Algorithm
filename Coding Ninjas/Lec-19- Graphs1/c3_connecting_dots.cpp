/*
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/

int a[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool checker(int i,int j,int n, int m){
    
    if(i>=0 &&j>=0 && i<n && j<m){
        
        return true;
    }
    return false;
}


int isCycle(char board[][MAXN],int n,int m,int i,int j,int**visited,char current,int count){
    
	if(visited[i][j]!=2)
        visited[i][j]=1;
    
    for(int q=0;q<8;q++){
        int x = i + a[q][0];
        int y = j + a[q][1];
        
        if(checker(x,y,n,m) && visited[x][y]==2 && count>=4)
           return 1;
       
        
        if(checker(x,y,n,m) && board[x][y]==current && visited[x][y] == 0){
            int temp = isCycle(board,n,m,x,y,visited,current,count+1);
            if(temp==1){
                return 1;
            }
        }
    }
    return 0;
    
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
      int ** visited = new int * [n];
    for(int i=0;i<n;i++){
        visited[i] = new int[m];
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            char current = board[i][j];
            int count = 1;
            visited[i][j] = 2;
            int temp =  isCycle(board,n,m,i,j,visited,current,count);
            visited[i][j] = 0;
            if(temp==1){
                return 1;
            }
        }
    }
    return 0;
    
}