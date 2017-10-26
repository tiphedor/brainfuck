# brainfuck
brainfuck interpreter

# Installation

    git clone
    make

If you're *really* into brainfuck, you can even :

    sudo make install
    
Which will copy the program to /usr/local/bin by default. You can change that path by editing the *Makefile*.

# Usage

    bf brainfuck_file.bf
    
Is the default synopsis. Will execute the code located in the brainfuck_file.bf and print the result in *stdout*. The ````,```` operator will read from *stdin*.
 
## Using a custom size for the array

The default size of the brainfuck array is 30,000, you can change that size by specifying ````--array-size=xxxx````

    bf input.bf --array-size=300
