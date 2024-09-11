import random

def generar_arreglo(cantidad, minimo, maximo, ordenado=False, descendiente=False):
    """
    Genera un arreglo de números aleatorios.
    
    :param cantidad: Número de elementos en el arreglo
    :param minimo: Valor mínimo de los números
    :param maximo: Valor máximo de los números
    :param ordenado: Si True, el arreglo estará ordenado
    :return: Arreglo de números aleatorios
    """
    if cantidad <= 0:
        return []

    arreglo = [random.randint(minimo, maximo) for _ in range(cantidad)]

    if ordenado:
        arreglo.sort()

    if descendiente:
        arreglo.reverse()

    return arreglo

# Ejemplo de uso:
cantidad = int(input("Cantidad de números en el arreglo: "))
minimo = int(input("Valor mínimo: "))
maximo = int(input("Valor máximo: "))
ordenado = input("¿Ordenar los números? (sí/no): ").strip().lower() == 'si'
descendiente = input("¿Invertir los números? (sí/no): ").strip().lower() == 'si'

arreglo = generar_arreglo(cantidad, minimo, maximo, ordenado, descendiente)
print(arreglo)