# Tic-Tac-Toe

## Settings file

The settings file can be any file extension and must contain values for M, N and K. The game board has a width of M and a height of N. A player needs to match K tiles in a row to win. In the file a setting is declared with `M=<value>`, this is case insensitive. The order the settings are in does not matter but they must be separated by new lines.

## Compilation

If the program has been previously compiled, the files can be cleaned up with make clean. To compile the program normally, use `make`. To run it in editor mode, which allows the changing of the game settings at runtime, use `make EDITOR=1`. To run in secret mode, which disables the ability to save logs to file, use `make SECRET=1`.

## Running the program

When running the program, you must provide the name of the settings file as a command-line argument. To do this, use `./tictactoe <filename>`. An error will be displayed if there is a problem with the settings file and the program will close.
Using the main menu
When the program is run, the main menu is shown, listing all available options. Each option is lead by a number in square brackets (eg. `[1]`). This is the number you must enter to select that menu option.

## Playing the game

When the game is running, each turn a graphical representation of the board will be printed to the screen. The board is displayed as a grid, with empty tiles empty and filled tiles with a coloured ‘X’ or ‘O’. Player O goes first. To take a turn, type the coordinates of the tile you wish to place your symbol, comma separated. The coordinates of each square are shown on the sides of the board for your reference. For example, to play at coordinates (1,2), enter `1,2`. If for any reason the selection was invalid, you will be prompted to choose again. Once the game is over, either from a player winning or a stalemate from the board being full, you are sent back to the main menu.

## The logfile

When you choose to save your logs to file, the program will display the filename in which they are saved. This filename includes the settings of the game and the date and time. The file shows the settings of the game (if compiled in editor mode, the last used settings) and the logs for each game. Each game is assigned a number, and each log has a turn number for that game, a player and x and y coordinates. This exact information can also be displayed to the terminal with the view logs option in the main menu.
