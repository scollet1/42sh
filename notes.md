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
###### hash table
	- O(1) lookup
	- potential for collisions
	- memory inefficient

###### queue [x]
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


### "; Separator"

# Optional

## Inhibitors
### "\"/\"  \"\"\" \"\'\""

## "Globbing / Regex"

## "Back Quotes \"`\""

## Sub Shells

## Local Variables
### Unset

### Export

## Command History (BIG ONE)
### "! Builtin"

## Line Edition

## File Descriptors and Read

## Dynamic Autocompletion (BIG ALSO)

## Job Control (Even BIGGER)
### Jobs

### fg bg

### Background Process &

## Shell Script
