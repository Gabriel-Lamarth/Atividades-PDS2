# Atividade das Aulas 02 e 03

**Nome:** Gabriel Lamarth Moreira Barbosa  
**Turma:** TF - Engenharia de Controle e Automação  
**Tema:** Armazenamento de dados em memória, ponteiros e alocação dinâmica  

---

## Exercício 1 - Endereço, conteúdo e ponteiro

Considere o trecho de código abaixo:

```cpp
int x = 10;
int *p = &x;
```

* **a)** O que está armazenado em `x`?
* **b)** O que está armazenado em `p`?
* **c)** Explique o significado das expressões `&x`, `p`, `&p` e `*p`.
* **d)** Após a instrução `*p = 25;`, qual passa a ser o valor de `x`? Justifique.

### Respostas

* **a)** Em `x`, está armazenado o valor inteiro 10.
* **b)** Em `p`, está armazenado o endereço do espaço de memória onde o valor 10, referente a variável `x`, está.
* **c)** `&x` refere-se ao endereço de `x`. `p` refere-se ao ponteiro que aponta para `x` na memória. `&p` remete ao endereço do ponteiro `p`. e `*p` remete ao valor armazenado no espaço de memória apontado por `p`.
* **d)** Após a instrução, o novo valor alocado no espaço de memória que `p` aponta passa a valer 25, ou seja, `x` passa a valer 25. Isso ocorre pois alteramos o valor contido no endereço armazenado no ponteiro, sobreescrevendo seus bits, resultando na alteração. Como `x` refere-se ao valor armazenado no mesmo endereço, seu valor também é alterado.

---

## Exercício 2 - Conteúdo da variável e conteúdo apontado

Considere o programa abaixo:

```cpp
int n = 7;
int *ptr = &n;

cout << n << endl;
cout << &n << endl;
cout << ptr << endl;
cout << &ptr << endl;
cout << *ptr << endl;
```

* **a)** Indique quais linhas exibem um valor inteiro e quais exibem um endereço de memória.
* **b)** Quais expressões devem produzir o mesmo endereço?
* **c)** Por que `&ptr` não representa o endereço de `n`?

### Respostas

* **a)** A primeira e a última linha retornam o valor inteiro 7. As demais linhas retornam endereços de memória.
* **b)** As linhas 2 e 3 devem produzir o mesmo endereço.
* **c)** Porque a expressão representa o endereço do ponteiro, ou seja, o endereço onde está armazenado o endereço de `n`, pois ponteiros também ocupam espaço na memória.

---

## Exercício 3 - Dois ponteiros para o mesmo dado

Analise o trecho abaixo:

```cpp
int *p1, *p2;
p1 = new int;
*p1 = 42;
p2 = p1;

cout << *p1 << " " << *p2 << endl;

*p2 = 53;

cout << *p1 << " " << *p2 << endl;
```

* **a)** Qual é a saída das duas linhas?
* **b)** Explique por que a alteração feita por meio de `p2` também pode ser observada por meio de `p1`.
* **c)** Escreva a instrução adequada para liberar a memória alocada.

### Respostas

* **a)** 
* **b)** 
* **c)** 

---

## Exercício 4 - Stack, Heap, new e delete

Considere o trecho abaixo:

```cpp
int a = 10;
int *p = new int;
*p = 20;
```

* **a)** Em qual região da memória fica a variável local `a`?
* **b)** Em qual região da memória fica a variável local `p`?
* **c)** Em qual região fica o inteiro reservado por `new int`?
* **d)** Qual instrução deve ser executada para liberar essa memória?
* **e)** Por que as variáveis locais não exigem o mesmo gerenciamento manual?

### Respostas

* **a)** 
* **b)** 
* **c)** 
* **d)** 
* **e)** 

---

# Aula 03 - Uso seguro de ponteiros e passagem de parâmetros

---

## Exercício 5 - Perda de referência à memória alocada

Considere o trecho abaixo:

```cpp
int *a;
int b = 10;

a = new int;
*a = 20;
a = &b;
*a = 30;
```

* **a)** Qual é o valor de `b` ao final?
* **b)** O que acontece com a região reservada por `new int` depois de `a = &b;`?
* **c)** Identifique o erro de gerenciamento de memória.
* **d)** Reescreva o trecho para liberar corretamente a memória antes de fazer `a` apontar para `b`.

### Respostas

* **a)** 
* **b)** 
* **c)** 
* **d)**

```cpp
// Código corrigido
```

---

## Exercício 6 - Ponteiro nulo

Considere a declaração:

```cpp
int *p = nullptr;
```

* **a)** O que `nullptr` representa?
* **b)** É válido executar `*p = 10;` nesse estado? Explique.
* **c)** Complete o código abaixo para alocar memória, verificar o ponteiro, armazenar o valor 90 e liberar a memória.

### Respostas

* **a)** 
* **b)** 
* **c)**

```cpp
int *p = nullptr;

// complete aqui
```

---

## Exercício 7 - Vetor alocado dinamicamente

Escreva um programa C++ que:
1. Leia um valor inteiro positivo n;
2. Aloque dinamicamente um vetor de n inteiros;
3. Leia os n elementos;
4. Calcule e exiba a soma dos elementos;
5. Libere corretamente a memória alocada.

Na resposta, explique por que a liberação deve ser feita com `delete[]`, e não com `delete`.

### Resposta

```cpp
#include <iostream>

using namespace std;

int main() {
    // Insira a solução aqui
    
    return 0;
}
```

**Explicação sobre `delete[]`:**

---

## Exercício 8 - Passagem por valor, referência e ponteiro

Analise o programa abaixo:

```cpp
#include <iostream>
using namespace std;

void addOneValue(int x) {
    x++;
}

void addOneReference(int &x) {
    x++;
}

void addOnePointer(int *x) {
    (*x)++;
}

int main() {
    int n = 10;

    addOneValue(n);
    cout << n << endl;

    addOneReference(n);
    cout << n << endl;

    addOnePointer(&n);
    cout << n << endl;
}
```

* **a)** Qual é a saída do programa?
* **b)** Por que `addOneValue` não altera a variável `n`?
* **c)** Explique como `addOneReference` e `addOnePointer` conseguem alterar o parâmetro real.
* **d)** Segundo as notas de aula, quando se deve preferir referência e quando o uso de ponteiro é necessário?

### Respostas

* **a)** 
* **b)** 
* **c)** 
* **d)** 
```
