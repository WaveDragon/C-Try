class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def dfs(node: TreeNode):
            if not node.left and not node.right:
                yield node.val
            else:
                if node.left:
                    yield from dfs(node.left)
                if node.right:
                    yield from dfs(node.right)
        
        seq1 = list(dfs(root1)) if root1 else list()
        seq2 = list(dfs(root2)) if root2 else list()
        return seq1 == seq2


tree1 = TreeNode(2,TreeNode(3,TreeNode(6),TreeNode(7,TreeNode(11))),TreeNode(4,TreeNode(8),TreeNode(10,None,TreeNode(12))))
tree2 = TreeNode(2,TreeNode(3,TreeNode(6),TreeNode(7,TreeNode(11))),TreeNode(4,TreeNode(8),TreeNode(10,None,TreeNode(12))))
a = Solution()
a.leafSimilar(tree1,tree2)