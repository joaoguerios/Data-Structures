class Queue {
    constructor() {
      this.items = [];
    }
  
    enqueue(item) {
      this.items.push(item);
    }
  
    dequeue() {
      if (this.isEmpty()) {
        throw new Error('A fila está vazia.');
      }
      return this.items.shift();
    }
  
    front() {
      if (this.isEmpty()) {
        throw new Error('A fila está vazia.');
      }
      return this.items[0];
    }
  
    isEmpty() {
      return this.items.length === 0;
    }
  
    size() {
      return this.items.length;
    }
  }
  
  module.exports = Queue;
  