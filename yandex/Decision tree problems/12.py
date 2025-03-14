import math

class DecisionTreeNode:
    def __init__(self, split_feature=None, split_value=None, left=None, right=None, class_label=None):
        self.split_feature = split_feature
        self.split_value = split_value
        self.left = left
        self.right = right
        self.class_label = class_label

def calculate_entropy(points):
    if not points:
        return 0.0
    
    total = len(points)
    class_counts = {
        0: 0,
        1: 0
    }
    for _, _, _, c in points:
        class_counts[c] += 1

    probabilities = [count / total for count in class_counts.values() if count > 0]
    return -sum(p * math.log2(p) for p in probabilities)

def split_points(points, feature, value):
    left = [point for point in points if point[feature] < value]
    right = [point for point in points if point[feature] >= value]
    return left, right

def build_decision_tree(points):
    if not points:
        return None

    current_entropy = calculate_entropy(points)
    if current_entropy == 0:  # All points belong to the same class
        return DecisionTreeNode(class_label=points[0][3])

    best_split = None
    best_entropy = float('inf')
    best_left, best_right = None, None

    for feature in range(3):  # Features: Age (0), Income (1), Credit History (2)
        unique_values = sorted(set(point[feature] for point in points))
        for value in unique_values:
            left, right = split_points(points, feature, value)
            left_entropy = calculate_entropy(left)
            right_entropy = calculate_entropy(right)
            weighted_entropy = (len(left) / len(points)) * left_entropy + (len(right) / len(points)) * right_entropy

            if weighted_entropy < best_entropy:
                best_entropy = weighted_entropy
                best_split = (feature, value)
                best_left, best_right = left, right

    if best_split is None:
        majority_class = max({0: sum(1 for _, _, _, c in points if c == 0), 1: sum(1 for _, _, _, c in points if c == 1)}, key=lambda k: k)
        return DecisionTreeNode(class_label=majority_class)

    feature, value = best_split
    left_child = build_decision_tree(best_left)
    right_child = build_decision_tree(best_right)

    return DecisionTreeNode(split_feature=feature, split_value=value, left=left_child, right=right_child)

def classify_point(tree, point):
    if tree.class_label is not None:
        return tree.class_label

    feature_value = point[tree.split_feature]
    if feature_value < tree.split_value:
        return classify_point(tree.left, point)
    else:
        return classify_point(tree.right, point)

# Training data
train_points = [
    (25, 50, 0, 1),
    (35, 30, 0, 0),
    (45, 70, 1, 1),
    (22, 15, 0, 0),
    (50, 80, 1, 1),
    (29, 40, 0, 0)
]

# New client data
new_client = (28, 51, 0)

# Build the decision tree
decision_tree = build_decision_tree(train_points)

# Classify the new client
print(classify_point(decision_tree, new_client))
