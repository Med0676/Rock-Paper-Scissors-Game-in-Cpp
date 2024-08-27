# Rock, Paper, Scissors Game in C++

This repository contains a simple console-based implementation of the classic "Rock, Paper, Scissors" game using C++. The game allows a single player to play against the computer over multiple rounds, with results displayed at the end of each round and the entire game.

## Features

- **Interactive Gameplay**: The player can choose between Stone, Paper, or Scissors for each round, while the computer randomly selects its move.
- **Multiple Rounds**: Players can choose to play between 1 to 10 rounds per game session.
- **Detailed Results**: Each round's results are displayed, showing the player's choice, the computer's choice, and the round winner.
- **Final Results**: At the end of the game, the total number of wins, losses, and draws are displayed, along with the final winner.
- **Color-Coded Feedback**: The console screen changes color based on whether the player wins, loses, or draws.

## How to Run

### Prerequisites

- C++ Compiler (e.g., GCC, Clang)

### Compilation and Execution

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Med0676/rock-paper-scissors-cpp.git
    ```

2. **Navigate to the project directory**:
    ```bash
    cd rock-paper-scissors-cpp
    ```

3. **Compile the code**:
    ```bash
    g++ -o rps_game main.cpp
    ```

4. **Run the game**:
    ```bash
    ./rps_game
    ```

## Example Output

How Many Round 1 to 10 ? 3

Round [1] begin:

Your Choice : [1], [2], [3]Scissors ? 1

Player1 choice: Stone 
Computer choice: Scissors
Round Winner : [Player1]

____________ [2] ____________

Your Choice : [1], [2], [3]Scissors ? 2

Player1 choice: Paper 
Computer choice: Paper
Round Winner : [NO Winner]

____________ [3] ____________

Your Choice : [1], [2], [3]Scissors ? 3

Player1 choice: Scissors
Computer choice: Stone 
Round Winner : [Computer]

[Game Result ]______

Game Round : 3 
Player1 won times : 1
Computer won times : 1 
Draw times : 1 
Final Winner : NO Winner


## Future Improvements

- Implementing a graphical user interface (GUI).
- Adding multiplayer support for two players.
- Enhancing the computer's strategy with more complex AI.

## Contributing

Contributions are welcome! If you have any suggestions or find any bugs, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
