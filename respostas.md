# Atividade das Aulas 02 e 03

## Armazenamento de dados em memória

Nome: Gabriel Lamarth Moreira Barbosa

Turma: TF - Engenharia de Controle e Automação

---

## Exercício 1 - Endereço, conteúdo e ponteiro

Considere o trecho:

`int x = 10;
int *p = &x; `

- O que está armazenado em x?
- O que está armazenado em p?
- Explique o significado das expressões &x, p, &p e *p.
- Após a instrução *p = 25;, qual passa a ser o valor de x? Justifique.

### a) 

Resposta: Em x, está armazenado o valor inteiro 10.

### b) 

Resposta: Em p, está armazenado o endereço do espaço de memória onde o valor 10, referente a variável x, está.


### c) 

Resposta: &x refere-se ao endereço de x. p refere-se ao ponteiro que aponta para x na memória. &p remete ao endereço do ponteiro p. e *p remete ao valor armazenado no espaço de memória apontado por p.

### d) 

Resposta: Após a instrução, o novo valor alocado no espaço de memória que p aponta passa a valer 25, ou seja, x passa a valer 25. Isso ocorre pois alteramos o valor contido no endereço armazenado no ponteiro, sobreescrevendo seus bits, resultando na alteração. Como x refere-se ao valor armazenado no mesmo endereço, seu valor também é alterado.

---

## Exercício 2 - Conteúdo da variável e conteúdo apontado

### a) 

Resposta: A primeira e a última linha retornam o valor inteiro 7. As demais linhas retornam endereços de memória.

### b) 

Resposta: As linhas 2 e 3 devem produzir o mesmo endereço.

### c) 

Resposta: Porque a expressão representa o endereço do ponteiro, ou seja, o endereço onde está armazenado o endereço de n, pois ponteiros também ocupam espaço na memória.

---

## Exercício 3 - Dois ponteiros para o mesmo dado

### a)

Resposta:

### b)

Resposta:

### c)

Resposta:

---

## Exercício 4 - Stack, Heap, new e delete

### a)

Resposta:

### b)

Resposta:

### c)

Resposta:

### d)

Resposta:

### e)

Resposta:

---

## Exercício 5 - Perda de referência à memória alocada

### a)

Resposta:

### b)

Resposta:

### c)

Resposta:

### d)

```cpp
// Código corrigido
```

---

## Exercício 6 - Ponteiro nulo

### a)

Resposta:

### b)

Resposta:

### c)

```cpp
// Código completo
```

---

## Exercício 7 - Vetor alocado dinamicamente

```cpp
// Programa completo
```

Explicação sobre `delete[]`:

---

## Exercício 8 - Passagem por valor, referência e ponteiro

### a)

Resposta:

### b)

Resposta:

### c)

Resposta:

### d)

Resposta:
