from random import randrange

def display_board(board):
    for row in board:
        print(f"{row[0]} {row[1]} {row[2]}")

def enter_move(board):
    while True:
        try:
            movimiento_usuario = int(input("Ingresa el numero del cuadro: "))
            if 1 <= movimiento_usuario <= 9:
                for i in range(3):
                    if movimiento_usuario in board[i]:
                        board[i][board[i].index(movimiento_usuario)] = 'O'
                        return
                print("Cuadro ocupado. Intentalo de nuevo.")
            else:
                print("Numero fuera de rango. Intentalo de nuevo.")
        except ValueError:
            print("Ingresa un numero valido.")

def make_list_of_free_fields(board):
    free_fields = []
    for i in range(3):
        for j in range(3):
            if isinstance(board[i][j], int):
                free_fields.append((i, j))
    return free_fields

def victory_for(board, sign):
    for i in range(3):
        if all(cell == sign for cell in board[i]) or all(board[j][i] == sign for j in range(3)):
            return True
    if all(board[i][i] == sign for i in range(3)) or all(board[i][2 - i] == sign for i in range(3)):
        return True
    return False

def draw_move(board):
    free_fields = make_list_of_free_fields(board)
    if free_fields:
        movimiento_maquina = randrange(len(free_fields))
        i, j = free_fields[movimiento_maquina]
        board[i][j] = 'X'

def jugar_tic_tac_toe():
    tablero = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    display_board(tablero)
    while True:
        print("\nTu turno (O):")
        enter_move(tablero)
        display_board(tablero)
        if victory_for(tablero, 'O'):
            print("\nTu ganas (O)")
            break
        if all(isinstance(cell, str) for row in tablero for cell in row):
            print("\nEmpate")
            break
        print("\nTurno de la máquina (X):")
        draw_move(tablero)
        display_board(tablero)
        if victory_for(tablero, 'X'):
            print("\nLa máquina (X) gana")
            break
        if all(isinstance(cell, str) for row in tablero for cell in row):
            print("\nEmpate")
            break

if __name__ == "__main__":
    jugar_tic_tac_toe()
