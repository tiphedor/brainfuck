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
    
Is the default synopsis. It will execute the code located in the brainfuck_file.bf file and print the result to *stdout*. The ````,```` operator will read from *stdin*.
