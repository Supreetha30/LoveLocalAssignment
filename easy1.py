def length_of_last_word(s):
    # Split the string into words using whitespaces as separators
    words = s.split()

    # Check if there are any words in the list
    if words:
        # Return the length of the last word
        return len(words[-1])
    else:
        # If there are no words, return 0
        return 0

# Example usage:
s1 = "Hello World"
s2 = "   fly me   to   the moon  "
s3 = "luffy is still joyboy"

output1 = length_of_last_word(s1)
output2 = length_of_last_word(s2)
output3 = length_of_last_word(s3)

print(output1)  
print(output2) 
print(output3) 