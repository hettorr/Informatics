#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = 1e9;
constexpr int DIM = 1e3;

bool map[DIM][DIM];
int dist[DIM][DIM];

using namespace std;

class SWave{
private:
	const static int q_dir = 4;
	const int d_x[q_dir] {0, 0, 1, -1};
	const int d_y[q_dir] {1, -1, 0, 0};

	struct Coord{
		int x, y;
	};

	int q_row, q_col;
	
	inline bool is_valid(const int &x, const int &y){
		return (x < q_row) && (x >= 0) && (y < q_col) && (y >= 0) && (dist[x][y] == INF) && (map[x][y] == false);
	}
	
	void wave(const Coord &start){
		queue<Coord> Q;
		dist[start.x][start.y] = 0;
		Q.push(start);
		
		while (Q.empty() == false){
			auto [x,y] = Q.front(); Q.pop();
			for (int dir = 0; dir < q_dir; ++dir)
				if (is_valid(x + d_x[dir], y + d_y[dir])){
					dist[x + d_x[dir]][y + d_y[dir]] = dist[x][y] + 1;
					Q.push({x + d_x[dir], y + d_y[dir]});
				}
		}
	}
	
public:
	SWave():q_row(0), q_col(0){}
	SWave(const int &q_row, const int &q_col):q_row(q_row), q_col(q_col){}
	
	void input_map(istream &input){
		bool is_wall;
		for (int i = 0; i < q_row; ++i)
			for (int j = 0; j < q_col; ++j){
				input >> is_wall;
				map[i][j] = is_wall;
			}
	}
	
	int calc_dist(const Coord &start, const Coord &finish){
		for (int i = 0; i < q_row; ++i)
			for (int j = 0; j < q_col; ++j)
				dist[i][j] = INF;
		
		wave(start);
		
		return dist[finish.x][finish.y];
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int q_row, q_col; cin >> q_row >> q_col;
	SWave wave(q_row, q_col); wave.input_map(cin);
	
	int x_start, y_start, x_finish, y_finish; 
	cin >> y_start >> x_start >> y_finish >> x_finish;
	--x_start; --y_start; --x_finish; --y_finish;
	
	int dist = wave.calc_dist({x_start, y_start}, {x_finish, y_finish});
	cout << (dist == INF ? -1 : dist) << '\n';
	
	return 0;
}
