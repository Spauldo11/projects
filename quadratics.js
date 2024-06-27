const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
// Positive answer
function positive(one, two, three) {
    let x = 0;
    one = parseInt(one);
    two = parseInt(two);
    three = parseInt(three);
    // x = -b
    x = -two;
    // b^2
    two = two *= two;
    // 4(a)(c)
    three *= one;
    three *= 4;
    // sqrt b^2 - 4(a)(c)
    let sqrt = two -= three;
    let finalRoot = Math.sqrt(sqrt);
    //-b + sqrt
    x += finalRoot;
    // 2a
    one *= 2;
    // all divided by 2a
    let finalX = x / one;
    if (sqrt < 0) {
        return 'imaginary';
    } else {
        return finalX;
    }
}
// Negative answer
function negative(one, two, three) {
    let y = 0;
    one = parseInt(one);
    two = parseInt(two);
    three = parseInt(three);
    // x = -b
    y = -two;
    // b^2
    two = two *= two;
    // 4(a)(c)
    three = three *= one;
    three *= 4;
    // sqrt b^2 - 4(a)(c)
    let sqrt = two -= three
    let finalRoot = Math.sqrt(sqrt);
    y -= finalRoot;
    // 2a
    one = one *= 2;
    // all divided by 2a
    let finalY = y / one;
    if (sqrt < 0) {
        return 'imaginary';
    } else {
        return finalY;
    }
}
console.log('Note: a coefficient is the number attached to a variable and a constant is a regular number with no variable.')
readline.question('What is the first coefficient in your quadratic equation: ', numOne => {
    readline.question('What is the second coefficient in your quadratic equation: ', numTwo => {
        readline.question('What is the constant in your quadratic equation: ', numThree => {
            console.log(`Your answers are ${positive(numOne, numTwo, numThree)} and ${negative(numOne, numTwo, numThree)}`);
            readline.close();
        })
    })
})