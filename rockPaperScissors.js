const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
function play() {
    readline.question('Would you like rock(R), paper(P), or scissors(S)?', selection => {
        const compChoice = Math.floor(Math.random() * 3);
        // Simulates a win
        switch (compChoice) {
            case 0:
                if (selection == "R" || selection == "r") {
                    console.log('The computer picked scissors, you won!');
                } else if (selection == "P" || selection == "p") {
                    console.log('The computer picked rock, you won!');
                } else {
                    console.log('The computer picked paper, you won!');
                }
                break;
            // Simulates a loss
            case 1:
                if (selection == "R" || selection == "r") {
                    console.log('The computer picked paper, you lost!');
                } else if (selection == "P" || selection == "p") {
                    console.log('The computer picked scissors, you lost!');
                } else {
                    console.log('The computer picked rock, you lost!');
                }
                break;
            //Simulates a tie
            case 2:
                if (selection == "R" || selection == "r") {
                    console.log('The computer picked rock, you tied!');
                } else if (selection == "P" || selection == "p") {
                    console.log('The computer picked paper, you tied!');
                } else {
                    console.log('The computer picked scissors, you tied!');
                }
                break;
        }
        readline.close();
    })
}