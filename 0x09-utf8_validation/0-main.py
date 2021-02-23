#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data), True)

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data), True)

data = [229, 65, 127, 256]
print(validUTF8(data), False)

data = [243, 129, 129, 129]
print(validUTF8(data), True)

data = [127, 127, 0]
print(data)
print(validUTF8(data), True)

data = [122, 195, 129, 127]
print(validUTF8(data), True)

data = []
print(validUTF8(data), True)

data = [0, 129]
print(validUTF8(data), False)

data = [129, 0]
print(validUTF8(data), False)

data = [122, 243, 129, 127, 129]
print(validUTF8(data), False)

data = [122, 243, 129, 129, 129]
print(validUTF8(data), True)

data = [634, 755, 641, 641, 641]
print(validUTF8(data), True)

data = [634, 755, 641, 639, 641]
print(validUTF8(data), False)

data = [634, 707, 641, 639]
print(validUTF8(data), True)
