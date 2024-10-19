#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;

int visited[1000][1000]; //mảng đánh dấu trạng thái
int a,b,c;
int step[1000][1000]; //mảng đánh dấu số bước tương ứng kiểm tra trạng thái

int checkFinal(int x, int y){
    if (x == c || y == c || x + y == c){
        return 1;
    } 
    else return 0;
}

void solve(){
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            visited[i][j] = 0;
        }
    }
    int res;
    q.push({0,0});
    visited[0][0] = 1;
    step[0][0] = 0;
    while(!q.empty()){
        //Trạng thái là bộ (x, y): lượng nước có trong bình 1 và 2
        int x = q.front().first;
        int y= q.front().second;
        q.pop();
        res = step[x][y];
        if (checkFinal(x,y)) {
            cout << res;
            break;
        }
        //trạng thái mới được sinh ra từ trạng thái trước đó
        //đổ đầy bình 1 (a,y)
        if (visited[a][y] == 0){
            
            q.push({a,y}); //đưa trạng thái mới vào hàng đợi
            step[a][y] = res + 1;
            visited[a][y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ đầy bình 2 (x,b)
        if (visited[x][b] == 0){
            
            q.push({x,b}); //đưa trạng thái mới vào hàng đợi
            step[x][b] = res + 1;
            visited[x][b] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ hết bình 1 ra ngoài (0,y)
        if (visited[0][y] == 0){
            
            q.push({0,y}); //đưa trạng thái mới vào hàng đợi
            step[0][y] = res + 1;
            visited[0][y] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ hết bình 2 ra ngoài (x,0)
        if (visited[x][0] == 0){
            
            q.push({x,0}); //đưa trạng thái mới vào hàng đợi
            step[x][0] = res + 1;
            visited[x][0] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ nước từ bình 1 sang 2 
        int nx,ny;
        if (x + y >= b){
                nx = x + y - b;
                ny = b;
        }
        else if (x + y <= b){
                nx = 0; 
                ny = x + y;
        }
        if (visited[nx][ny] == 0){
            
            q.push({nx,ny}); //đưa trạng thái mới vào hàng đợi
            step[nx][ny] = res + 1;
            visited[nx][ny] = 1; //đánh dấu trạng thái được sinh ra
        }

        //đổ nước từ bình 2 sang 1 
        if (x + y >= a){
                ny = x + y - a;
                nx = a;
        }
        else if (x + y <= a){
                ny = 0; 
                nx = x + y;
            }
        if (visited[nx][ny] == 0){
            
            q.push({nx,ny}); //đưa trạng thái mới vào hàng đợi
            step[nx][ny] = res + 1;
            visited[nx][ny] = 1; //đánh dấu trạng thái được sinh ra
        }
        
    }
    if (res == 0) cout << -1;
}

int main(){
    cin >> a >> b >> c;
    solve();

}