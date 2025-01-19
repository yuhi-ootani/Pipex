#!/bin/bash

# ============================
# Color Definitions
# ============================
# Reset
RESET="\033[0m"

# Bold Colors for Headers
BOLD_CYAN="\033[1;36m"
BOLD_PURPLE="\033[1;35m"
BOLD_RED="\033[1;31m"

# Regular Colors for Outputs
GREEN="\033[0;32m"
YELLOW="\033[1;33m"

# ============================
# Assign Arguments to Variables
# ============================
INPUTFILE="$1"
CMD1="$2"
CMD2="$3"
OUTFILE="$4"

echo -e "${BOLD_CYAN}\n=== pipex result ===${RESET}"
# Execute the pipex program
./pipex "$INPUTFILE" "$CMD1" "$CMD2" "$OUTFILE"
cat "$OUTFILE"

echo -e "${BOLD_PURPLE}\n=== shell result ===${RESET}"
# Execute the equivalent shell command
< "$INPUTFILE" $CMD1 | $CMD2 > "$OUTFILE"
cat "$OUTFILE"

# Check memory leaks using valgrind
echo -e "${BOLD_RED}\n=== Memory Leak Check ===${RESET}"
valgrind --leak-check=full --track-fds=yes --trace-children=yes ./pipex "$INPUTFILE" "$CMD1" "$CMD2" "$OUTFILE" 
echo
