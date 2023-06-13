#!/bin/sh

clear

make re

#!/bin/bash

# Check the operating system
OS=$(uname)

# Set the Python executable based on the operating system
if [ "$OS" = "Linux" ]; then
    PYTHON_EXECUTABLE="python3"
elif [ "$OS" = "Darwin" ]; then
    PYTHON_EXECUTABLE="python"
else
    echo "Unsupported operating system."
    exit 1
fi

# Use the Python executable in your script
# $PYTHON_EXECUTABLE your_script.py

# echo "\n\n---- Test 1 : 1 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=1
# 	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	./push_swap "$random"
# fi

# echo "\n\n\n---- Test 2 : 1 2 3 3 4 5 6 7 ----\n"
# if [ $? -eq 0 ]
# then
# 	n=10
# 	error_random=$($PYTHON_EXECUTABLE random/error_randomizer.py $n)
# 	echo ./push_swap "$error_random"
# 	./push_swap "$error_random"
# fi

echo "\n\n---- Test 3 : 1-- random value ----\n"
if [ $? -eq 0 ]
then
	n=100
	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
	echo ./push_swap "$random"
	./push_swap "$random"
fi

# echo "\n\n---- Test 4 : 5 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=5
# 	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	./push_swap "$random"
# fi

# echo "\n\n---- Test 5 : 100 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=100
# 	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	numbers=$(./push_swap "$random")
# 	$PYTHON_EXECUTABLE visualizer.py "$numbers"
# fi

# echo "\n\n---- Test 5 : 10 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=10
# 	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	numbers=$(./push_swap "$random")
# 	$PYTHON_EXECUTABLE visualizer.py "$numbers"
# fi

# echo "\n\n---- Test 5 : 5 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=5
# 	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	numbers=$(./push_swap "$random")
# 	# $PYTHON_EXECUTABLE visualizer.py "$numbers"
# fi
# echo "\n\n---- Test 6 : 30 random values ----\n"
# if [ $? -eq 0 ]
# then
# 	n=30
# 	random=$($PYTHON_EXECUTABLE random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	./push_swap "$random"
# fi

