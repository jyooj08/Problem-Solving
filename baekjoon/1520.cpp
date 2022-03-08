#include<iostream>
#include<queue>
using namespace std;

typedef struct point{
  int x, y;
  int height;

  point(int _x, int _y, int _h): x(_x), y(_y), height(_h) {}

  bool operator<(const point p) const {
    return this->height > p.height;
  }
}Point;

int main(){
  int m, n;
  int arr[500][500], route[500][500];
  priority_queue<Point> heap;
  fill_n(route[0], 500*500, 0);

  cin >> m >> n;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++) {
      cin >> arr[i][j];
      heap.push(Point(i, j, arr[i][j]));
    }
  }

  route[m-1][n-1] = 1;
  while(!heap.empty()){
    Point cur = heap.top();
    heap.pop();
    int x = cur.x, y = cur.y;

    if(x-1>=0 && arr[x-1][y] > arr[x][y]) route[x-1][y] += route[x][y];
    if(x+1<m && arr[x+1][y] > arr[x][y]) route[x+1][y] += route[x][y];
    if(y-1>=0 && arr[x][y-1] > arr[x][y]) route[x][y-1] += route[x][y];
    if(y+1<n && arr[x][y+1] > arr[x][y]) route[x][y+1] += route[x][y];

    // cout << x << ", " << y << endl;
    // for(int i=0;i<m;i++){
    //   for(int j=0;j<n;j++) cout << route[i][j] << ' ';cout <<endl;
    // }cout << endl;
  }

  cout << route[0][0] << endl;

  return 0;
}