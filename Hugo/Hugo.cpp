#include<iostream>
using namespace std;
int row,column,xhugo,yhugo;
int fire, lake, out; 
int mapfire[501][501], maplake[501][501];
int xfire[501],yfire[501];
int xlake[501],ylake[501];
int xout[501],yout[501];
int rear,front;
int que[100001];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int vis[501][501];
int diamond[501][501];
int result;

int Push(int x){
    return que[++rear]=x;
}
int Pop(){
    return que[front++];
}

void BFS(){
    rear=-1,front=0;
    //Push tọa độ lửa vào queue
    for (int i = 1; i <= fire; i++)
    {
        Push(xfire[i]);
        Push(yfire[i]);   
    }
    while (rear>=front)
    {
        //Lấy tọa độ lửa từ queue
        int x=Pop();
        int y=Pop();
        //Dùng mảng dx[4],dy[4] thì phải cho chạy từ 0=>3 
        for (int i = 0; i <= 3; i++)
        {
            //for 4 hướng 
            int r= x + dx[i];
            int c= y + dy[i];
            //check edge
            if (r<1 || c<1 || r>row || c>column)
            {
                continue;
            }
            //check mapfire nếu có bằng 0 thì chạy và cộng dần khi đến các điểm
            if (mapfire[r][c]==0)
            {
                Push(r);
                Push(c);
                mapfire[r][c]=mapfire[x][y]+1;
            }   
        }   
    }   
    //Sau cùng sẽ có mapfire vs các khoảng cách đến các điểm như time chạy
}

void DFS(int x, int y, int sum, int time){
    //check time xem nếu mà bằng time vs lửa chạy thì không đc
    if(time>=mapfire[x][y] && mapfire[x][y]>0){ 
    return;
    }
    //check nếu gặp lối thoát thì so sánh các sum nếu có số diamond lớn nhất thì lấy
    else if(maplake[x][y]==10000){
        if (sum>result)
        {
            result=sum;
        }   
    }
    //đánh dấu đã visit tọa độ hugo
    vis[x][y]=1;
        for (int i = 0; i <= 3; i++)
        {
            //for 4 hướng check hugo đi
            int r = x + dx[i];
            int c = y + dy[i];
            //check edge
            if (r<1 || c<1 || r>row || c>column)
            {
                continue;
            }
            //check xem hugo đã visit chưa
            if(!vis[r][c]){
            if (mapfire[r][c]==-1)
            {
                //nếu mà gặp -1 thì là gặp hồ thì time+2 và gọi lại dfs 
                DFS(r,c,sum + diamond[r][c],time+2);
            }
            else
                //nếu k thì đi đg bình thường thì time+1 và gọi lại dfs
                DFS(r,c,sum + diamond[r][c], time+1);
            }
        }
        //gán lại visit chưa thăm cái tọa độ để check hướng khác
    vis[x][y]=0;
}

int main(){
    freopen("input1.txt","r",stdin);
    int tc;
    cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        cout<<"Case #"<<t<<endl;
        cin>>row>>column>>xhugo>>yhugo;
        result=-1;
        //Tạo map lửa, map hồ, matrix visit = 0
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column; j++)
            {
                mapfire[i][j]=0;
                maplake[i][j]=0;
                vis[i][j]=0;
            }
        }
        //matrix fire 
        cin>>fire;
        for (int i = 1; i <= fire; i++)
        {
            cin>>xfire[i]>>yfire[i];
            mapfire[xfire[i]][yfire[i]]=1;
        }
        //Matrix lake
        cin>>lake;
        for (int i = 1; i <= lake; i++)
        {
            cin>>xlake[i]>>ylake[i];
            mapfire[xlake[i]][ylake[i]]=-1;
        }
        //Matrix exit
        cin>>out;
        for (int i = 1; i <= out; i++)
        {
            cin>>xout[i]>>yout[i];
            maplake[xout[i]][yout[i]]=10000;
        }
        //Matrix diamond
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column; j++)
            {
                cin>>diamond[i][j];
            }
            
        }
        
        BFS();
        DFS(xhugo,yhugo,diamond[xhugo][yhugo],1);

        cout<<result<<endl;
        
        
    }
    
    return 0;
}