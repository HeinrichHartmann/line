### SYNOPSIS

    line <line_start> [line_end]

Returns given set of lines read from stdin.

### EXAMPLE

    ; seq 100 | line 4
    4

    ; seq 100 | line 4 6
    4
    5
    6

### INSTALLATION

    make

    # global install /usr/local/bin
    sudo make install
    
    # local install ~/bin
    make install PREFIX=$HOME
