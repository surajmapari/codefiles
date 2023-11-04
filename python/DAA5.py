def is_safe(board, row, col, n):
    # Check if no Queen is attacking in the same column
    for i in range(row):
        if board[i][col] == 1:
            return False
    
    # Check upper-left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check upper-right diagonal
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(board, row, n):
    if row == n:
        return True

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1

            if solve_n_queens(board, row + 1, n):
                return True

            board[row][col] = 0

    return False

def print_board(board):
    for row in board:
        print(" ".join(["Q" if cell == 1 else "." for cell in row]))

def n_queens(n):
    board = [[0 for _ in range(n)] for _ in range(n)]
    if solve_n_queens(board, 0, n):
        print("Solution:")
        print_board(board)
    else:
        print("No solution found.")

# Example usage:
n = 4  # Change this to the desired board size

n_queens(n)
