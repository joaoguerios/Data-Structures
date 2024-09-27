'''
Joao Pedro Costa Guerios GRR20234965
'''


def busca_sequencial(array, n):
    '''
    busca sequencial
    '''
    resultados_sequenciais = []
    for i, value in enumerate(array):
        if value == n:
            resultados_sequenciais.append(i)
    if len(resultados_sequenciais) == 0:
        print("Nada encontrado na busca sequencial.")
    else:
        print("Índices encontrados na busca sequencial:", resultados_sequenciais)


def busca_binaria(array, n):
    '''
    busca binaria
    '''
    resultados_binarios = []
    left, right = 0, len(array) - 1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] == n:
            left = mid - 1
            right = mid + 1
            while array[left] == mid:
                resultados_binarios.append(mid-left)
                left -= 1
            resultados_binarios.append(mid)
            while array[right] == mid:
                resultados_binarios.append(mid+right)
                right += 1
            break
        elif array[mid] < n:
            left = mid + 1
        else:
            right = mid - 1

    if len(resultados_binarios) == 0:
        print("Nada encontrado na busca binária.")
    else:
        print("Índices encontrados na busca binária:", resultados_binarios)


ARRAY = [3, 8, 1, 7, 3, 8, 3]
CHAVE = 3
busca_sequencial(ARRAY, CHAVE)
busca_binaria(sorted(ARRAY), CHAVE)
