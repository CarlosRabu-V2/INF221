import random

def generar_matriz(filas, minimo, maximo):
    """
    Genera una matriz de números aleatorios.
    
    :param filas: Número de filas en la matriz
    :param columnas: Número de columnas en la matriz
    :param minimo: Valor mínimo de los números
    :param maximo: Valor máximo de los números
    :return: Cadena que representa la matriz
    """
    if filas <= 0:
        return ""
    
    matriz = []
    for _ in range(filas):
        fila = [random.randint(minimo, maximo) for _ in range(filas)]
        matriz.append(' '.join(map(str, fila)))
    
    return '\n'.join(matriz)

# Ejemplo de uso:
filas = int(input("Número de filas: "))
minimo = int(input("Valor mínimo: "))
maximo = int(input("Valor máximo: "))
5
matriz = generar_matriz(filas, minimo, maximo)
print(matriz)
