class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def starts_with(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True
        
    def func(self, word):
        node = self.root
        e = ""
        for char in word:
            if char not in node.children:
                return word
            
            node = node.children[char]
            e = e + char
            if node.is_end_of_word:
                return e
            
            
            
        return word
        
        


class Solution(object):
    def replaceWords(self, dictionary, sentence):
        
        L = []
        LL = sentence.split()
        trie = Trie()
        
        for root in dictionary:
            trie.insert(root)
            
        for word in LL:
            L.append(trie.func(word))
        
        
        return " ".join(L)