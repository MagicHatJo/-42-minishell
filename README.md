# [42] minishell

The second project of the Unix branch at 42. Basic requirements are to recreate a basic working shell, with a few required builtins. History was implemented as a bonus builtin. Enviromental variables need to be set up and maintained. In the event that a command is input that is not a builtin, an attempt is made to execute it as is, followed by checking all paths for a valid matching executable.

### Builtins Implemented

```
cd
echo
env
exit
history
setenv
unsetenv
```

### Possible Optimization

The official ls on macs, at the time of this writing, utilizes 38 flags. Adding more flags for a more complete recreation would be the next step.

## Final Score

125/100

## Usage

### Compilation

Compiler:

```
clang-6.0
```

Dependencies:

```
libft
readline
```

### Execution

How to run:

```
./minishell
```

## Example

```
./minishell
minishell > echo "Hello"
Hello
minishell >
```

## Norme

This project is coded in accordance with the school's norms. A full copy of the norm can be found [here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf).
