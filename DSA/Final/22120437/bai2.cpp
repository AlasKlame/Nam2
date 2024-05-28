#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Position {
    int row;
    int col;
};

bool is_valid(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

bool is_wall(char cell) {
    return cell == '#';
}

bool find_treasure(char** grid, int m, int n, Position start) {
    queue<Position> q;
    q.push(start);

    bool visited[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    visited[start.row][start.col] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();
        if (grid[current.row][current.col] == '$') {
            return true;
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int next_row = current.row + dx[i];
            int next_col = current.col + dy[i];
            if (is_valid(next_row, next_col, m, n) && !visited[next_row][next_col] && !is_wall(grid[next_row][next_col])) {
                q.push({next_row, next_col});
                visited[next_row][next_col] = true;
            }
        }
    }

    return false;
}

int main() {
    ifstream input_file("bai2.in");
    ofstream output_file("bai2.out");

    int m, n;
    input_file >> m >> n;

    char** grid = new char*[m];
    for (int i = 0; i < m; i++) {
        grid[i] = new char[n];
    }

    Position start;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            input_file >> grid[i][j];
            if (grid[i][j] == 'Y') {
                start = {i, j};
            }
        }
    }

    bool found = find_treasure(grid, m, n, start);

    if (found) {
        output_file << "YES";
    } else {
        output_file << "NO";
    }

    for (int i = 0; i < m; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    input_file.close();
    output_file.close();

    return 0;
}