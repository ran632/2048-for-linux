2048.c
======
#### The well known 2048 for Linux/UNIX/OSX Terminal

![screenshot](http://imageshack.com/a/img843/4002/w0vl.png)



### Gameplay

(from wikipedia)
2048 is played on a simple gray 4×4 grid with tiles of varying colors overlaid that slide smoothly when a player moves them. The game uses the arrow keys to move tiles left, right, up, and down. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. The resulting tile cannot merge with another tile again in the same move. Higher-scoring tiles emit a soft glow. Every turn, a new tile will randomly appear in an empty spot on the board with a value of either 2 or 4.

### Requirements

- C compiler
- GNU/Linux
- ncurses

### Install in System

To install the game on your system you will need root privileges. due to puting the 2048
executable in /urs/bin/

all saved files (like high scores etc.) will be save in:
/home/<youre user name>/.2048/
so to *reset* the score - just delete the hidden folder...

so, lets install. 

 - open up your favorite Terminal Emulator
 - Clone the project, or download the [Zip File](https://github.com/ran632/2048-for-linux/archive/master.zip)
 - Navigate to the folder (if needed - extract the zip)
 - run:
```shell
$ make install
```
this command will build the game (just like a simple "make"), create the necessary folders, and copy the exec to the destination.

Now to run it, you can open a terminal emulator and run:
```shell
$ 2048
```
from anywhere in your system.
OR

launch the game via your application launcher:

 - Ubuntu unity via the Dash
 - Gnome Shell via the app overview
 - Cinnamon/KDE/XFCE etc via the menu

**ENJOY**

#### Uninstall
so you had enough, and you just want to remove the game.
in case you deleted the build folder (this repository clone/zip)
you will need to download the Makefile to Uninstall the game The easy way. (if you still have the build folder - good for you!).

run:
```shell
$ make uninstall
```

enter your password and then delete the folder (or just the make file) of the repository.
thats it.

to remove manually:

 - fire up a terminal
 ```shell
 # rm /usr/bin/2048
 $ rm -r ~/.2048
 ```
 thats it...




### Build (for Developers...)
Clone the project, or download the [Zip File](https://github.com/ran632/2048-for-linux/archive/master.zip).
Navigate to the folder (if needed - extract the zip)
in this method - your High Score will not be saved...
your a developer, you dont really need the High Score :wink:

to build & run:

```shell
$ make
$ cd bin
$ ./2048
```

you will now have a build folder (with all the Object files) & a bin with the executable


### Clean 
Thare are 2 ways to clean.

- to delete only the build directory (keeping the executable) run:
```shell
$ make clean
```

- To delete all the build files and the Exec file:
```shell
$ make bclean
```