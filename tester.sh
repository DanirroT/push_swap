#!/bin/bash

# A função 'gerar_argumentos' recebe o número de argumentos (N) como parâmetro
gerar_argumentos() {
    local N=$1

    # Verifica se o número de argumentos N foi fornecido
    if [ -z "$N" ] || ! [[ "$N" =~ ^[0-9]+$ ]] || [ "$N" -lt 1 ]; then
        echo "Uso: $0 <numero_de_argumentos>"
        exit 1
    fi

    # Definir o intervalo de números aleatórios a serem gerados.
    # Usamos um intervalo maior que N para garantir que haverá números suficientes
    # para escolher N números únicos (ex: N=500, Intervalo: 1 a 100000).
    local MIN_VALOR=1
    local MAX_VALOR=$((1000 > 2 * N ? 1000 : 2 * N)) # Garante um intervalo mínimo, e grande o suficiente

    # Gera N números inteiros aleatórios e únicos no intervalo definido, separados por espaço
    # O comando 'shuf' é ideal para gerar números aleatórios e garantir a unicidade (-i e -n)
    ARG=$(shuf -i $MIN_VALOR-$MAX_VALOR -n $N | tr '\n' ' ')

    # Remove o espaço em branco final (se houver) e imprime a lista de argumentos
    echo "Argumentos gerados (N=$N): $ARG"
}

# --- Execução Principal ---

# Recebe o número de argumentos do primeiro parâmetro do script
N_ARGS=$1

# 1. Gera a lista de números aleatórios e únicos
gerar_argumentos $N_ARGS

# 2. Executa o push_swap com o checker_linux
echo "--- Executando o teste ---"
# A variável ARG agora contém a lista de números, ex: "4 67 3 87 5"
# A saída do push_swap é redirecionada como entrada para o checker_linux
./push_swap $ARG 2> output.$N_ARGS.txt| ./checker_linux $ARG
grep "Sorting End" output.$N_ARGS.txt 

# Verifica o código de saída do checker (0 para OK, 1 para KO/erro)
CHECKER_STATUS=$?

echo "--- Resultado ---"
if [ $CHECKER_STATUS -eq 0 ]; then
    echo "✅ Resultado: OK (Números ordenados com sucesso!)"
else
    echo "❌ Resultado: KO (Houve um erro, os números NÃO estão ordenados, ou push_swap falhou.)"
fi