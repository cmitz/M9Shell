# Shell

This shell was created by Casper Smits (s402588) in may 2019.

## Requirements

This project was made to be opened with CLion. Just open the folder as an existing project. Then, use CLions green play button to run the shell. This uses the `cmake` version embedded with CLion.

Alternatively, use the following commands. This requires `cmake`.

```
cd <source path CMakeList.txt>
cmake -Bbuild -H.
cmake --build build --target all
```

## Features

This shell has three build-in commands:

| Command | Description |
|:--------|:------------|
| `exit`	| Makes the shell quit. Exit code 0 |
| `pwd` 	| Returns the current working directory |
| `cd`		| Changes the working directory. Without arguments, changes to `~/`. |


You can, of cource, execute programs – the shell will wait for that program to finish:

```bash
echo "Hello world!" # -> Hello World!
```

It supports piping output and input streams like so: 

```bash
./outputs | grep Lorem # -> O: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
```

It also supports output redirection like so:

```bash
./outputs > textfile.txt 2> errors.txt
./outputs > textfile.txt 2>&1
```

TODO: It shouls be supporting sequences, but at the moment, it does not.

## Implementation details

The pwd, cd and program commands are pretty straight-forward. The most interesting part is that I catch forking errors (exit with -1), that I used a switch case for the IO Redirection flags and that a new file will have the permission 0664 (maybe that should be inherited from parent folder, doesn't it?).

The piping was a challenge. In the implementation proces, I switched approaches three times – rewriting the piping from scratch. I first did one pipe, then tried to allow a second pipe (three commands) and then I had a massive proces leak – I don't know how or why. I just had to kill some processes (grep) via the CLI. I guess it was still listening to input.

The second approach was first creating **all** the necessary pipes in a vector, and one-by-one fork a proces and correctly pipe it. But, keeping track of what was happening was extremely tricky, and the code was unmaintainable. 

The third approach is the current approach, and is is not much code. It uses the existing IORedirects to redirect output. However, piping more than two commands together still doesn't work, and I cannot figure out a better approach.

Maybe this would work with some recursion. But then again, how to wait properly on the child processes?

#### Sequencing

Since sequencing does not seem to be part of the grading proces, I decided to not support that. I had a hard enough time in C++ and with pipes already, and decided to focus on the compiler.
