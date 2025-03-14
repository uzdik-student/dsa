import math

def calculate_entropy(group):
    # Если группа пуста, её энтропия считается равной 0
    if not group:
        return 0.0

    n = len(group)
    counts = {
        0: 0,
        1: 0
    }
    for _, _, c in group:
        counts[c] += 1

    # Энтропия равна 0, если в группе точки только одного класса
    if counts[0] == n:
        return 0.0
    if counts[1] == n:
        return 0.0

    probabilities = [count / n for count in counts.values() if count > 0]
    return -sum(p * math.log2(p) for p in probabilities)

n = int(input())
points = []
for _ in range(n):
    x, y, c = map(float, input().split())
    points.append((x, y, int(c)))

b = float(input())

left_group = [point for point in points if point[0] < b]
right_group = [point for point in points if point[0] >= b]

left_entropy = calculate_entropy(left_group)
right_entropy = calculate_entropy(right_group)

n_left = len(left_group)
n_right = len(right_group)
entropy = (n_left / n) * left_entropy + (n_right / n) * right_entropy

print(round(entropy, 2))

