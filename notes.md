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

#### setenv
set environment variables

#### unsetenv
unset environment variables

## Pipes, Redirects, Logical Ops... etc...
### Error and Return Values

### Redirections
#### <

#### >> >

#### |

#### Advanced Redirection
##### File Output Aggregation

##### Heredoc <<

### Logical Operators
#### "&& ||"

#### "& |"

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
