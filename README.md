# Shell

This shell was created by Casper Smits (s402588) in may 2019.

## Requirements

This project was made to be opened with CLion. Just open the folder as an existing project. Then, use CLions green play button to run the shell. This uses the `cmake` version embedded with CLion.

Alternatively, use the following commands. This requires `cmake`.

```bash
cd <source path CMakeList.txt>
cmake -Bbuild -H.
cmake --build build --target all
```

The build output has also been provided in the `build` folder. 

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

The shell does **not** support sequences. It also does not support running something in the background with the suffix `&`.

## Implementation details

The pwd, cd and program commands are pretty straight-forward. The most interesting part is that I catch forking errors (exit with -1), that I used a switch case for the IO Redirection flags, and that a new file will have the permission 0664 (maybe that should be inherited from parent folder, doesn't it?).

### Piping attempts 

The piping was a challenge. In the implementation proces, I switched approaches four times – rewriting the piping from scratch. I first allowed one pipe, then tried to allow a second pipe (three commands) and then I had a massive proces leak – I don't know how or why. I just had to kill some processes (grep) via the CLI. I guess it was still listening to input.

The second approach was first creating **all** the necessary pipes in a vector, and one-by-one fork a proces and correctly pipe it. But, keeping track of what was happening was extremely tricky, and the code was unmaintainable. 

The third approach is the second-to-last approach, and is is not much code. It uses the existing IORedirects to redirect output. However, piping **more than two commands together still didn't work**, and I could not figure out a better approach. *This version of the code is available in branch* `master_old`.

> Two weeks passed between approach #3 and #4. On the day of the deadline, I had an epiphany.

### Final piping approach

In the last and current approach, I branched from an earlier commit, just to not mess up what was *kind of working*. In this approach, I limited the amount of forking, and keep track of two pipes and iterate over the commands. An old one (previous) and a new one (next), since we need a structure like this:

```
  cmd0    cmd1   cmd2   cmd3   cmd4  
     pipe0   pipe1  pipe2  pipe3  
     [0,1]   [2,3]  [4,5]  [6,7]  
```

When doing command `cmd1` there will be a reference to pipe0 and pipe1, but not pipe2 or pipe3.

This results in the following code:

```cpp
// Keep reference of the pipes between commands
int new_pipefd[2];
int old_pipefd[2];

for( SimpleCommand *cmd : commands ) {
	//...
	
	// If not last command, create pipe
    if (isNotLastCommand) {
        // Create Pipe
        pipe(new_pipefd);
    }	

	// Fork this process
   pid_t cid = fork();
   
   // Do the piping and executing
   // ...
}
```

In the end, the child process executes and exits, the parent will wait for it to end. **After that** the parent will move to the next command. That means there is a chance for buffer overflowing if the output of a file is too large.

#### Sequencing

Since sequencing does not seem to be part of the grading proces (sequencing was not mentioned in the grading distribution), I decided to not support that. I had a hard enough time in C++ and with pipes already, and decided to focus on the compiler.

#### Final note on code style

I don't like C++ and I don't really know what its style conventions are. That is why you will find variables in camelCase as well as snake_case. Sorry about that.
