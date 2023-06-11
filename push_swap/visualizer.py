# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visualizer.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 15:19:29 by pcazac            #+#    #+#              #
#    Updated: 2023/06/11 15:36:24 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import matplotlib.pyplot as plt

def create_graph(numbers):
    plt.barh(range(len(numbers)), numbers)
    plt.xlabel('Numbers')
    plt.ylabel('Order')
    plt.title('Output Graph')
    plt.show()

# Read input numbers from command-line argument
input_string = sys.argv[1]
input_numbers = [int(number) for number in input_string.split('\n')]

create_graph(input_numbers)