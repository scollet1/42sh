# Mandatory

## Command Consumption
### Simple Command Execution


### $PATH

## Builtins w/ POSIX Specs

### cd
change directory

### echo
parse an parameterized string and display the result

### exit
leave the shell bro

### Environment Variables
##### What are these and how do we store them?
They are variable referenced in the shell environment and will only last the lifetime of the shell unless
	they are declared in a configuration file

##### How to store them in memory?
- [ ] hash table
 - O(1) lookup
 - potential for collisions
 - memory inefficient

- [x] queue
 - O(1) insertion
 - O(n) lookup
 - memory efficient
 - easy to work w/, implement, conceptualize

#### env
display environment variables
iterate our list of env variables and print them to screen with a newline after every print

#### setenv
set environment variables
insert an environment variable to the list of variables

#### unsetenv
remove an environment variable from the list of variables

## Pipes, Redirects, Logical Ops... etc...
### Error and Return Values
Display the process exit value or display the error if an error occurred

### Redirections
#### <

#### >
Redirect output of some process to a file

#### >>
Append the output of some process to a file
 - open(fd) as w+

#### |
Pipe the output of one process as input to another process
 - This is determined by a queue of execution??

#### &>$(fd)
Redirect output to file descriptor

#### Advanced Redirection
##### File Output Aggregation

##### Heredoc <<
Special-purpose code block
Uses redirection to feed a command list to an interactive program or command

### Logical Operators
#### && ||
Evaluation of two arguments at a time

### ; Separator
Commands separated by a ";" are executed sequentially with the shell waiting for each command to terminate in turn
The return status is the exit status of the last command executed

# Optional

## Inhibitors
### "\"/\"  \"\"\" \"\'\""
"Stringifies" characters or sequences of characters

## "Globbing / Regex"
Expanding wild cards

### *
Greedily consumes characters before, after, or sandwiched between another string of characters
By itself, it consumes all

### ?
Single-character consumption

## "Back Quotes \"`\""
Everything enclosed in back-ticks is evaluated before a given command
Its output is then used as input for that command

## Sub Shells ()
A subshell is a separate instance of the command processor

## Local Variables
### Unset
Seems to be the same as unsetenv

### Export
Export exposes variables to other programs

## Command History (BIG ONE)
### !
Runs the command given to it with a previous invocation and its parameters
```
$> echo "hello"
hello
$> !echo
echo "hello"
hello
```

### !!
Executes previous command

## Line Edition


## File Descriptors
A list of fds that either must already exist (0, 1, 2) or must be opened before referencing

## Read
Read from parameters on the command line

## Dynamic Autocompletion (BIG ALSO)
Reference the command history, I believe using termcaps
It would be helpful to store this list in memory for a short period and then dump to disk periodically for efficiency
Afterwards the file with history will be referenced... a la .bash_history...
Another option with the same motivation is to maintain a list of commands and dedicate a wait-free thread to pulling from the head while commands are appended to the tail

## Job Control (Even BIGGER)
### Jobs / ps
List the jobs running in the background

### fg bg
fg(foreground) switches a job running in the background(bg) to the foreground
bg restarts a suspended job and runs it in the background

### Background Process &
Fork a process and run it in the bg

## Shell Script
Allow shell-script parsing and execution on the command line and from a file
