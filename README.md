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

### Build
Clone the project, or download the [Zip File](https://github.com/ran632/2048-for-linux/archive/master.zip).
Navigate to the folder (if needed - extract the zip)

to build & run:

```shell
$ make
$ ./2048
```

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