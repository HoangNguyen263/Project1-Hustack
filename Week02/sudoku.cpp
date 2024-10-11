#include <iostream>
using namespace std;

int m[9][9];  // Ma trận 9x9 chứa Sudoku

// Hàm kiểm tra xem có thể đặt giá trị v tại vị trí (row, col) không
bool isValid(int row, int col, int v) {
    // Kiểm tra hàng
    for (int i = 0; i < 9; i++) {
        if (m[row][i] == v) return false;
    }
    // Kiểm tra cột
    for (int i = 0; i < 9; i++) {
        if (m[i][col] == v) return false;
    }
    // Kiểm tra ô vuông 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[startRow + i][startCol + j] == v) return false;
        }
    }
    return true;
}

// Hàm giải Sudoku và trả về số lượng lời giải
int solveSudoku(int row, int col) {
    // Nếu đã qua dòng cuối cùng, tức là bảng đã được điền hoàn chỉnh
    if (row == 9) return 1;

    // Chuyển sang cột tiếp theo hoặc dòng tiếp theo
    if (col == 9) return solveSudoku(row + 1, 0);

    // Nếu ô hiện tại đã có giá trị (khác 0), tiếp tục sang ô tiếp theo
    if (m[row][col] != 0) return solveSudoku(row, col + 1);

    int count = 0;  // Đếm số lượng lời giải
    // Thử các giá trị từ 1 đến 9
    for (int v = 1; v <= 9; v++) {
        if (isValid(row, col, v)) {
            m[row][col] = v;  // Đặt giá trị v tại ô (row, col)

            // Giải tiếp phần còn lại của bảng
            count += solveSudoku(row, col + 1);

            // Trả lại giá trị 0 để thử giá trị khác (backtrack)
            m[row][col] = 0;
        }
    }

    return count;  // Trả về tổng số lượng lời giải
}

int main() {
    // Nhập bảng Sudoku
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> m[i][j];
        }
    }

    // Gọi hàm giải Sudoku và in ra số lượng lời giải
    cout << solveSudoku(0, 0) << endl;

    return 0;
}
