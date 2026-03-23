class Node:
    def __init__(self, x: int):
        self.x = x
        self.next = None

def intersect_two_lists(headA: Node, headB: Node) -> Node | None:
    if not headA or not headB:
        return None
    
    pA = headA
    pB = headB
    while pA != pB:
        pA = pA.next if pA else headB
        pB = pB.next if pB else headA
        
    return pA
