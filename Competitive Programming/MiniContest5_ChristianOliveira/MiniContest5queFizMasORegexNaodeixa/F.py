def polygonArea(x, y, n):
    area = 0
    for i in range(0,n):
        area += (x[i] * y[(i+1)%n]) - (y[i] * x[(i+1)%n])  
    return abs(area)

def main():
    n = int(input())
    x = []
    y = []
    
    for i in range(n):
        a, b = input().split()
        x.append(int(a)) 
        y.append(int(b))
    print(polygonArea(x, y, n))

main()