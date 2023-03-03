import re

def solve(txt):
    pattern = "((\\s)*((\\+|\\-)?\\d+))(((\\.(\\d+))(([e|E](\\+|\\-)?\\d+)?))|([e|E]((\\+|\\-)?\\d+)))"
    return re.fullmatch(pattern, txt)

def main():
    while True:
        txt = input().strip()
        if txt == "*":
            break
        if solve(txt):
            print("correta")
        else:
            print("incorreta")
main()