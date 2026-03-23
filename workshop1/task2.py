
class Stack:
    def __init__(self):
        self.a = []

    def is_empty(self) -> bool:
        return len(self.a) == 0

    def push(self, x: int) -> None:
        self.a.append(x)
        
    def pop(self) -> int | None:
        if not self.is_empty():
            return self.a.pop()
        return None
        
    def peek(self) -> int | None:
        if not self.is_empty():
            return self.a[-1]
        return None
        
        
def sort_stack(stack: Stack) -> None:
    if stack.is_empty():
        return
    
    temp = Stack()
    while not stack.is_empty():
        cur = stack.pop()
        
        while not temp.is_empty() and temp.peek() < cur:
            stack.push(temp.pop())
    
        temp.push(cur)
        
    while not temp.is_empty():
        stack.push(temp.pop())

