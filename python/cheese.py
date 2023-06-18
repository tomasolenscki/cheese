import pygame
import sys
import serial

bluetoothSerial = serial.Serial(port='COM10', baudrate=9600, timeout=0)

def transforma_matriz(a):
    matriz = []
    colunas = []
    colunas = a.split('<')[1].split('>')[0].split(' ')
    for i in range(len(colunas)-1):
        matriz.append(colunas[i].split(',')[:-1])

    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            matriz[i][j] = int(matriz[i][j] )

    return matriz

# Inicializando o Pygame
pygame.init()

# Definindo cores
BRANCO = (255, 255, 255)
PRETO = (0, 0, 0)
BRANCO = (255, 255, 255)
PRETO = (0, 0, 0)
MARROM = (139, 69, 19)
AMARELO = (255, 255, 0)

# Definindo o tamanho das células do tabuleiro e o número de células
CELL_SIZE = 100
NUM_CELLS = 5
JOGADOR_1 = 1
JOGADOR_2 = 2
NEUTRON = 3


# Criando a janela do jogo
window = pygame.display.set_mode((CELL_SIZE * NUM_CELLS, CELL_SIZE * NUM_CELLS))

# Inicializando o tabuleiro

def draw_board():
    for y in range(NUM_CELLS):
        for x in range(NUM_CELLS):
            rect = pygame.Rect(x*CELL_SIZE, y*CELL_SIZE, CELL_SIZE, CELL_SIZE)
            pygame.draw.rect(window, BRANCO, rect, 1)
            if tabuleiro[y][x] != 0:
                if tabuleiro[y][x] == JOGADOR_1:
                    color = MARROM
                elif tabuleiro[y][x] == JOGADOR_2:
                    color = BRANCO
                elif tabuleiro[y][x] == NEUTRON:
                    color = AMARELO
                pygame.draw.circle(window, color, rect.center, CELL_SIZE//2-5)

string = "<0,1,2,3,0, 0,1,2,3,0, 0,1,2,3,0, 0,1,2,3,0, 0,1,2,3,0, >"
while True:
    data = bluetoothSerial.readline()

    if data:
        string = data.decode('ascii')
    
    tabuleiro = transforma_matriz(string)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    
    window.fill((0, 0, 0))
    draw_board()
    
    pygame.display.update()