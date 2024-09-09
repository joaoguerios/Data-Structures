const readline = require("readline");
const Stack = require('./pilha.js');
const Queue = require('./fila.js');

const minhaPilha = new Stack();
minhaPilha.push(10);
minhaPilha.push(20);
minhaPilha.push(30);
console.log('Topo da pilha:', minhaPilha.peek());
minhaPilha.pop(); 
console.log('Topo da pilha após remoção:', minhaPilha.peek()); 
console.log('A pilha está vazia?', minhaPilha.isEmpty()); 
console.log('Tamanho da pilha:', minhaPilha.size()); 


const minhaFila = new Queue();
minhaFila.enqueue(10);
minhaFila.enqueue(20);
minhaFila.enqueue(30);
console.log('Elemento na frente da fila:', minhaFila.front());
minhaFila.dequeue(); 
console.log('Elemento na frente da fila após remoção:', minhaFila.front());
console.log('A fila está vazia?', minhaFila.isEmpty()); 
console.log('Tamanho da fila:', minhaFila.size()); 

