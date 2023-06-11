#!/bin/sh

clear

make re


# echo "\n\n---- Test 1 : 1 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=1
# 	random=$(python random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	./push_swap "$random"
# fi

# echo "\n\n\n---- Test 2 : 1 2 3 3 4 5 6 7 ----\n"
# if [ $? -eq 0 ]
# then
# 	n=10
# 	error_random=$(python random/error_randomizer.py $n)
# 	echo ./push_swap "$error_random"
# 	./push_swap "$error_random"
# fi

# echo "\n\n---- Test 3 : 3 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=3
# 	random=$(python random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	./push_swap "$random"
# fi

# echo "\n\n---- Test 4 : 5 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=5
# 	random=$(python random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	./push_swap "$random"
# fi

# echo "\n\n---- Test 5 : 100 random value ----\n"
# if [ $? -eq 0 ]
# then
# 	n=100
# 	random=$(python random/randomizer.py $n)
# 	echo ./push_swap "$random"
# 	numbers=$(./push_swap "$random")
# 	python visualizer.py "$numbers"
# fi

echo "\n\n---- Test 6 : 50 random value ----\n"
if [ $? -eq 0 ]
then
	n=30
	random=$(python random/randomizer.py $n)
	echo ./push_swap "$random"
	./push_swap "$random"
fi
