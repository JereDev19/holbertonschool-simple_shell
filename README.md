<h1 align="center">Simple shell - Project at Holberton School</h1>
<br>

<h2>Introduction:</h2>

<p>This is a very important project at Holberton School that consist of making our own shell with a limited amount of functions and a perfect memory management.</p>

<br>

<h2> How to shell works: </h2>
<p> A shell is a computer program that provides a command-line interface (CLI) for interacting with an operating system. The shell takes user input, processes it and executes it on the operating system.
When a user enters a command into the shell, the shell parses it and breaks it into different parts. The shell then searches the user-defined and default search paths to find the program that matches the entered command. Once found, the shell loads the program into memory and provides it with the arguments entered by the user. </p>

<br></br>

<h2>List of allowed functions and system calls:</h2>
<br>

| Function | Description | `man` Command |
| --- | --- | --- |
| `access` | Checks file access permissions. | `man 2 access` |
| `chdir` | Changes the current working directory. | `man 2 chdir` |
| `close` | Closes a file descriptor. | `man 2 close` |
| `closedir` | Closes a directory stream. | `man 3 closedir` |
| `execve` | Executes a program. | `man 2 execve` |
| `exit` | Terminates the calling process. | `man 3 exit` |
| `_exit` | Terminates the calling process. | `man 2 _exit` |
| `fflush` | Flushes a stream. | `man 3 fflush` |
| `fork` | Creates a new process by duplicating the calling process. | `man 2 fork` |
| `free` | Deallocates memory previously allocated by `malloc`, `calloc`, or `realloc`. | `man 3 free` |
| `getcwd` | Gets the current working directory. | `man 3 getcwd` |
| `getline` | Reads an entire line of input from a stream. | `man 3 getline` |
| `getpid` | Gets the process ID of the calling process. | `man 2 getpid` |
| `isatty` | Tests whether a file descriptor refers to a terminal. | `man 3 isatty` |
| `kill` | Sends a signal to a process. | `man 2 kill` |
| `malloc` | Allocates memory. | `man 3 malloc` |
| `open` | Opens a file. | `man 2 open` |
| `opendir` | Opens a directory stream. | `man 3 opendir` |
| `perror` | Prints a system error message to standard error. | `man 3 perror` |
| `printf` | Prints formatted output to standard output. | `man 3 printf` |
| `fprintf` | Prints formatted output to a stream. | `man 3 fprintf` |
| `vfprintf` | Prints formatted output to a stream, using a variable argument list. | `man 3 vfprintf` |
| `sprintf` | Prints formatted output to a string. | `man 3 sprintf` |
| `putchar` | Writes a character to standard output. | `man 3 putchar` |
| `read` | Reads data from a file descriptor. | `man 2 read` |
| `readdir` | Reads a directory. | `man 3 readdir` |
| `signal` | Installs a signal handler. | `man 2 signal` |
| `stat` | Gets file status. | `man 2 stat` |
| `lstat` | Gets file status, ignoring symbolic links. | `man 2 lstat` |
| `fstat` | Gets file status from a file descriptor. | `man 2 fstat` |
| `strtok` | Breaks a string into tokens. | `man 3 strtok` |
| `wait` | Waits for a child process to terminate. | `man 2 wait` |
| `waitpid` | Waits for a specific child process to terminate. | `man 2 waitpid` |
| `wait3` | Waits for a child process to terminate and returns resource usage information. | `man 2 wait3` |
| `wait4` | Waits for a specific child process to.

<br></br>

## List of built-ins
<br>


cd
<br>
- Changes the current working directory.

echo
<br>
- Displays a message on the screen.

exit
<br>
- Exist the shell

export
<br>
- Sets a environment variable.

history
<br>
- Displays the shell command history.

kill
<br>
- Sends a signal to a running process.

pwd
<br>
- Displays the current working directory.

read
<br>
- Reads a line of user input and stores it in a variable.

source
<br>
- Executes a script in the current shell context.

alias
<br>
Creates an alias for a command.

unalias
<br>
Removes a previously created alias.

set
<br>
Displays or sets shell options.

unset
<br>
Deletes an environment variable or a user-defined function.

type
<br>
Displays informaton about a command.

<br></br>
<br></br>

<div align="center">

## Commands
<br>

| Command | Description |
| --- | --- |
| ls | List the contents of a directory. Can be used with various options to show details such as file sizes, permissions, and timestamps. |
| cd | Changes the current working directory. |
| pwd | Displays the current working directory. |
| mkdir | Creates a new directory. Can also be used with options to set directory permissions or create parent directories. |
| touch | Creates an empty file or updates the timestamp of an existing file. |
| rm | Deletes a file or directory. Can also be used with options to force deletion, prompt for confirmation, or delete recursively. |
| cp | Copies a file or directory. Can be used with options to preserve file attributes, copy recursively, or prompt before overwriting. |
| mv | Moves or renames a file or directory. Can also be used to move files between directories or to rename multiple files at once. |
| less | Displays the contents of a file in paginated form. Allows navigation and search within the file. |
| ps | Displays information about running processes. Can be used with options to show detailed information such as process IDs, memory usage, and CPU usage. |
| kill | Sends a signal to a running process to stop it. Can be used with options to specify the signal to send or to send the signal to a specific process ID. |
| top | Displays real-time information about the system processes. Shows the processes using the most CPU and memory resources. |
| cat | Displays real-time information about the system processes. Shows the processes using the most CPU and memory resources. |

_Note: To access the help documentation for each command, you can use the `man` command followed by the command name or use the `--help` option when running the command._

</div>

<br></br>

## Usage
<br>

1) - Clone the repository.
``` 
git clone https://github.com/JereDev19/holbertonschool-simple_shell
```

2) - Move to the repository
``` 
cd holbertonschool-simple_shell
``` 

3) - Compile it.
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

<br></br>
## How to use it
<br>

```
prompt$ ./hsh
```

<br></br>


## Examples Command
<br>

```
username@prompt:~$ ./hsh
$ ls
AUTHORS  README.md  a.out  aux_functions.c  get_path.c  hsh  man_1_simple_shell  more_aux_functions.c  shell.c  shell.h
```

```
username@prompt:~$ ./hsh
$ ls -la
total 84
drwxr-xr-x 3 root root  4096 Apr 27 11:47 .
drwxr-xr-x 5 root root  4096 Apr 26 12:20 ..
drwxr-xr-x 8 root root  4096 Apr 27 10:30 .git
-rw-r--r-- 1 root root   147 Apr 27 08:16 AUTHORS
-rw-r--r-- 1 root root  1710 Apr 27 11:45 README.md
-rwxr-xr-x 1 root root 18096 Apr 27 11:47 a.out
-rw-r--r-- 1 root root  1518 Apr 26 15:21 aux_functions.c
-rw-r--r-- 1 root root  1026 Apr 27 11:26 get_path.c
-rwxr-xr-x 1 root root 18096 Apr 27 08:36 hsh
-rw-r--r-- 1 root root     1 Apr 26 12:20 man_1_simple_shell
-rw-r--r-- 1 root root   774 Apr 26 15:20 more_aux_functions.c
-rw-r--r-- 1 root root  1412 Apr 27 10:56 shell.c
-rw-r--r-- 1 root root   770 Apr 27 08:09 shell.h
```
<br>

```
username@prompt:~$ ./hsh
$ pwd
/home/simple_shell/
$ env
username@prompt:~$ ./hsh
$ env
HOSTNAME=11548ecbb7ce
LANGUAGE=en_US:en
PWD=/home/simple_shell/k
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
LC_ALL=en_US.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/home
```
<br>

```
username@prompt:~$ ./hsh
$ ps
PID TTY          TIME CMD
 7148 pts/5    00:00:00 bash
22314 pts/5    00:00:00 a.out
22374 pts/5    00:00:00 ps
```

<br>

```
If you want to see more commands, we invite you to try the executable !. :)
```
<br>

<p align="center">
<a href="https://github.com/JereDev19/holbertonschool-simple_shell"><strong>Explore the docs »</strong></a>
</p>

## Authors

* **Jeremias Erba** - *Holberton Student* - [Jeremias Erba](https://github.com/JereDev19/) - *Software development and team leadership.*
* **Gabriel Acosta** - *Holberton Student* - [Gabriel Acosta](https://github.com/GabiAcosta) - *Software Developer.*
