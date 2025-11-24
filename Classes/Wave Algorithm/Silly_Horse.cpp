#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <vector>

constexpr int INF = 1e9;
constexpr int DIM = 8;

using namespace std;

struct Coord{
	int x, y;
};

Coord str_to_coord(const string& str){
	return {str[0] - 'a', str[1] - '1'};
}

string coord_to_str(const Coord& coord){
	string res(1, static_cast<char>('a' + coord.x));
	res.append(1, static_cast<char>('1' + coord.y));
	return res;
}

int dist[DIM][DIM];
Coord par[DIM][DIM];

class SHorse{
private:
	const static int q_dir = 8;
	const int d_x[q_dir] {2,  2, -2, -2,  1, -1,  1, -1};
	const int d_y[q_dir] {1, -1,  1, -1,  2,  2, -2, -2};

	int q_row, q_col;
	
	inline bool is_valid(const int &x, const int &y){
		return (x < q_row) && (x >= 0) && (y < q_col) && (y >= 0) && (dist[x][y] == INF);
	}
	
	void wave(const Coord &start){
		queue<Coord> Q;
		dist[start.x][start.y] = 0;
		par[start.x][start.y] = {-1,-1};
		Q.push(start);
		
		while (Q.empty() == false){
			auto [x,y] = Q.front(); Q.pop();
			for (int dir = 0; dir < q_dir; ++dir)
				if (is_valid(x + d_x[dir], y + d_y[dir])){
					dist[x + d_x[dir]][y + d_y[dir]] = dist[x][y] + 1;
					par[x + d_x[dir]][y + d_y[dir]] = {x,y};
					Q.push({x + d_x[dir], y + d_y[dir]});
				}
		}
	}
	
public:
	SHorse():q_row(8), q_col(8){}
	SHorse(const int &q_row, const int &q_col):q_row(q_row), q_col(q_col){}
	
	void calc_map(const Coord &start){
		for (int i = 0; i < q_row; ++i)
			for (int j = 0; j < q_col; ++j)
				dist[i][j] = INF;
		
		wave(start);
	}
	
	int get_dist(const Coord &finish){
		return dist[finish.x][finish.y];
	}
	
	void get_way(const Coord &finish, vector<Coord> &way){
		Coord curr = finish;
		while (curr.x != -1){
			way.push_back(curr);
			curr = par[curr.x][curr.y];
		}
		reverse(way.begin(), way.end());
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string str_start, str_finish; cin >> str_start >> str_finish;
	Coord start = str_to_coord(str_start), finish = str_to_coord(str_finish); 
	
	SHorse horse;	
	horse.calc_map(start);
	
	vector<Coord> way;
	horse.get_way(finish, way);
	
	for (const Coord &pos : way)
		cout << coord_to_str(pos) << '\n';
	
	return 0;
}
