const choices = ["Rock", "Paper", "Scissors"];
const resultElement = document.getElementById("result");
const computerChoiceElement = document.getElementById("computer-choice");
const playAgainButton = document.getElementById("play-again");

document.querySelectorAll(".choice").forEach(button => {
    button.addEventListener("click", () => {
        const userChoice = button.id.charAt(0).toUpperCase() + button.id.slice(1);  // Capitalize choice
        playGame(userChoice);
    });
});

playAgainButton.addEventListener("click", () => {
    resultElement.textContent = "";
    computerChoiceElement.textContent = "";
    playAgainButton.style.display = "none";
    document.querySelectorAll(".choice").forEach(button => {
        button.disabled = false;
    });
});

function playGame(userChoice) {
    const computerChoice = choices[Math.floor(Math.random() * 3)];
    
    // Display computer's choice with animation
    computerChoiceElement.textContent = "Computer is choosing...";
    setTimeout(() => {
        computerChoiceElement.textContent = `Computer chose: ${computerChoice}`;
        setTimeout(() => {
            const result = determineWinner(userChoice, computerChoice);
            resultElement.textContent = result;
            document.querySelectorAll(".choice").forEach(button => {
                button.disabled = true; // Disable buttons after choice
            });
            playAgainButton.style.display = "inline-block";
        }, 1000);
    }, 1000);
}

function determineWinner(userChoice, computerChoice) {
    if (userChoice === computerChoice) {
        return "It's a tie!";
    } else if (
        (userChoice === "Rock" && computerChoice === "Scissors") ||
        (userChoice === "Paper" && computerChoice === "Rock") ||
        (userChoice === "Scissors" && computerChoice === "Paper")
    ) {
        return "You win!";
    } else {
        return "You lose!";
    }
}
