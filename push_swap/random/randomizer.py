# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    randomizer.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 13:57:58 by pcazac            #+#    #+#              #
#    Updated: 2023/06/12 16:59:10 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import random

def generate_random_integers(n):
    random_integers = random.sample(range(1, 101), n)
    return random_integers

n = int(sys.argv[1])
random_numbers = generate_random_integers(n)
output = ' '.join(['' + str(num) + '' for num in random_numbers])
print(output)