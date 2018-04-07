import heapq
class PriorityQueue:
    def __init__(self,priorityFunction):
        self.priorityFunction=priorityFunction
        self.heap=[]

    def push(self,item):
        heapq.heappush(self.heap,(self.priorityFuntion(item),item))

    def pop(self,item):
        (_,item)=heapq.heappop(self.heap)
        return item

    def empty(self):
        return len(self.heap)==0

    def greedySearch(problem,heuristic):
        return graphSearch(problem,PriorityQueue(heuristic))

    def pacmanPathFinder(problem,food):
        manhattanDistanceHeuristic = lambda state: abs(state[0][0]-food[0])+abs(state[0][1]-food[1])
        return greedySearch(problem,manhattanDistanceHeuristic)

def graphSearch(problem,strategy):
    start = problem.getStartState()
    explored = set([start[0]])
    strategy.push(start)
    
    while not strategy.empty():
        node = strategy.pop()
        if problem.isGoalState(node):
            return node[1]
        for move in problem.getSuccessors(node):
            if move[0] not in explored:
                explored.add(move[0])
                strategy.push(move)
    return None