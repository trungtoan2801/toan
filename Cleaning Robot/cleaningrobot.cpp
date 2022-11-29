#include<iostream>
using namespace std;
int row,column;
int map[101][101],dis[11][11];
int banx[11],bany[11],ban;
int visb[101][101],visd[11];
int check,result;
int que[100001];
int rear, front;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int Push(int a){
    //Hàm Push này để Push tọa độ điểm bẩn vào
    return que[++rear]=a;
}
int Pop(){
    //Hàm Pop này để lấy tọa độ điểm bẩn từ trong queue ra
    return que[front++];
}
//Hàm BFS này để tạo ma trận thông số khoảng cách từ điểm bẩn này đến điểm bẩn khác 
void BFS(int a){
    rear=-1,front=0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            //Ma trận khoảng cách từ robot đến các điểm bẩn khác và nó đến obstacle và quay lại
            visb[i][j]=0;
        }
    }
    //Push tọa độ điểm bẩn vào queue
    Push(banx[a]);
    Push(bany[a]);
    //Gán tọa độ điểm bẩn đó đã được visit
    visb[banx[a]][bany[a]]=1;
    while (rear>=front)
    {
        //Lấy điểm bẩn vừa Push vào queue ra
        int x=Pop();
        int y=Pop();
        for (int i = 0; i <= 3; i++)
        {
            //Xét 4 hướng 
            int r = x + dx[i];
            int c = y + dy[i];
            //Check edge
            if (r>=0 && c>=0 && r<row && c<column && !visb[r][c] && map[r][c]!=2)
            {
                //Tạo ma trận thông số khoảng cách từ điểm bẩn này đến điểm bẩn khác
                visb[r][c]=visb[x][y]+1;
                //Push tọa độ điểm robot đã chạy vào trong queue để tí có thể dùng lại và check hướng khác
                Push(r);
                Push(c);
            }
        }
    }
    for (int i = 0; i <= ban; i++)
    {
        //check để nó không vào vị trí và robot đang đứng
        if (i!=a)
        {
            //Tạo ma trận thông số khoảng cách điểm bẩn đến các điểm bẩn còn lại
            dis[a][i]=visb[banx[i]][bany[i]]-1;
        }
        
    } 
}

void DFS(int index, int tong, int pos){
    //check tong xem có lớn hơn k vì mình đang muốn tìm đường đi ngắn nhất
    if(tong>result) return;
    //check xem đẫ đi hết điểm bẩn chưa
    if(index==ban){
        //check xem tong nếu nhỏ hơn result thì đường đi đó tối ưu hơn
        if(tong<result) {
            result=tong;
            return;
        }
    }
    //gán tại vị trí đang xét =1 như là đã visit
    visd[pos]=1;
    for (int i = 0; i <= ban; i++)
    {
        //Nếu mà chưa thăm thì xét tiếp
        if (!visd[i])
        {
            //Nếu mà robot không đi được đg nào thì nó sẽ trả về biến check=1 
            if(dis[pos][i]==-1){
                check=1;
                return;
            }
            //Sau khi mà check xem có = -1 không thì nó sẽ backtrack lại DFS và tính tổng lên 
            DFS(index+1,tong+dis[pos][i],i);
        }
    }
    //Sau khi mà Backtrack xong thì nó sẽ gán lại vị trí vừa backtrack vs giá trị =0 như là chưa thăm để xét lại nhưng ô khác
    visd[pos]=0;
}


int main(){
    freopen("input.txt","r",stdin);
    int tc;
    cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        cout<<"Case #"<<t<<endl;
        cin>>row>>column;
        ban=0;
        check=0;
        result=1000000;
        //Tạo ma trận thông số khoảng cách từ điểm bẩn này đến điểm bẩn khác mà không đi qua tọa độ robot
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                dis[i][j]=0;
            }
        }
        /*Nhập map và check robot và điểm bẩn rồi gán vào mảng tọa độ điểm bẩn để tí lấy ra xét các điểm bẩn đó xem
        có đường đi nào tối ưu cho robot đi không*/ 
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cin>>map[i][j];
                if (map[i][j]==3)
                {
                    banx[0]=i;
                    bany[0]=j;
                    visd[0]=0;
                }
                else if (map[i][j]==1)
                {
                    ban++;
                    banx[ban]=i;
                    bany[ban]=j;
                    visd[ban]=0;
                }   
            }
        }
        //bfs các số điểm bẩn để tạo 1 ma trận thông số khoảng cách các điểm bẩn để xét xem đường đi nào tối ưu nhất
        for (int i = 0; i <= ban; i++)
        {
            BFS(i);
        }
        //gán dfs giá trị vs index, tong, pos = 0 để xét
        DFS(0,0,0);
        /*Check xem nếu mà check =0 thì robot có thể đi đc hết mà không bị chặn bởi gì
        còn nếu =1 thì bị chặn và không đi được*/
        if(!check){
            cout<<result<<endl;
        }
        else
            cout<<-1<<endl;
        
    }
    

    return 0;
}