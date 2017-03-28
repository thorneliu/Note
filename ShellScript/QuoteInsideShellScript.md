# Single Quote

A string with Single quote in shell script will literally print everything inside the
string, even the special variables such as `$HOME` will be printed as `$HOME`, not as
`/home/jack`:

```
[legend@legend01 ~]$ echo 'print $HOME'
print $HOME
[legend@legend01 ~]$
```
As we can see everything inside Single quote will be printed out, what we see inside
the command is what will be printed out.

Another example:
```
[legend@legend01 ~]$ echo 'print a string with double quote "Hello world"'
print a string with double quote "Hello world"
```

# Double Quote

Use double quotes when you want to display the real meaning of special variables.
The real meaning of some variables will be extracted by shell. For example:

```
[legend@legend01 ~]$ echo "print $HOME"
print /home/legend
[legend@legend01 ~]$
```

As we can see `"$HOME"` is printed as `/home/legend` because the real meaning of 
`$HOME` is extracted. 

Another example:
```
[legend@legend01 ~]$ echo "print current time `date`"
print current time Tue Mar 28 14:10:05 CST 2017
[legend@legend01 ~]$
```
Double quotes will remove the special meaning of all characters except the following:

* $ Parameter Substitution.
* ` Backquotes
* \$ Literal Dollar Sign.
* \´ Literal Backquote.
* \” Embedded Doublequote.
* \\ Embedded Backslashes.`
