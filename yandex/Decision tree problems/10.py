import math
import random

# Probabilities of letters
probabilities = {
    "A": 0.5,
    "B": 0.25,
    "C": 0.15,
    "D": 0.1
}

# Calculate entropy
entropy = -sum(p * math.log2(p) for p in probabilities.values())

# Round to two decimal places
round(entropy, 2)



population = ["A", "B", "C", "D"]
weights = [0.5, 0.25, 0.15, 0.1]
k = 20
s = ''.join(random.choices(population, weights=weights, k=k))
print(s)

# BDACAAAAAAACAACADBAA A=13 B=2 C=3 D=2
# BDACACABCCABAAABBADD A=8 B=5 C=4 D=3
# AABAAAACBCABAACAAACA A=13 B=3 C=4 D=0