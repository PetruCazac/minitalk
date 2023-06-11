# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_randomizer.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 14:28:01 by pcazac            #+#    #+#              #
#    Updated: 2023/06/11 14:44:01 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

def generate_random_numbers(n):
    numbers = []
    for _ in range(n - 1):
        numbers.append(random.randint(0, 2000))  # Adjust the range as needed

    # Add a duplicate number
    duplicate_number = random.choice(numbers)
    numbers.append(duplicate_number)

    # Shuffle the numbers
    random.shuffle(numbers)

    # Convert the numbers to a string separated by spaces
    numbers_string = ' '.join(map(str, numbers))
    return numbers_string

if __name__ == '__main__':
    n = int(sys.argv[1])  # Get the input size from the shell script argument
    result = generate_random_numbers(n)
    print(result)