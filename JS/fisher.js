function fisherYatesShuffle(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
}

const deck = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];
console.log(`baralho normal : ${deck}`);
for (let x = 0; x < 100; x++) {
    fisherYatesShuffle(deck);
    console.log(`baralho diferente : ${deck}`);
}
