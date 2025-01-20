class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()  # Split the string into words
        if len(pattern) != len(words):  # If lengths don't match, return False
            return False
        
        char_to_word = {}
        word_to_char = {}
        
        for char, word in zip(pattern, words):
            # Check if there's a mismatch in the mapping
            if char in char_to_word and char_to_word[char] != word:
                return False
            if word in word_to_char and word_to_char[word] != char:
                return False
            
            # Create the mapping
            char_to_word[char] = word
            word_to_char[word] = char
        
        return True
