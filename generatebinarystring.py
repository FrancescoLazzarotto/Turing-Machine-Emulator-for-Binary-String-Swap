import random

def generate_binary_string(length):
    return ''.join(random.choice(['0', '1']) for _ in range(length))


num_strings = 5


string_length = 10


for _ in range(num_strings):
    random_string = generate_binary_string(string_length)
    print(random_string)
