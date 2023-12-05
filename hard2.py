def shortest_palindrome(s):
    if not s:
        return ""

    # Function to check if a string is a palindrome
    def is_palindrome(string):
        return string == string[::-1]

    # Find the longest palindrome substring starting from the beginning of s
    for i in range(len(s), 0, -1):
        if is_palindrome(s[:i]):
            # Construct the shortest palindrome by adding the reversed remaining substring in front of s
            return s[i:][::-1] + s

# Example usage:
s1 = "aacecaaa"
s2 = "abcd"

output1 = shortest_palindrome(s1)
output2 = shortest_palindrome(s2)

print(output1)  
print(output2) 

